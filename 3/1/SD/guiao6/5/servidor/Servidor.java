import java.io.IOException;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
public class Servidor {
    public static void servidor() throws IOException {
        ServerSocket sSock = new ServerSocket(12345);

        while (true) {

            Socket clSock = sSock.accept();
            Thread thread = new Thread(new Worker(clSock));
            thread.start();
            System.out.println("server");
        }
    }
}
