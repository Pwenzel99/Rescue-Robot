package android.example.robotsgonnarescue;

import android.annotation.SuppressLint;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Looper;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.github.mikephil.charting.charts.RadarChart;
import com.github.mikephil.charting.charts.ScatterChart;
import com.github.mikephil.charting.components.Legend;
import com.github.mikephil.charting.components.XAxis;
import com.github.mikephil.charting.components.YAxis;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.RadarData;
import com.github.mikephil.charting.data.RadarDataSet;
import com.github.mikephil.charting.data.RadarEntry;
import com.github.mikephil.charting.data.ScatterData;
import com.github.mikephil.charting.data.ScatterDataSet;
import com.github.mikephil.charting.formatter.IndexAxisValueFormatter;
import com.github.mikephil.charting.interfaces.datasets.IScatterDataSet;
import com.github.mikephil.charting.utils.ColorTemplate;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * The main activity that runs the app by sending commands to the bots and creating the graphs.
 *
 * @Author Ben Pierre, Andrew Holman, Patrick Wenzel
 */
public class MainActivity extends AppCompatActivity implements OnTouchListener {
    final String ADDRESS = "192.168.1.1";
    final int PORT = 288;

    /**
     * Buttons for moving forward, backwards, left, right, playing a song, scanning, making the music and kill switch button appear, playing music, ending program
     */
    protected ImageButton forwardButton, backButton, leftButton, rightButton, songButton, scanButton, toggleButton, musicToggle, killSwitch;
    /**
     * Shows the received text from the bot
     */
    protected TextView receivedText;
    /**
     * How many centimeters to move forward and how many degrees to turn
     */
    protected EditText MTargetGoal, RTargetGoal;
    /**
     * Connection to the cybot
     */
    protected Connection connection;
    /**
     * Radar chart from the scans
     */
    protected RadarChart radarChart;
    /**
     * Scatter chart to show where the cybot has been
     */
    protected ScatterChart scatterChart;
    /**
     * Builds a string
     */
    protected StringBuilder stringBuilder;
    /**
     * List of objects
     */
    protected ListView list;
    /**
     * Keeps track of the data from the ir sensor
     */
    protected ArrayList<RadarEntry> irDataVals;
    /**
     * Keeps track of the data from the ping sensor
     */
    protected ArrayList<RadarEntry> pingDataVals;
    /**
     * Keeps track of walls run into
     */
    protected ArrayList<Entry> walls;
    /**
     * Keeps track of objects ran into
     */
    protected ArrayList<Entry> objects;
    /**
     * Keeps track of holes ran into
     */
    protected ArrayList<Entry> holes;
    /**
     * Keeps track of scanned objects
     */
    protected ArrayList<ScannedObject> scannedObjects;
    /**
     * String array of labels
     */
    protected String[] labels = new String[181];
    /**
     * Custom adapter
     */
    protected CustomAdapter customAdapter;
    /**
     * Checks visibility of buttons
     */
    protected Boolean visibility;
    /**
     * Checks if an object was recognized
     */
    protected boolean recObj;
    /**
     * Checks if an object was scanned
     */
    protected boolean scanObj;
    /**
     * Checks if the toggle button was pressed
     */
    protected boolean mToggled;
    /**
     * Checks if in Object
     */
    protected boolean inObj;

    /**
     * Initializes the variables, builds the scatter plot and starts communication with the CyBot.
     *
     * @param savedInstanceState the saved bundle that is used to build the view.
     */
    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setValues();
        buildLists();
        initializeLabels(labels);
        findViews();
        setListeners();
        listInit();
        chartInit();

        connection = new Connection(ADDRESS, PORT);
        connection.boot();


    }

    /**
     * Initiates all values need for the list view @list
     */
    private void listInit() {
        ScannedObject demoObj = new ScannedObject(0, 0, 11);
        demoObj.setEnd(37, 8);
        demoObj.setClosest(5.2);
        demoObj.build();
        scannedObjects.add(demoObj);
        list.setAdapter(customAdapter);
    }

    /**
     * Initiates everything needed for the radar graph
     */
    private void chartInit() {
        scatterChart = findViewById(R.id.scatterGraph);
        scatterChart.getDescription().setEnabled(false);

        scatterChart.setDrawGridBackground(false);
        scatterChart.setTouchEnabled(true);
        scatterChart.setMaxHighlightDistance(50f);

        scatterChart.setDragEnabled(true);
        scatterChart.setScaleEnabled(true);

        scatterChart.setMaxVisibleValueCount(200);
        scatterChart.setPinchZoom(true);

        Legend l = scatterChart.getLegend();
        l.setVerticalAlignment(Legend.LegendVerticalAlignment.TOP);
        l.setHorizontalAlignment(Legend.LegendHorizontalAlignment.RIGHT);
        l.setOrientation(Legend.LegendOrientation.VERTICAL);
        l.setDrawInside(false);
        l.setXOffset(5f);

        YAxis yl = scatterChart.getAxisLeft();
//        yl.setAxisMinimum(0f);
//        yl.setAxisMaximum(700f);
        scatterChart.getAxisRight().setEnabled(false);

        XAxis xl = scatterChart.getXAxis();
//        xl.setAxisMinimum(0f);
//        xl.setAxisMaximum(700f);
        xl.setDrawGridLines(false);
    }

    /**
     * Sets all field variables to the correct values
     */
    private void setValues() {
        scannedObjects = new ArrayList<>();
        visibility = true;
        irDataVals = new ArrayList<>();
        pingDataVals = new ArrayList<>();
        walls = new ArrayList<>();
        objects = new ArrayList<>();
        holes = new ArrayList<>();
        stringBuilder = new StringBuilder();
        recObj = false;
        scanObj = false;
        mToggled = true;
        inObj = false;
        customAdapter = new CustomAdapter();
    }

    /**
     * Finds all views and sets correct pointers
     */
    private void findViews() {
        toggleButton = findViewById(R.id.ToggleButton);
        forwardButton = findViewById(R.id.fButton);
        backButton = findViewById(R.id.bButton);
        leftButton = findViewById(R.id.lButton);
        rightButton = findViewById(R.id.rButton);
        songButton = findViewById(R.id.mButton);
        scanButton = findViewById(R.id.sButton);
        MTargetGoal = findViewById(R.id.MTargetGoal);
        RTargetGoal = findViewById(R.id.RTargetGoal);
        musicToggle = findViewById(R.id.ToggleMusicButton);
        killSwitch = findViewById(R.id.KillSwitch);
        list = findViewById(R.id.list);
        radarChart = findViewById(R.id.radarChart);
        radarChart.setVisibility(View.INVISIBLE);
        receivedText = findViewById(R.id.RecievedText);
        songButton.setVisibility(View.INVISIBLE);
    }

    /**
     * Sets the on click listener of all buttons to this,
     * Note my custom ActivityMain implements View.OnTouchListener, see @onTouch
     */
    @SuppressLint("ClickableViewAccessibility")
    private void setListeners() {
        forwardButton.setOnTouchListener(this);
        backButton.setOnTouchListener(this);
        leftButton.setOnTouchListener(this);
        rightButton.setOnTouchListener(this);
        songButton.setOnTouchListener(this);
        scanButton.setOnTouchListener(this);
        musicToggle.setOnTouchListener(this);
        killSwitch.setOnTouchListener(this);
        toggleButton.setOnTouchListener(this);
    }

    /**
     * Sends the command to the CyBot to start playing music.
     */
    @SuppressLint("SetTextI18n")
    private void toggleMusic() {
        if (mToggled) {
            songButton.setVisibility(View.VISIBLE);
            killSwitch.setVisibility(View.VISIBLE);
            mToggled = false;
            receivedText.setText("Made Buttons Visible");
        } else {
            songButton.setVisibility(View.INVISIBLE);
            killSwitch.setVisibility(View.INVISIBLE);
            mToggled = true;
            receivedText.setText("Made Buttons Invisible");
        }
    }

    /**
     * Method designed to handle an input
     *
     * @param input is the received character from the Cybot used to decide what happened to the Cybot.
     */
    public void handleInput(char input) {
        if (input == 'o') { // start listening for an object
            stringBuilder.delete(0, stringBuilder.length());
            recObj = true;
        } else if (input == 'p') { // start listening for a list of stuff
            stringBuilder.delete(0, stringBuilder.length());
            buildLists(); // clear lists
            scanObj = true;
        } else if (recObj) {
            if (input == ',') {
                parseObject(stringBuilder.toString());
                stringBuilder.delete(0, stringBuilder.length());
                recObj = false;
            } else stringBuilder.append(input);
        } else if (scanObj) {
            if (input == ',') {
                parseScan(stringBuilder.toString());
                stringBuilder.delete(0, stringBuilder.length());
                if (irDataVals.size() > 180) {
                    scanObj = false;
                    buildObjects();
                    startGraph();
                    Log.v("MainActivity", "ScanCompleted");
                }
            } else stringBuilder.append(input);

        }
    }

    /**
     * Parses the scan information that was send from the Cybot and updates the relevant data fields.
     *
     * @param toString is the raw string input from Cybot.
     */
    private void parseScan(String toString) {
        Scanner sc = new Scanner(toString);
        sc.useDelimiter(" ");
        String tempa = sc.next();
        String tempb = sc.next();
        float irData = Float.parseFloat(tempa) > 1 ? Float.parseFloat(tempa) : irDataVals.get(0).getValue();
        float pingData = Float.parseFloat(tempb) > 1 ? Float.parseFloat(tempb) : pingDataVals.get(0).getValue();
        irDataVals.add(0, new RadarEntry(irData > 50 ? 50 : irData));
        pingDataVals.add(0, new RadarEntry(pingData > 50 ? 50 : pingData));
        Log.v("Graph", "Radar = " + tempa + "," + tempb + "at: " + irDataVals.size());

        sc.close();
    }

    /**
     * Parses the object information that was send from the Cybot and updates the relevant data fields.
     *
     * @param toString is the raw string input from Cybot.
     */
    @SuppressLint("SetTextI18n")
    private void parseObject(String toString) {
        //try{
        final String toString2 = toString;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                receivedText.setText(toString2);
                receivedText.setText("OBJ:" + toString2);
            }
        });
        Scanner sc = new Scanner(toString);
        sc.useDelimiter(" ");
        char type = sc.next().charAt(0);
        int x = (Integer.parseInt(sc.next())) / 100;
        int y = (Integer.parseInt(sc.next())) / 100;
        sc.close();
        scatterAddValues(x, y, type);
        System.out.println("Added " + type + " at : " + x + "," + y);
    }
//        catch (Exception e){
//            Log.v("ParseObject",e.getLocalizedMessage());
//        }


    /**
     * Method that takes an array of values distance values and builds an array of object values,
     * appends them to the view model and displays them
     */
    private void buildObjects() {
        scannedObjects.clear();
        ScannedObject scannedObject = new ScannedObject(-1,0,0);
        for (int i = 0; i < 90; i++) {
            Log.v("ListData", "Handling point with a distance of " + pingDataVals.get(i).getValue() + " at " + i);
            if (!inObj) {
                //Enter Object
                if (irDataVals.get(i).getValue() < 50 && pingDataVals.get(i).getValue()<50) {
                    Log.v("ListOBJ", "Adding new object at angle:" + i * 2);
                    inObj = true;
                    scannedObject = new ScannedObject(scannedObjects.size() + 1, i * 2, pingDataVals.get(i).getValue());
                    scannedObject.setClosest(irDataVals.get(i).getValue());

                }
            } else {
                //Leave Object
                if (irDataVals.get(i).getValue() >= 50) {
                    Log.v("ListOBJ", "BuiltObject");
                    inObj = false;
                    if(scannedObject!=null) {
                        scannedObject.setEnd(i * 2, pingDataVals.get(i).getValue());
                        scannedObject.build();
                        if (scannedObject.getLinearWidth() > 2.0) scannedObjects.add(scannedObject);
                    }
                } else {
                    Log.v("ListOBJ", "Adding point to obj with " + pingDataVals.get(i).getValue() + " at " + i);
                    assert scannedObject != null;
                    scannedObject.setClosest(pingDataVals.get(i).getValue());
                }
            }
        }
        if (inObj) {
            scannedObject.setEnd(90, pingDataVals.get(90).getValue());
            scannedObject.build();
            scannedObjects.add(scannedObject);
        }
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                customAdapter.notifyDataSetChanged();
            }
        });
        System.out.println("Size:" + customAdapter.getCount());
    }


    /**
     * The handler for all the buttons that are on the main activity.
     *
     * @param v     is the view of the button that was clicked
     * @param event is the click event that occured
     * @return returns true if the click was false and successful if an error occured.
     */
    @SuppressLint({"ClickableViewAccessibility", "SetTextI18n"})
    @Override
    public boolean onTouch(View v, MotionEvent event) {
        //If we need to restart
        if (recObj || scanObj) {
            Toast.makeText(this, "Please wait for the finished command", Toast.LENGTH_SHORT).show();
            return false;
        }

        if (!connection.isConnected()) {
            Log.v("Buttons", "Button clicked without connection");
            return true;
        }

        if (event.getAction() == MotionEvent.ACTION_UP) {
            String MGoal = MTargetGoal.getText().toString();
            String RGoal = RTargetGoal.getText().toString();
            switch (v.getId()) {
                case R.id.ToggleButton:

                    toggleViews();

                    break;
                case R.id.KillSwitch:

                    connection.sendString(".z,");
                    receivedText.setText("Pressed Kill Switch");

                    break;
                case R.id.ToggleMusicButton:

                    toggleMusic();

                    break;
                case R.id.fButton:
                    connection.sendString(".f" + MGoal + ',');
                    receivedText.setText("Moved " + MGoal + " Centimeters Forward");

                    break;
                case R.id.bButton:

                    connection.sendString(".b" + MGoal + ',');
                    receivedText.setText("Moved " + MGoal + " Centimeters Backwards");

                    break;
                case R.id.lButton:
                    connection.sendString(".l" + RGoal + ',');
                    receivedText.setText("Turned " + RGoal + " Degrees to the Left");

                    break;
                case R.id.rButton:

                    connection.sendString(".r" + RGoal + ',');
                    receivedText.setText("Turned " + RGoal + " Degrees to the Right");

                    break;
                case R.id.sButton:

                    connection.sendString(".s,");
                    receivedText.setText("Scanned");

                    break;
                case R.id.mButton:

                    connection.sendString(".m,");
                    receivedText.setText("Played Music");

                    break;

            }
        }
        return true;
    }

    /**
     * Handles a connection
     *
     * @Author Ben Pierre
     */
    public class Connection {
        volatile Socket socket = null;
        final String address;
        final int port;
        OutputStream outputStream;
        OutputStreamWriter writer;
        InputStream inputStream;

        /**
         * Assigns values to address and port
         */
        Connection(final String address, int port) {
            this.address = address;
            this.port = port;
        }

        /**
         * Creates a socket, assigns all streams
         * Creates a listening thread for input
         */
        void boot() {
            Log.v("Connection", "Connecting");
            //This is for my gui pls ignore
            final ImageView good, bad;
            good = findViewById(R.id.ConnectedInd);
            bad = findViewById(R.id.ErrConnect);
            good.setVisibility(View.GONE);
            bad.setVisibility(View.GONE);
            findViewById(R.id.connectedMeasure).setVisibility(View.VISIBLE);

            Thread connection = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        //Connect socket and wait until its really connected
                        socket = new Socket(address, port);

                        while (true) {
                            if (socket != null) break;
                        }

                        //Grab streams after socket made
                        outputStream = socket.getOutputStream();
                        writer = new OutputStreamWriter(outputStream, StandardCharsets.US_ASCII);
                        inputStream = socket.getInputStream();
                        while (true) {
                            if (inputStream != null) break;

                        }
                        Log.v("Connection", "Streams set up");

                        //More gui stuff
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                findViewById(R.id.connectedMeasure).setVisibility(View.INVISIBLE);
                                good.setVisibility(View.VISIBLE);
                                Log.v("Connection", "Connected, set gui");
                            }
                        });

                    } catch (IOException e) {
                        //Handles an exception and does more gui stuff
                        final String emessage = e.getLocalizedMessage();
                        Looper.prepare();
                        Log.v("Connection", emessage);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                receivedText.setText(emessage);
                                findViewById(R.id.connectedMeasure).setVisibility(View.INVISIBLE);
                                bad.setVisibility(View.VISIBLE);
                            }
                        });
                    }
                }
            });

            //This is the listener for input, it handles input from the brobot by passing them to
            //@handleInput()
            Thread listener = new Thread(new Runnable() {
                @Override
                public void run() {
                    while (true) {
                        try {
                            while (true) {
                                if (socket != null) break;

                            }
                            while (true) {
                                if (inputStream != null) break;

                            }
                            handleInput((char) inputStream.read());
                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                    }
                }
            });
            //Starts the two threads
            Log.v("Debug", "Statting thread");

            connection.start();
            Log.v("Debug", "Out her again");

            listener.start();
            Log.v("Connection", "Starting input thread");

        }


        /**
         * Sends a string to the Cybot to make it execute various commands.
         * . = command
         * , = end command
         * .f = forward
         * .b = backwards
         * .l = turn left
         * .r = turn right
         * .s = scan
         * .m = play song
         * @Author some guy on piazza who gave me the bit by bit idea, Ben Pierre
         * @param stringin string to send, see header for command code
         */
        void sendString(String stringin) {
            Log.v("Connection", "Sending " + stringin);
            final String string = stringin;
            Thread thr = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        byte[] bytes = string.getBytes(StandardCharsets.US_ASCII);
                        DataOutputStream dos = new DataOutputStream(connection.socket.getOutputStream());
                        dos.write(13);
                        dos.flush();
                        for (byte aByte : bytes) {
                            dos.write(aByte);
                            dos.flush();
                            Thread.sleep(100);
                        }
                    } catch (Exception e) {
                        Log.v("Connection", e.getLocalizedMessage());
                    }
                }
            });
            thr.start();
        }

        /**
         * Checks if the connection is valid
         *
         * @return True if the socket is connected
         */
        boolean isConnected() {
            return socket != null && socket.isConnected();
        }

    }

    /**
     * Intializes the radar graph whenever the scanner data is sent
     */
    public void startGraph() {
        Collections.rotate(irDataVals, -45);
        Collections.rotate(pingDataVals, -45);

        final RadarDataSet dataSet1 = new RadarDataSet(irDataVals, "IR Sensor");
        final RadarDataSet dataSet2 = new RadarDataSet(pingDataVals, "Ping Sensor");

        dataSet1.setColor(Color.BLUE);
        dataSet2.setColor(Color.RED);
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                radarChart.setBackgroundColor(Color.WHITE);
                radarChart.getDescription().setEnabled(false);
                radarChart.setWebLineWidth(0.1f);

                radarChart.setWebColor(Color.GRAY);
                radarChart.setWebLineWidth(0.1f);
                radarChart.setWebColorInner(Color.GRAY);
                radarChart.setWebAlpha(100);

                RadarData data = new RadarData();
                data.addDataSet(dataSet1);
                data.addDataSet(dataSet2);

                XAxis xAxis = radarChart.getXAxis();
                xAxis.setValueFormatter(new IndexAxisValueFormatter(labels));
                xAxis.setTextSize(0.1f);
                xAxis.setXOffset(0);
                xAxis.setYOffset(0);
                xAxis.setTextColor(Color.WHITE);

                YAxis yAxis = radarChart.getYAxis();
                yAxis.setValueFormatter(new IndexAxisValueFormatter(labels));
                yAxis.setTextSize(0.1f);
                yAxis.setXOffset(0);
                yAxis.setYOffset(0);
                yAxis.setTextColor(Color.WHITE);
                radarChart.getLegend().setEnabled(false);
                radarChart.setSkipWebLineCount(0);
                radarChart.setData(data);
                radarChart.invalidate();
            }
        });
    }

    /**
     * Initializes all the labels
     * @param labels Given labels to initialize
     */
    private void initializeLabels(String[] labels) {
        for (int i = 0; i < 181; i++) {
            labels[i] = Integer.toString(i);
        }
    }

    /**
     * Builds all the lists
     */
    private void buildLists() {
        irDataVals = new ArrayList<>();
        pingDataVals = new ArrayList<>();
        while (irDataVals.size() < 90) {
            irDataVals.add(new RadarEntry(0));
            pingDataVals.add(new RadarEntry(0));
        }
    }


    /**
     * Adds the given x and y coordinates to the array list and then redraws the array list.
     *
     * @param xval is the given x coordinate.
     * @param yval is the given y coordinate.
     * @param type is the given type which is used to color the dots.
     */
    private void scatterAddValues(int xval, int yval, char type) {
        if(type == 'b'){
            objects.add(new Entry(xval,yval));
        }
                walls.add(new Entry(xval, yval));
        Log.v("Reached", " True");
        try {
            ScatterDataSet set1 = new ScatterDataSet(walls, "DS 1");
            set1.setScatterShape(ScatterChart.ScatterShape.SQUARE);
            set1.setColor(ColorTemplate.COLORFUL_COLORS[0]);
            ScatterDataSet set2 = new ScatterDataSet(objects, "DS 2");
            set2.setScatterShape(ScatterChart.ScatterShape.CIRCLE);
            set2.setScatterShapeHoleColor(ColorTemplate.COLORFUL_COLORS[3]);
            set2.setScatterShapeHoleRadius(3f);
            set2.setColor(ColorTemplate.COLORFUL_COLORS[1]);
            ScatterDataSet set3 = new ScatterDataSet(holes, "DS 3");
            set3.setShapeRenderer(new android.example.robotsgonnarescue.CustomScatterShapeRenderer());
            set3.setColor(ColorTemplate.COLORFUL_COLORS[2]);

            set1.setScatterShapeSize(15f);
            set2.setScatterShapeSize(15f);
            set3.setScatterShapeSize(15f);

            ArrayList<IScatterDataSet> dataSets = new ArrayList<>();
            dataSets.add(set1); // add the data sets
            dataSets.add(set2);
            dataSets.add(set3);

            // create a data object with the data sets
            final ScatterData data = new ScatterData(dataSets);
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    scatterChart.setData(data);
                    scatterChart.invalidate();
                }
            });
        }catch (Exception e){
            Log.v("Scatter", e.getLocalizedMessage());
        }
    }

    /**
     * Switches which graph is on display,
     */
    @SuppressLint("SetTextI18n")
    public void toggleViews() {
        if (visibility) {
            visibility = false;
            radarChart.setVisibility(View.VISIBLE);
            scatterChart.setVisibility(View.GONE);
            receivedText.setText("Switched to Radar Chart");
        } else {
            visibility = true;
            radarChart.setVisibility(View.GONE);
            scatterChart.setVisibility(View.VISIBLE);
            receivedText.setText("Switched to Scatter Chart");
        }
    }

    /**
     * @Author Ben Pierre
     * A custom adaptor to load my values into the adaptor views
     */
    class CustomAdapter extends BaseAdapter {

        /**
         * Gets the number of items in the ListView Backend
         *
         * @return Item Count in backend
         */
        @Override
        public int getCount() {
            return scannedObjects.size();
        }

        /**
         * Gets item at a given position in the form of a ScannedObject
         *
         * @param position Item number to fetch
         * @return ScannedObject at this position
         */
        @Override
        public Object getItem(int position) {
            return scannedObjects.get(position);
        }

        /**
         * Fetches the id of the item at this location
         *
         * @param position Item number to fetch
         * @return ID of the item at this location
         */
        @Override
        public long getItemId(int position) {
            return scannedObjects.get(position).getID();
        }

        /**
         * Builds a new custom view for this list card
         *
         * @param position    position to build and reference
         * @param convertView View to convert to a custom card
         * @param parent      container View
         * @return A mutated view to reflect the item at @position
         */
        @SuppressLint({"SetTextI18n", "ViewHolder", "InflateParams"})
        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            convertView = getLayoutInflater().inflate(R.layout.scanned_object, null);
            TextView no = convertView.findViewById(R.id.cardLoc);
            TextView start = convertView.findViewById(R.id.cardStart);
            TextView end = convertView.findViewById(R.id.cardEnd);
            TextView width = convertView.findViewById(R.id.cardWidth);
            TextView distance = convertView.findViewById(R.id.cardDistance);

            distance.setText("Distance: " + scannedObjects.get(position).getDistance() + "cm");
            no.setText("#: " + scannedObjects.get(position).getID());
            start.setText("Start: " + scannedObjects.get(position).getEndAngle());
            end.setText("End: " + scannedObjects.get(position).getStartAngle());
            width.setText("Width: " + scannedObjects.get(position).getLinearWidth() + "cm");
            return convertView;
        }
    }
}
