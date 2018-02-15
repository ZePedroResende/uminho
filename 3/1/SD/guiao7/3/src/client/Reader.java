package client;

import java.io.*;
import java.net.Socket;

public class Reader implements Runnable{
    private Socket socket;
    private BufferedWriter out;
    private BufferedReader input;

    public Reader(Socket socket) throws IOException {
        this.socket = socket;
        out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        input= new BufferedReader(new InputStreamReader(System.in));
    }

    @Override
    public void run() {
        try{
            String t= "";
            while((t = input.readLine()) != null && !t.equals("quit")){
                out.write(t);
                out.newLine();
                out.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
