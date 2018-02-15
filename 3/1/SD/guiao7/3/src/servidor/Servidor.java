package servidor;

import java.io.BufferedWriter;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Servidor {
    public static void main(String []args) throws IOException {
        ServerSocket sSock = new ServerSocket(12345);
        Hub outList = new Hub();
        while (true) {
            Socket clSock = sSock.accept();
            Thread thread = new Thread(new Worker(clSock, outList));
            thread.start();
            System.out.println("server");
        }
    }
}
