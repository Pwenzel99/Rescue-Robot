package android.example.robotsgonnarescue;

import java.text.DecimalFormat;

/**
 * @author Ben Pierre
 */
public class ScannedObject {
    /**
     * Start position, end position, number of object
     */
    private int sPos, ePos,id;
    /**
     * Width of the object, distance away, start distance, end distance
     */
    private double lWidth,distance,distanceS,distanceE;
    /**
     * Decimal format so numbers are formatted 0.0
     */
    private DecimalFormat format = new DecimalFormat("#.#");

    /**
     * Creates a scanned object
     * @param id the number of this object
     * @param sAngle starting angle
     * @param distanceS starting distance
     */
    public ScannedObject(int id, int sAngle,double distanceS){
        this.id = id;
        this.sPos = sAngle;
        this.distanceS = distanceS;
        distance = Double.MAX_VALUE;
    }

    /**
     * sets end point of this object
     * @param eAngle ending angle
     * @param eDistance distance at ending angle
     */
    public void setEnd(int eAngle, double eDistance){
        ePos = eAngle;
        distanceE = eDistance;
    }

    /**
     * Sets closest point, note this handles making sure its smallest
     * @param distance new smallest distance
     */
    public void setClosest(double distance){

        if(distance<this.distance)this.distance=distance;
    }

    /**
     * Calculates linear width
     */
    public void build(){
        lWidth = Math.sqrt(distanceS * distanceS + distanceE*distanceE - 2
                * distanceE*distanceS*Math.cos(((ePos-sPos)*Math.PI)/180));

    }

    /**
     * Returns starting angle
     * @return The Starting angle
     */
    public int getStartAngle(){
        return 180-sPos;
    }

    /**
     * Returns the ending andle
     * @return The angle at the end of the object
     */
    public int getEndAngle(){
        return 180-ePos;
    }

    /**
     * Gets the linear width, in cm, of this object
     * @return Linear width, in cm, of this object
     */
    public double getLinearWidth(){
        return Double.parseDouble(format.format(lWidth));
    }

    /**
     * Gets the closets distance of this object to the robot
     * @return The Distance, in cm, to this object
     */
    public double getDistance(){
        return Double.parseDouble(format.format(distance));
    }

    /**
     * Gets the objects id
     * @return The objects ID
     */
    public int getID(){
        return id;
    }



}
