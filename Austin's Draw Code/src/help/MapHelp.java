package help;

import static help.DrawHelp.WIDTH;
import static help.DrawHelp.HEIGHT;

public class MapHelp {
	public static int Distance(int x, int y, int [][] grid) {
		int i, j;
		int width = WIDTH/32;
		int height = HEIGHT/32;
		
		double distance1 = 1000000000, distance2 = 1000000000, distance3 = 1000000000, temp;
		for (i = 0; i < width; i++) {
			for(j = 0; j < height; j++) {
				if(grid[i][j] == 1) {
					temp = Math.sqrt((x-i)*(x-i)+(y-j)*(y-j));
					if (temp < distance1) {
						distance1 = temp;
					}
				}
				if(grid[i][j] == 2) {
					temp = Math.sqrt((x-i)*(x-i)+(y-j)*(y-j));
					if(temp < distance2) {
						distance2 = temp;
					}
				}
				if(grid[i][j] == 3) {
					temp = Math.sqrt((x-i)*(x-i)+(y-j)*(y-j));
					if(temp < distance3) {
						distance3 = temp;
					}
				}
			}
		}
		if(distance1 < distance2 && distance1 < distance3) {
			return 1;
		}
		else if(distance2 < distance1 && distance2 < distance3){
			return 2;
		}
		else {
			return 3;
		}
	}
}
