import java.io.IOException;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
public class Servidor {
    public static void servidor() throws IOException {
        Banco banco = new Banco();
        ServerSocket sSock = new ServerSocket(12345);
        banco.criarConta(100);
        while (true) {
            Socket clSock = sSock.accept();
            Thread thread = new Thread(new Worker(clSock, banco));
            thread.start();
            System.out.println("server");
        }
    }
}
