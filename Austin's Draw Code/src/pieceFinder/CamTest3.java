package pieceFinder;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JLabel;

import com.github.sarxos.webcam.Webcam;
import com.github.sarxos.webcam.WebcamPanel;
import com.github.sarxos.webcam.WebcamResolution;

import pieceFinder.camTest.CustomComponents0;

public class CamTest3 {
	public static void main(String[] argv) {
	
		List<Webcam> webcam = Webcam.getWebcams();
		Point p = new Point();
		Triangluation t = new Triangluation();
		int yCoord;
		double temp0, temp1, temp2;
		double camPos[]=new double[3];
		CustomComponents0 component = new CustomComponents0();
		CustomComponents0 component1 = new CustomComponents0();
		CustomComponents0 component2 = new CustomComponents0();
		
		BufferedImage image0= null;
		BufferedImage image1= null;
		BufferedImage image2= null;
		Color testColor=new Color(48, 85, 64);
		
		Webcam[] cams = new Webcam[3];
		cams[0] = webcam.get(0);
		cams[1] = webcam.get(1);
		cams[2] = webcam.get(2);
		
		cams[0].setViewSize(WebcamResolution.VGA.getSize());
		cams[1].setViewSize(WebcamResolution.VGA.getSize());
		cams[2].setViewSize(WebcamResolution.VGA.getSize());
		
		cams[0].open();
		cams[1].open();
		cams[2].open();
		
		WebcamPanel panel0 = new WebcamPanel(cams[0]);
		panel0.setFPSDisplayed(true);
		panel0.setDisplayDebugInfo(true);
		panel0.setImageSizeDisplayed(true);
		panel0.setMirrored(false);
		JFrame window = new JFrame("Test webcam panel 0");
		window.setPreferredSize(new Dimension(700,600));
		window.setResizable(true);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.pack();
		window.setVisible(true);
		window.add(panel0);
		
		WebcamPanel panel1 = new WebcamPanel(cams[1]);
		panel1.setFPSDisplayed(true);
		panel1.setDisplayDebugInfo(true);
		panel1.setImageSizeDisplayed(true);
		panel1.setMirrored(false);
		JFrame window1 = new JFrame("Test webcam panel 1");
		window1.setPreferredSize(new Dimension(700,600));
		window1.setResizable(true);
		window1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window1.pack();
		window1.setVisible(true);
		window1.add(panel1);
		
		WebcamPanel panel2 = new WebcamPanel(cams[2]);
		panel2.setFPSDisplayed(true);
		panel2.setDisplayDebugInfo(true);
		panel2.setImageSizeDisplayed(true);
		panel2.setMirrored(false);
		JFrame window2 = new JFrame("Test webcam panel 2");
		window2.setPreferredSize(new Dimension(700,600));
		window2.setResizable(true);
		window2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window2.pack();
		window2.setVisible(true);
		window2.add(panel2);
		
		int[] n = new int[3];
		double[] position = new double[3];
		camFindPiece[] player = new camFindPiece[3];
		double temp;
		
		while(true) {

			for(int i=0;i<3;i++) {
				image0 = cams[i].getImage();
				position[i] = 0;
				n[i] = 0;
				
			for(yCoord=100;yCoord<300;yCoord++) {
				player[i] = new camFindPiece(image0, testColor);
				temp = player[i].findCenter(yCoord);
				
				if (!Double.isNaN(temp)) {
					n[i]++;
					position[i] += temp;
					System.out.println("temp: " + temp);
					System.out.println("Cam " + i + ": " + position[i]);
					}	
				}
				position[i] /= n[i];
				System.out.println("n value = " + n[i]);
				System.out.println("final Cam " + i + ": " + position[i]);
			}
			p.setLocation(t.findAverage(position));
			System.out.println("X Coordinate"+p.getX());
			System.out.println("Y Coordinate"+p.getY());
			
			component.Center(position[0]);
			panel0.add(component);
			panel0.repaint();
			window.repaint();
			
			component1.Center(position[1]);
			panel1.add(component1);
			panel1.repaint();
			window1.repaint();
			
			component2.Center(position[2]);
			panel2.add(component2);
			panel2.repaint();
			window2.repaint();
						
		}
		
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
            g.drawOval(center-50,300,100,100);			//x,y,width,height
        }
	}
}
