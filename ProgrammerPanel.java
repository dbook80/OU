/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import javax.swing.JLabel;

/**
 *
 * @author Donovan
 */
public class ProgrammerPanel extends ControlPanel {

        JLabel jlProgrammer = new JLabel("Programmer:  ");
        JLabel jlYourName = new JLabel("Donovan Booker");
    
    public ProgrammerPanel(Model model) {
        super(model);
        add(jlProgrammer);
        add(jlYourName);
    }
    
}
