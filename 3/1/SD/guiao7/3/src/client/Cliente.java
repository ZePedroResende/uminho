package client;

import java.io.*;
import java.net.Socket;

public class Cliente {
    public static void main(String[] args) throws IOException, InterruptedException {
        boolean flag = true;
        String t = "";
        String texto = "";
        Socket socket = new Socket("127.0.0.1", 12345);
        Thread Reader = new Thread(new Reader(socket));
        Thread Writer = new Thread(new Writer(socket));
        Reader.start();
        Writer.start();
        Reader.join();
        Writer.join();
        System.out.println("server");
        while(socket.isConnected()){
          Thread.sleep(400);
        }
        socket.shutdownOutput();
        socket.shutdownInput();
        socket.close();
    }
}

