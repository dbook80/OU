/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import java.awt.Color;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JLabel;

/**
 *
 * @author Donovan
 */
public class ColorPanel extends ControlPanel {
    
    JLabel jlColor = new JLabel("Set Color:  ");
    JButton jbColor = new JButton("Change:  ");

    public ColorPanel(Model model) {
        super(model);
        //Allows users to do the action of changing colors
        jbColor.addActionListener(ae -> changeColor());
        
        add(jlColor); //adding label & button to the Panel
        add(jbColor);
    }
    private void changeColor(){ 
        model.setColor(JColorChooser
                .showDialog(
                        this, 
                        "Choose New Color", 
                        model.getColor()));
        model.getView().repaint();
    }
    
}
