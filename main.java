import java.util.Timer;
import java.util.TimerTask;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;

public class main {
    public static void main(String[] args) {
        Timer timer=new Timer();
        Ventana itf=new Ventana();
        TimerTask tarea=new TimerTask() {
            @Override
            public void run() {
                Cliente c=new Cliente("rev");
                if (c.getmensaje() != null){

                }
                
            }
            
        };

        timer.schedule(tarea, 0,500);
        
            }
        }
