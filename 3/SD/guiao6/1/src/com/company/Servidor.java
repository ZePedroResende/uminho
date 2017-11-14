package com.company;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Servidor {
    public static void servidor() throws IOException {
        String texto = "";
        ServerSocket sSock = new ServerSocket(12345);
        while(true){
            boolean flag = true;
            Socket clSock =  sSock.accept();
            BufferedReader in = new BufferedReader(new InputStreamReader(clSock.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(clSock.getOutputStream()));

            while(flag){
               texto = in.readLine();
               out.write(texto);
               out.newLine();
               out.flush();
               if(!texto.equals(""))
                   flag = false;
            }
            System.out.println("server");
            clSock.shutdownOutput();
            clSock.shutdownInput();
            clSock.close();
        }


    }
}
