package servidor;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;

public class Worker implements Runnable {
    private Socket socket;
    private Hub outList;
    private BufferedReader in;

    public Worker(Socket socket, Hub outList) throws IOException {
        this.socket = socket;
        outList.add(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())));
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.outList = outList;
    }

    @Override
    public void run() {
        String texto = "";
        try{

            while((texto = in.readLine()) != null) {
                outList.call(texto);
            }


            /*
            out.newLine();
            out.flush();
            out.write("quit");
            out.newLine();
            out.flush();
            */

            socket.shutdownOutput();
            socket.shutdownInput();
            socket.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

    }

}
