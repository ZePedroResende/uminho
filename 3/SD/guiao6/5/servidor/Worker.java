import com.sun.imageio.spi.OutputStreamImageOutputStreamSpi;

import java.io.*;
import java.net.Socket;

public class Worker implements Runnable{
    private Socket socket;
    private BufferedReader in  = null;
    private BufferedWriter out = null;

    public Worker(Socket socket) throws IOException {
      socket = socket;
      in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
    }

    @Override
    public void run() {
        String texto;
        int total = 0;
        int numeroDeEscritas = 0;
        try{

            while((texto = in.readLine()) != null) {
                total += Integer.parseInt(texto); numeroDeEscritas++;
                out.write(Integer.toString(total));
                out.newLine();
                out.flush();
            }

            out.write(Integer.toString(total/numeroDeEscritas));
            System.out.println(total/numeroDeEscritas);

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
