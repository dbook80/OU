/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mvc;

import java.awt.Color;
import javax.swing.SwingUtilities;

/**
 *
 * @author Donovan
 * 
 * Central Class to run the GUI
 */
public class Model {
    private final Title title = new Title();
    private final Controller controller;
    private final View view;
    private final MVCFrame mVCFrame;
    
    //Default fields 
    private int size = 44;
    private Color color = new Color(255, 0, 255);
    private boolean solid = true;
    private int titleFontSize = 24;

    public Model() {
        controller = new Controller(this);
        view = new View(this);
        mVCFrame = new MVCFrame(this);
    }

    public Title getTitle() {
        return title;
    }

    public Controller getController() {
        return controller;
    }

    public View getView() {
        return view;
    }

    public MVCFrame getmVCFrame() {
        return mVCFrame;
    }

    public int getSize() {
        return size;
    }

    public Color getColor() {
        return color;
    }

    public boolean isSolid() {
        return solid;
    }

    public int getTitleFontSize() {
        return titleFontSize;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public void setSolid(boolean solid) {
        this.solid = solid;
    }

    public void setTitleFontSize(int titleFontSize) {
        this.titleFontSize = titleFontSize;
    }
    
    public static void main(String[] args) {
        
        SwingUtilities.invokeLater(new Runnable() {
            
            @Override
            
            public void run(){
                Model model = new Model();
            }
        });
    }
}
