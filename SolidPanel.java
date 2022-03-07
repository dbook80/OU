/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

/**
 *
 * @author Donovan
 */
public class SolidPanel extends ControlPanel {
    
    JLabel jlSolid = new JLabel("Solid:");
    JPanel jpButtons = new JPanel();
    JRadioButton jrbYes = new JRadioButton("Yes");
    JRadioButton jrbNo = new JRadioButton("No");
    ButtonGroup bgSolid = new ButtonGroup();

    public SolidPanel(Model model) {
        super(model);
        
        if(model.isSolid()) {
            jrbYes.setSelected(true);
        } 
        else {
            jrbNo.setSelected(true);
        }
        
        jrbYes.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                model.setSolid(true);
                model.getView().repaint();
            }
        });
        
        jrbNo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                model.setSolid(false);
                model.getView().repaint();
            }
        });
        bgSolid.add(jrbYes);
        bgSolid.add(jrbNo);
        jpButtons.add(jrbYes);
        jpButtons.add(jrbNo);
        jpButtons.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        add(jlSolid);
        add(jpButtons);
    }
    
}
