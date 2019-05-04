package pieceFinder;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JLabel;

import com.github.sarxos.webcam.Webcam;
import com.github.sarxos.webcam.WebcamPanel;
import com.github.sarxos.webcam.WebcamResolution;

import pieceFinder.camTest.CustomComponents0;

public class Table {
	List<Webcam> webcam = new ArrayList<Webcam>();
	Webcam[] cams = new Webcam[3];
	
	public Table() {
		webcam = Webcam.getWebcams();
		cams[0]=webcam.get(0);
		cams[1]=webcam.get(1);
		cams[2]=webcam.get(2);

		cams[0].setViewSize(WebcamResolution.VGA.getSize());
		cams[1].setViewSize(WebcamResolution.VGA.getSize());
		cams[2].setViewSize(WebcamResolution.VGA.getSize());

		cams[0].open();
		cams[1].open();
		cams[2].open();
	}

	public Point getPoint() {
	
	Point p = new Point();
	Triangluation t = new Triangluation();
	int yCoord;

	BufferedImage image = null;
	Color testColor = new Color(35, 84, 65);

	

	int[] n = new int[3];
	double[] position = new double[3];
	camFindPiece[] player = new camFindPiece[3];
	double temp;


		for (int i = 0; i < 3; i++) {
			image = cams[i].getImage();
			position[i] = 0;
			n[i] = 0;

			for (yCoord = 0; yCoord < 300; yCoord++) {
				player[i] = new camFindPiece(image, testColor);
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
		System.out.println("X Coordinate" + p.getX());
		System.out.println("Y Coordinate" + p.getY());
		return p;
	}

}
