package com.company;

import java.io.IOException;
import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String []args) throws IOException {
        boolean flag = true;
        String t = "";
        String texto = "";
        Socket socket = new Socket("127.0.0.1",12345);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        BufferedReader input= new BufferedReader(new InputStreamReader(System.in));
        while((t = input.readLine()) != null && !t.equals("quit")){
            out.write(t);
            out.newLine();
            out.flush();
            texto = in.readLine();
            System.out.println(texto);
        }
        socket.shutdownOutput();
        texto = in.readLine();
        System.out.println(texto);

        socket.shutdownInput();
        socket.close();
    }
}
