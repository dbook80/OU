/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

/**
 *
 * @author Donovan
 */
public class Controller extends JPanel {
    
    private final Model model;

    public Controller(Model model) {
        this.model = model;
        
        setBorder(BorderFactory.createLineBorder(Color.GREEN));
        
        setLayout(new GridLayout(5, 1)); //Separate controller panels
        
        add(new ProgrammerPanel(model)); //add controller panels to the model
        add(new SizePanel(model));
        add(new ColorPanel(model));
        add(new SolidPanel(model));
        add(new TitlePanel(model));
    }
}
