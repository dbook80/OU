/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

/**
 *
 * @author Donovan
 */
public class View extends JPanel {
    private final Model model;

    public View(Model model) {
        this.model = model;
        setBorder(BorderFactory.createLineBorder(Color.BLUE, 2));
        repaint();
    }
    
    @Override
    protected void paintComponent(Graphics g) {
    super.paintComponents(g); // call the super class c-tor
    // center of view panel, in pixels:
    g.clearRect(0, 0, getWidth(), getHeight());
    int xCenter = getWidth() / 2; // calculate center of panel
    int yCenter = getHeight() / 2;
    int size = model.getSize();
    int xStart = xCenter - size;
    int yStart = yCenter - size;
    int xWidth = 2 * size;
    int yHeight = 2 * size;
    
    g.setColor(model.getColor());
    if(model.isSolid()){
        g.fillOval(xStart, yStart, xWidth, yHeight); 
    }
    else{
        g.drawOval(xStart, yStart, xWidth, yHeight);
    }
    //Title of the View Panel
    Color titleFontColor = new Color(102,51,0);
    g.setColor(titleFontColor);
    
    Font font = new Font("Arial", Font.BOLD, model.getTitleFontSize());
    g.setFont(font);
    
    g.drawString("View", 10, getHeight() / 6);
 }

}
