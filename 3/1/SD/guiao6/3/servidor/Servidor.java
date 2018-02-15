import java.io.IOException;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
public class Servidor {
    public static void servidor() throws IOException {
        String texto = "";
        int total = 0;
        int numeroDeEscritas=0;
        ServerSocket sSock = new ServerSocket(12345);

        while (true) {

            Socket clSock = sSock.accept();
            BufferedReader in = new BufferedReader(new InputStreamReader(clSock.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(clSock.getOutputStream()));

               while((texto = in.readLine()) != null) {
                   total += Integer.parseInt(texto);
                   numeroDeEscritas++;
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
            System.out.println("server");
            clSock.shutdownOutput();
            clSock.shutdownInput();
            clSock.close();
        }
    }
}
