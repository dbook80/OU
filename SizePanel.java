/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author Donovan
 */
public class SizePanel extends ControlPanel {

        JLabel jlSize = new JLabel("Set Size:  ");
        JTextField jtfSize;
        
    public SizePanel(Model model) {
        super(model);
        
        jtfSize = new JTextField(10);
        
        jtfSize.setText("" + model.getSize());
        
        jtfSize.addActionListener(ae -> updateSize());
        
        add(jlSize);
        add(jtfSize);
    }
    
    private void updateSize(){ 
        String stringNewSize = jtfSize.getText();// get the string entered
        
        try {
            int newSize = Integer.parseInt(stringNewSize); // parse to int
            model.setSize(newSize); // update model
            model.getView().repaint(); // draw again
        } 
        catch (Exception e) { // deal with WTF
            jtfSize.setText("BAD INPUT!"); // msg to jtf
            JOptionPane.showMessageDialog( // GUI msg
            null,
            "Invalid input. Not a number.", // error message
            "Error Message:", // error title
            JOptionPane.ERROR_MESSAGE); // error symbol
           jtfSize.setText("" + model.getSize()); // msg to jtf
        }
    }
}
