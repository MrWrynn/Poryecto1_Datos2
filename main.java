import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JButton;

public class main {
    public static void main(String[] args) {
        Timer timer=new Timer();
        TimerTask tarea=new TimerTask() {
            Interfaz itf=new Interfaz("eduardo","otro");

            @Override
            public void run() {
                Cliente c=new Cliente("rev");
                if (c.getmensaje() != null){
                    if (c.getmensaje().contains("d") || c.getmensaje().contains("v")){
                        System.out.println(c.getmensaje());
                        char clave=c.getmensaje().charAt(0);
                        int i1=Character.getNumericValue(c.getmensaje().charAt(1));
                        int j1=Character.getNumericValue(c.getmensaje().charAt(2));
                        int i2=Character.getNumericValue(c.getmensaje().charAt(3));
                        int j2=Character.getNumericValue(c.getmensaje().charAt(4));
                        if (clave=='d'){
                            itf.listaB[i1][j1].setEnabled(false);
                            itf.listaB[i2][j2].setEnabled(false);
                            if(c.getmensaje().charAt(5)=='1'){
                                
                                itf.p1+=Character.getNumericValue(c.getmensaje().charAt(6));
                                itf.label1.setText(itf.getnombre1()+": "+itf.p1);
                            }
                            else{
                                itf.p2+=Character.getNumericValue(c.getmensaje().charAt(6));;
                                itf.label2.setText(itf.getnombre2()+": "+itf.p2);
                            }
                        }
                        else{
                            itf.listaB[i1][j1].setText(null);
                            itf.listaB[i2][j2].setText(null);

                        }
                        
                    }

                }
                
            }
            
        };

        timer.schedule(tarea, 0,500);
        
            }
        }
    