import com.sun.imageio.spi.OutputStreamImageOutputStreamSpi;

import java.io.*;
import java.net.Socket;

public class Worker implements Runnable{
    private Socket socket;
    private Banco banco;
    private BufferedReader in  = null;
    private BufferedWriter out = null;

    public Worker(Socket socket, Banco banco) throws IOException {
      this.socket = socket;
      this.banco = banco;
      in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
    }

    @Override
    public void run() {
        String texto = "";
        int total = 0;
        try{

            while((texto = in.readLine()) != null) {
              total = Integer.parseInt(texto);
              if(total == 1){
                  total = (int) banco.consultar(1);
              }
              else if( total == 2 ){
                banco.deposita(1,100);
                total = 100;
              }
              out.write(Integer.toString(total));
              out.newLine();
              out.flush();
            }

            System.out.println(banco.consultar(1));
            out.newLine();
            out.flush();
            out.write("quit");
            out.newLine();
            out.flush();

            socket.shutdownOutput();
            socket.shutdownInput();
            socket.close();
        }
         catch (IOException e) {
            e.printStackTrace();
        }

    }
}
