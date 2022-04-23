import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;


public class Carta{
   private int i;
   private int j;
   private String mensaje;
   public JButton carta;

   public Carta(int i, int j){
        carta=new JButton();

       this.i=i;
       this.j=j;
       
       ActionListener evento=new ActionListener(){
           @Override
           public void actionPerformed(ActionEvent evento){
               Cliente cliente=new Cliente(getIJString());
               mensaje=cliente.getmensaje();
               //System.out.println(mensaje);
               ImageIcon imagen=new ImageIcon(mensaje);
               //boton.setEnabled(false);
               carta.setIcon(new ImageIcon(imagen.getImage().getScaledInstance(carta.getWidth(), carta.getHeight(),Image.SCALE_SMOOTH)));

           }
       };

       carta.addActionListener(evento);
   }
   /**
    * metodo para obtener i y j y enviarlos por el cliente
    */
   public String getIJString(){
       String valor= String.valueOf(i)+String.valueOf(j);
       return valor;
   }

}