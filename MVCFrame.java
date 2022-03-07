/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import java.awt.BorderLayout;
import javax.swing.JFrame;

/**
 *
 * @author Donovan
 * 
 * Class for the outlook of the Model
 */
public class MVCFrame extends JFrame {
    private final Model model;

    public MVCFrame(Model model) {
        this.model = model;
        //Close GUI/program with exit button
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1000,700);
        setTitle("MVC");
        
        setLayout(new BorderLayout()); 
        add(model.getTitle(),BorderLayout.NORTH);
        add(model.getController(),BorderLayout.WEST);
        add(model.getView(), BorderLayout.CENTER);
        setVisible(true);
    }
}
