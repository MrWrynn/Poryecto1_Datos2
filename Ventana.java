import java.awt.GridLayout;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * CLase para crear ventana
 */

public class Ventana extends JFrame {
    public int rows=10;
    public int columns=6;
    public ImageIcon cardBack=new ImageIcon("/home/cris/Escritorio/Proyecto1_Datos2/src/CardBack.png");
    public JButton array[][]=new JButton[rows][columns];
    public int p1=0;
    public int p2=0;
    public int num=1; //Turno
    
    public JLabel label1;
    public JLabel label2;
    public JLabel label3;
    public JPanel panel;
    
    
    public Ventana(){
        
        this.setSize(600,600);

        label1=new JLabel("Jugador 1: "+p1);
        label2=new JLabel("Jugador 2: "+p2);
        label3=new JLabel("Turno: Jugador "+num);
        panel=new JPanel();
        this.add(label1);
        this.add(label2);
        this.add(label3);
        this.add(panel);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        panel.setBounds(0, 60, 600, 600);
        label1.setBounds(10, 0, 100, 50);
        label2.setBounds(310, 0, 100, 50);
        label3.setBounds(150,0,150,50);
        panel.setLayout(new GridLayout(rows,columns)); 
        this.botones(panel);
        this.setVisible(true);
    }
    public void botones(JPanel panel) {
        int i=0;
        int j=0;
        while(i<rows){
            
            Carta carta=new Carta(i, j);
            carta.carta.setIcon(new ImageIcon(cardBack.getImage().getScaledInstance(70, 60,Image.SCALE_SMOOTH)));
            panel.add(carta.carta);
            array[i][j]=carta.carta;
            
            j++;
            if (j==columns){
                j=0;
                i++;
            }
        }
    }

    
}