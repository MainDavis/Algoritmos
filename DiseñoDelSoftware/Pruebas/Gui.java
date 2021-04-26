import java.awt.BorderLayout;
import java.awt.Point;

import javax.imageio.spi.ImageInputStreamSpi;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;

public class Gui {
    private int ancho;
    private int alto;
    private String titulo;
    private Icon pj_idle, pj_attack, pj_run, pj_death;
    private JButton p1, p2;
    private Boolean estado=false;

    public Gui(int ancho, int alto, String titulo){
        this.alto  = alto;
        this.ancho = ancho;
        this.titulo = titulo;

        JFrame frame = new JFrame(titulo);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);      
        frame.setSize(ancho, alto);
        frame.setResizable(false);

        pj_attack = new ImageIcon("NightBorne_attack.gif");
        pj_idle = new ImageIcon("NightBorne_idle.gif");
        pj_run = new ImageIcon("NightBorne_run.gif");
        pj_death = new ImageIcon("NightBorne_death.gif");

        p2 = new JButton(pj_idle);
        p2.setSize(100,100);
        
        p2.setLocation(new Point(0, 0));  
        frame.add(BorderLayout.EAST, p1);  
        
        p1 = new JButton(pj_idle);
        p1.setSize(300,300);
        p1.setLocation(0, 0);
        frame.getContentPane().add(BorderLayout.WEST, p1);


        frame.setVisible(true); 

    }

    public void cambiar(String estado){
        switch(estado){
            case "run":
                p1.setIcon(pj_run);
                break;
            case "idle":
                p1.setIcon(pj_idle);
                break;
            case "attack":
                p1.setIcon(pj_attack);
                break;
            default:
                System.out.println("Te has equivocado lol");
        }
    }

    public void attack(){
        p1.setIcon(pj_attack);

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        p1.setIcon(pj_idle);
    }
}
