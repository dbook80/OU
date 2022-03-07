/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

/**
 *
 * @author Donovan
 * 
 * Class to create borders for all 5 panels
 */
public class ControlPanel extends JPanel {
    final protected Model model;
    
    public ControlPanel(Model model){
        this.model = model;
        setBorder(BorderFactory.createEtchedBorder());
    }
}
