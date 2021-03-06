package pieceFinder;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;

import com.github.sarxos.webcam.Webcam;
import com.github.sarxos.webcam.WebcamPanel;
import com.github.sarxos.webcam.WebcamResolution;


public class camTest {

	public static void main(String[] args) {
		int yCoord =100;
		double xCoord =0;
		BufferedImage image = null;
		BufferedImage camImage = null;
		
		Webcam webcam = Webcam.getDefault();
		webcam.setViewSize(new Dimension(640, 480));
		webcam.open();
		camImage=webcam.getImage();
		
		Color testColor = new Color(48, 85, 64);  //addPiece(webcam);
		camFindPiece player1 = new camFindPiece(camImage, testColor);
		try {
			ImageIO.write(camImage, "PNG", new File("C:\\pictest\\test.png"));
		} catch (IOException e1) {
			System.out.println(e1);
		}	
		/*try {
			File t = new File("C:\\pictest\\test.png");
			image = ImageIO.read(t);
			System.out.println("Reading Complete.");
		}catch(IOException e){
			System.out.println("Error: "+e);
		}*/
			
		
		
		
		
		CustomComponents0 component = new CustomComponents0();
		webcam.close();
		webcam.setViewSize(WebcamResolution.VGA.getSize());
		
		WebcamPanel panel = new WebcamPanel(webcam);
		panel.setFPSDisplayed(true);
		panel.setDisplayDebugInfo(true);
		panel.setImageSizeDisplayed(true);
		panel.setMirrored(false);
		JFrame window = new JFrame("Test webcam panel");
		window.setResizable(true);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.pack();
		window.setVisible(true);
		window.add(panel);
		do {
			camImage=webcam.getImage();
			player1 = new camFindPiece(camImage, testColor);
			System.out.println(player1.findCenter(yCoord));
			component.Center(player1.findCenter(100));
			panel.add(component);
			panel.repaint();
			
			
		}while(true);
	
	}
	static class CustomComponents0 extends JLabel {

		private static final long serialVersionUID = 0;
        public static int center = 0;
       
        public double Center (double mid) {
        	center = (int)mid;
        	return center;
        }
//        @Override
//        public Dimension getMinimumSize() {
//        	return new Dimension (1080,720);
//        }
        
        
        @Override
        public Dimension getPreferredSize() {
            return new Dimension(640,480);			//Sets the max size on screen that the circle can print in
        }

        @Override
        public void paintComponent(Graphics g) {
            int margin = 10;
            Dimension dim = getSize();
            super.paintComponent(g);				//erases panel effects
            g.setColor(Color.red);
            g.drawOval(center-50,100,100,100);			//x,y,width,height
        }
    }

	
}
