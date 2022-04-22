import java.awt.GridLayout;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Ventana extends JFrame {
    private int rows=10;
    private int columns=6;
    public int p1=0;
    public int p2=0;
    public int num=1;
    public JLabel label1;
    public JLabel label2;
    public JLabel label3;
    private JPanel panel;
    public ImageIcon reves=new ImageIcon("/home/cris/Escritorio/Proyecto1_Datos2/src/CardBack.png");
    public JButton listaB[][]=new JButton[rows][columns];
    

    public Ventana(){
        this.setSize(550,550);
        label1=new JLabel("Jugador 1: "+p1);
        label2=new JLabel("Jugador 2: "+p2);
        label3=new JLabel("Turno: Jugador"+num);
        panel=new JPanel();
        this.add(label1);
        this.add(label2);
        this.add(label3);
        this.add(panel);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        panel.setBounds(0, 60, 550, 450);
        label1.setBounds(10, 0, 150, 30);
        label2.setBounds(310, 0, 150, 30);
        label3.setBounds(100,0,150,30);
        panel.setLayout(new GridLayout(rows,columns)); 
        this.setVisible(true);
        this.botones(panel);
    
    }
    public void botones(JPanel panel) {
        int i=0;
        int j=0;
        while(i<rows){
            Carta ficha=new Carta(i, j);
            panel.add(ficha.boton);
            listaB[i][j]=ficha.boton;
            ficha.boton.setIcon(new ImageIcon(reves.getImage().getScaledInstance(70, 60,Image.SCALE_SMOOTH)));
            j++;
            if (j==columns){
                j=0;
                i++;
            }
        }
    }

    
}