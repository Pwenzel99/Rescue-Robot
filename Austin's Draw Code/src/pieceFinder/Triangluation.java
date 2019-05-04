package pieceFinder;

import java.awt.Point;

public class Triangluation {
	
	private final static int HEIGHT = 960;
	private final static int WIDTH  = 1920;
	private final static int PIXELS = 640;
	private final static int CAM_ANGLE = 48;

//	public static void main(String[] args) {
//		Point myPoint = new Point(findAverage(411,411,411));
//		System.out.println(myPoint.getX() + " , " + myPoint.getY());
//	}
	public Triangluation () {
		
	}
		
	public Point findCoords(double cm1, double cm2, int flag) {
		//cm1 = 411;//what pixel does it see the color at?
		//cm2 = 297;//these are both for debugging
		
		double cm1A, cm2A, tempA, tempDist, x, y;
		Point temp;
		
		//find x and y
		
		//find the angles the cams are looking at
		cm1A = CAM_ANGLE * cm1 / PIXELS;
		cm2A = CAM_ANGLE * cm2 / PIXELS;
		cm1A = 90 - cm1A;
		tempA = 180 - cm1A - cm2A;
		
		System.out.println();
		System.out.println("Cam1A: " + cm1A +" , Cam2A: " + cm2A + " , TempA: " + tempA);
		System.out.println();
		
		//tempDist is the how faraway the object is from cam1
		if(flag > 0)
			tempDist = WIDTH * Math.sin(Math.toRadians(cm2A)) / Math.sin(Math.toRadians(tempA));
		else
			tempDist = HEIGHT * Math.sin(Math.toRadians(cm2A)) / Math.sin(Math.toRadians(tempA));
		//imagine drawling a small triangle where we know all angles and 1 side length
		tempA = 90 - cm1A;
		
		//for debugging
		System.out.println("Dist from cam to bottle: " + tempDist + " , Angle from bottle to wall:" + tempA);
		System.out.println();
		
		//finds base and height of small triangle (x,y)
		if(flag>0) {
			y = Math.round(tempDist * Math.sin(Math.toRadians(cm1A)));
			x = Math.round(Math.sqrt(Math.pow(tempDist,2) - Math.pow(y, 2)));
			
			y = HEIGHT - y;
		} else {
			x = Math.round(tempDist * Math.sin(Math.toRadians(cm1A)));
			y = Math.round(Math.sqrt(Math.pow(tempDist,2) - Math.pow(x, 2)));
		}
		
		
		
		System.out.println(x + " , " +y);
		
		temp = new Point((int)x,(int)y);
		
		
		return temp;
	}
	
	public Point findAverage(double[] a) {              //double a, double b, double c) {
		//a,b,c are pixel values found by cameras, must be less than PIXELS
		
		System.out.println(a[0] + "," + a[1] + "," + a[2]);
		
		Point p1 = new Point(findCoords(a[0],a[1],0));
		Point p2 = new Point(findCoords(a[1],a[2],1));
		
		Point pAVG = new Point();
		int n = 0;
		
		if(!(p1.getX() == 0 || p1.getY() == 0))
			n++;
		if(!(p1.getX() == 0 || p1.getY() == 0))
			n++;
		if(n == 0) {
			System.out.println("Point could not be found");
			return new Point(-1,-1);
		}
			
		//averages out the points given and sets them into a new point
		pAVG.setLocation(
				(p1.getX() + p2.getX()) / n,
				(p1.getY() + p2.getY()) / n
				);
		
		return pAVG;
	}

}
