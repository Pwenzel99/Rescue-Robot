package pieceFinder;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class pieceFindTest {

	public static void main(String[] args) {
		BufferedImage image = null;
		Color testColor = new Color (254, 50, 50);
		try {
			File f = new File("C:\\pictest\\cameraRedSquare.jpg");
			image = ImageIO.read(f);
			System.out.println("Reading Complete.");
		}catch(IOException e){
			System.out.println("Error: "+e);
			
	}
		findPiece player1 = new findPiece(image, testColor);
		
		System.out.println(player1.findCenter(535));
		
		
		
	}	
}
