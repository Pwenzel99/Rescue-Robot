package drawtest;

import static help.DrawHelp.LoadTexture;

import java.awt.*;
import javax.swing.*;
import org.newdawn.slick.opengl.Texture;

import pieceFinder.Table;

import static help.DrawHelp.*;
import static pieceFinder.Table.*;
import org.lwjgl.opengl.Display;
import java.awt.event.*;

public class Menu {
	public Menu() {
	JFrame main = new JFrame("Main Menu");
	JPanel pane = new JPanel(new GridBagLayout());
	JButton b1 = new JButton("Random Map");
	JButton b2 = new JButton("Create Map");
	 
	GridBagConstraints c = new GridBagConstraints();
	//Table t = new Table();
	
	
	c.insets = new Insets(10, 10, 10, 10);
	
	
	main.setVisible(true);
	main.setSize(600, 400);
	main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	pane.setBackground(Color.BLACK);
	b1.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			new Map();
		}
	});
	b2.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			new DrawMap();
		}
	});
	c.gridx = 0;
	c.gridy = 1;
	pane.add(b1, c);
	c.gridx = 0;
	c.gridy = 2;
	pane.add(b2, c);
	main.add(pane);
	
	
	
	
}
}
