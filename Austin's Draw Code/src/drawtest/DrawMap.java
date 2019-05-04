package drawtest;

import static help.DrawHelp.BeginSession;
import static help.DrawHelp.DrawTileTex;
import static help.DrawHelp.HEIGHT;
import static help.DrawHelp.LoadTexture;
import static help.DrawHelp.WIDTH;

import org.lwjgl.input.Mouse;
//Imports
import org.lwjgl.opengl.Display;
import org.newdawn.slick.opengl.Texture;

public class DrawMap {
	public DrawMap() {
		Display.setTitle("Map (Grass)");
		BeginSession();
			
		//Initialize Textures
		Texture t = LoadTexture("res/sand.jpg", "JPG");
		Texture t2 = LoadTexture("res/grass03.png", "PNG");
		Texture t3 = LoadTexture("res/water2.png", "PNG");
					
		//Initialize variables/array
		int height = HEIGHT/64;
		int width = WIDTH/64;
		int x = 0, y = 0, i, posX = 0, posY = 0;
		
		boolean leftButtonDown = Mouse.isButtonDown(0);
		boolean rightButtonDown = Mouse.isButtonDown(1);
		
		Texture tex = t2;
		int temp = 0;
		int loop = 0;
		
		while(!Display.isCloseRequested()) {
			leftButtonDown = Mouse.isButtonDown(0);
			rightButtonDown = Mouse.isButtonDown(1);
			if(leftButtonDown) {
				x = Mouse.getX();
				y = Mouse.getY();
				for(i = 0; i < width; i++) {
					if(x > i*64 && x < (i+1)*64) {
						posX = i;
					}
				}
				for(i = 0; i < height; i++) {
					if(y > i*64 && y < (i+1)*64) {
						posY = height - 1 - i;
					}
				}
				DrawTileTex(tex, 64*posX, 64*posY, 64, 64);
				
			}
			if(rightButtonDown && loop == 0) {
				loop = 1;
				temp += 1;
				if(temp > 2) {
					temp = 0;
				}
				if(temp == 0) {
					Display.setTitle("Map (Grass)");
					tex = t2;
				}
				else if(temp == 1) {
					Display.setTitle("Map (Water)");
					tex = t3;
				}
				else if(temp == 2) {
					Display.setTitle("Map (Sand)");
					tex = t;
				}
			}
			if(!rightButtonDown) {
				loop = 0;
			}
			Display.update();
			Display.sync(60);
			x = Mouse.getX();
			y = Mouse.getY();
			System.out.println(rightButtonDown);
			System.out.println(x);
			System.out.println(y);
		}
		
		Display.destroy();
	}
	
}
