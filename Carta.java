import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;


public class Carta{
   private int i;
   private int j;
   private String mensaje;
   public JButton boton;

   public Carta(int i, int j){
       this.i=i;
       this.j=j;
       boton=new JButton();
       ActionListener evento=new ActionListener(){
           @Override
           public void actionPerformed(ActionEvent e){
               Cliente cliente=new Cliente(getIJString());
               mensaje=cliente.getmensaje();
               //System.out.println(mensaje);
               ImageIcon imagen=new ImageIcon(mensaje);
               //boton.setEnabled(false);
               boton.setIcon(new ImageIcon(imagen.getImage().getScaledInstance(boton.getWidth(), boton.getHeight(),Image.SCALE_SMOOTH)));
           }
       };
       boton.addActionListener(evento);
   }

   public String getIJString(){
       String valor= String.valueOf(i)+String.valueOf(j);
       return valor;
   }

}