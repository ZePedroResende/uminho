package client;

import java.io.*;
import java.net.Socket;

public class Writer implements  Runnable{
    private Socket socket;
    private BufferedReader in;

    public Writer(Socket socket) throws IOException {
        this.socket = socket;
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }

    @Override
    public void run() {
        try {
            String t = "";
            while ((t = in.readLine()) != null) {
                System.out.println(t);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
