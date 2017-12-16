package com.company;

import java.io.IOException;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Servidor {
    public static void main(String []args) throws IOException {
        Banco banco = new Banco();
        ServerSocket sSock = new ServerSocket(12345);
        banco.criarConta(100);
        ArrayList<BufferedWriter> outList= new ArrayList<>();
        while (true) {
            Socket clSock = sSock.accept();
            Thread thread = new Thread(new Worker(clSock, banco, outList));
            thread.start();
            System.out.println("server");
        }
    }
}
