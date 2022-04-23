import java.util.Timer;
import java.util.TimerTask;
import java.awt.GridLayout;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class main {
    public static void main(String[] args) {
        Ventana ventana=new Ventana();
        Timer timer=new Timer();
        TimerTask timerTask=new TimerTask() {
            @Override
            public void run() {
                Cliente cliente=new Cliente("main");
                
                    
            }  
        };
        timer.schedule(timerTask, 0, 1000);
            }
}