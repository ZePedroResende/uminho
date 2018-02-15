package com.company;

import java.io.IOException;
import java.io.*;
import java.net.Socket;

public class Main {

    public static void main(String[] args) throws IOException {
        boolean flag = true;
        String texto = "";
        Socket socket = new Socket("127.0.0.1",12345);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

        while(flag){
            out.write("OLAAAAA");
            out.newLine();
            out.flush();
            texto = in.readLine();
            System.out.println(texto);
            if(!texto.equals(""))
                flag=false;
        }

        socket.shutdownOutput();
        socket.shutdownInput();
        socket.close();
    }
}
