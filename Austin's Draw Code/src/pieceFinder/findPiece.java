package pieceFinder;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class findPiece {
	private static BufferedImage image;
	private static Color idealColor;
	private static int  width;
	
	public findPiece(BufferedImage givenImage, Color givenColor) {
		image=givenImage;
		idealColor=givenColor;
		width = image.getWidth();
	}
	
	
	
	
	public static double similarToo(Color color,Color idealColor) {
		double top= (color.getRed()*idealColor.getRed())+(color.getGreen()*idealColor.getGreen())+(color.getBlue()*idealColor.getBlue());
		
		
		
		double bottom= Math.sqrt(Math.pow(idealColor.getRed(),2)+Math.pow(idealColor.getGreen(),2)+Math.pow(idealColor.getBlue(),2))*
				Math.sqrt(Math.pow(color.getRed(),2)+Math.pow(color.getGreen(),2)+Math.pow(color.getBlue(),2));
		
		
		double dotPro = top/bottom;
		/*if (dotPro>.9) {
			return 1;
		}
		else {
			return 0;
		}
		*/
		//return dotPro;
		return Math.round(dotPro-.49);
	}
	
	
	
	
	
	public double findCenter(int y) {
		double top=0.0;
		double bottom=0;
				
		for(int x=0; x<width; x++) {
			int c = image.getRGB(x, y);
			int red = (c & 0x00ff0000) >> 16;
			int green = (c & 0x0000ff00) >> 8;
			int blue = c &0x000000ff;
			Color color = new Color(red, green, blue);
			
			top += (similarToo(color, idealColor)*x);
			bottom += similarToo(color, idealColor);
			
			System.out.println("Pixel "+ x);
			System.out.println(color);
			
			System.out.println(similarToo(color, idealColor));		

			
			
			//System.out.println(top);

			//System.out.println(bottom);
			
			//System.out.println(color);
		}
		//System.out.println("");		
		
		
		return top/bottom;
	}
	
	
}
