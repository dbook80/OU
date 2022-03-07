/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

/**
 *
 * @author Donovan
 * 
 * Class to modify the look of the Title control Panel 
 * on the left side of the model and the Title itself.
 * The title is created in the View Class.
 */
public class TitlePanel extends ControlPanel {
    JLabel jlTitle = new JLabel("Title Font Size:");
    JButton jbChange = new JButton();

    public TitlePanel(Model model) {
        super(model);
        
        jbChange.addActionListener(ae -> updateTitleFontSize());
        add(jlTitle);
        add(jbChange);
    }
    
    private void updateTitleFontSize(){
        Object[] titleFontSizes = {
            1, 2, 4, 6, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 60, 72,
            84, 96, 108, 120, 144, 168, 192, 216, 240, 288
        };
        
        Object sizeObject = JOptionPane.showInputDialog(
            null,
            "Select Title Font Size:",
            "",
            JOptionPane.QUESTION_MESSAGE,
            null,
            titleFontSizes,
            null);
        
        if(sizeObject != null){
            int newSize = (Integer) sizeObject;
            model.setTitleFontSize(newSize);
        }
        model.getView().repaint();
    }
}
