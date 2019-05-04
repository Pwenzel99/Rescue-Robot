package pieceFinder;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;

import com.github.sarxos.webcam.Webcam;
import com.github.sarxos.webcam.WebcamPanel;
import com.github.sarxos.webcam.WebcamResolution;


public class camTest2 {

	public static void main(String[] args) {
		Triangluation t = new Triangluation();
		List<Webcam> webcam =Webcam.getWebcams();
		Point p = new Point();
		// List all webcams connected 
		//System.out.println( webcam );
		// Default camera,    webcam.get(0)
		// Second camera,    webcam.get(1)
		int yCoord;
		int n = 0;
		double temp;
		
		double camPos[]=new double[3];
		
		for(int i=0;i<3;i++) {
			n=0;
			camPos[i] = 0.0;
			BufferedImage image= null;
			Color testColor=new Color(48, 85, 64);
			Webcam cam=webcam.get(i);
			webcam.get(i).setViewSize(WebcamResolution.VGA.getSize());
			webcam.get(i).open();
			image=cam.getImage();
			for(yCoord=0;yCoord<480;yCoord++) {
				camFindPiece player1 = new camFindPiece(image, testColor);
				//System.out.println(player1.findCenter(yCoord));
				temp = player1.findCenter(yCoord);
				//if value found is not nan, then add it to the overall
				if (!Double.isNaN(temp)) {
					n++;
					camPos[i] += temp;
				}
			}
			//finds the average of all the values found
			camPos[i] /= n;
			System.out.println(camPos[i]);
			webcam.get(i).close();
		}
		p.setLocation(t.findAverage(camPos));
		System.out.println(p.getX());
		System.out.println(p.getY());
		//this is for debugging \|/
//		WebcamPanel panel = new WebcamPanel(cam);
//		panel.setFPSDisplayed(true);
//		panel.setDisplayDebugInfo(true);
//		panel.setImageSizeDisplayed(true);
//		panel.setMirrored(false);
//		JFrame window = new JFrame("Test webcam panel 1");
//		window.setResizable(true);
//		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		window.pack();
//		window.setVisible(true);
//		window.add(panel);
		
		
    }

	
}
