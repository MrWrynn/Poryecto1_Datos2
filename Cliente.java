import java.io.BufferedInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

/**
 * Esta clase permite crear el cliente que envía los mensajes al servidor
 */
public class Cliente {
    private String Host="localhost";
    private int Port=7979;
    private BufferedInputStream input;
    private DataOutputStream output;
    private String mensaje;
    public Cliente(String envio){
        try {
            Socket socket=new Socket(Host,Port);
            output = new DataOutputStream(socket.getOutputStream());
            input=new BufferedInputStream(socket.getInputStream());
            byte[] buffer=new byte[25000];
            int bytesRead=0;
            output.writeUTF(envio);
            while((bytesRead=input.read(buffer))!=-1){
                mensaje=new String(buffer,0,bytesRead);
                break;
            }
            socket.close();
        } catch (Exception e) {
        }
    }
    public String getmensaje() {
        return mensaje;  
    }
}