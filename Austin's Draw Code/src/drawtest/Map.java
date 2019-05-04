package drawtest;

import org.lwjgl.LWJGLException;
//Imports
import org.lwjgl.opengl.Display;
import org.newdawn.slick.opengl.Texture;
import static help.DrawHelp.*;
import static help.MapHelp.*;
import pieceFinder.Table;
import static pieceFinder.Table.*;

import java.awt.Point;
//import java.awt.Point;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Map {
	
	public Map() {
		Display.setTitle("Map");
		BeginSession();
		
		//Initialize Textures
		Texture t = LoadTexture("res/sand.jpg", "JPG");
		Texture t2 = LoadTexture("res/grass03.png", "PNG");
		Texture t3 = LoadTexture("res/water2.png", "PNG");
		Table table = new Table();
		
		
		//Initialize variables/array
		int height = HEIGHT/32;
		int width = WIDTH/32;
		int [][] grid = new int [width][height];
		int mpoints = 75;
		int i, j, xgrid, ygrid;
		Random rand = new Random();
		int texture = 0;
		//int x = (int)xy.getX();
		//int y = (int)xy.getY();
		//int posX;
		//int posY;
		
		//Sets random points in the array to 1
		for (i = 0; i < mpoints; i++) {
			xgrid = ThreadLocalRandom.current().nextInt(0, width);
			ygrid = ThreadLocalRandom.current().nextInt(0, height);
			texture = rand.nextInt(100);
			if (texture < 75) {
			grid [xgrid][ygrid] = 1;
			}
			else if (texture < 95) {
				grid [xgrid][ygrid] = 2;
			}
			else {
				grid [xgrid][ygrid] = 3;
			}
		}
		
		//While display is not prompted to exit
			
			//Draws tiles with textures
			for (i = 0; i < width; i++) {
				for (j = 0; j < height; j++) {
					if(Distance(i, j, grid) == 1) {
						DrawTileTex(t2,32*i, 32*j, 32, 32);
					}
					else if(Distance(i, j, grid) ==  2) {
						DrawTileTex(t3, 32*i, 32*j, 32, 32);
					}
					else if(Distance(i, j, grid) == 3) {
						DrawTileTex(t, 32*i, 32*j, 32, 32);
					}
				}
			}
			//DrawTileTex(t4, 250, 200, 20, 20);
			
			
			//Updates screen
			Display.update();
			for (i = 0; i < width; i++) {
				for (j = 0; j < height; j++) {
					if(Distance(i, j, grid) == 1) {
						DrawTileTex(t2,32*i, 32*j, 32, 32);
					}
					else if(Distance(i, j, grid) ==  2) {
						DrawTileTex(t3, 32*i, 32*j, 32, 32);
					}
					else if(Distance(i, j, grid) == 3) {
						DrawTileTex(t, 32*i, 32*j, 32, 32);
					}
				}
			}
			Display.update();
			
			//Display.sync(60);
			while(!Display.isCloseRequested()) {
				Texture t4 = LoadTexture("res/marker.png", "PNG");
				Point p = new Point(table.getPoint());
				final double x = p.getX();
				final double y = p.getY();
				
				for (i = 0; i < width; i++) {
					for (j = 0; j < height; j++) {
						if(Distance(i, j, grid) == 1) {
							DrawTileTex(t2,32*i, 32*j, 32, 32);
						}
						else if(Distance(i, j, grid) ==  2) {
							DrawTileTex(t3, 32*i, 32*j, 32, 32);
						}
						else if(Distance(i, j, grid) == 3) {
							DrawTileTex(t, 32*i, 32*j, 32, 32);
						}
					}
				}
				DrawTileTex(t4, (int)x, (int)y, 20, 20);
				Display.update();
				Display.sync(60);
			}
			
			
		//Closes display	
		Display.destroy();
	}
	
	//Main function that creates a new Drawing()
	public static void main(String[] args) {
		new Menu();
	}
}
