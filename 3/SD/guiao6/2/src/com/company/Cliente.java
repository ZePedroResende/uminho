package com.company;

import java.io.*;
import java.net.Socket;

public class Cliente {
    public static void client() throws IOException {

        boolean flag = true;
        String texto = "";
        Socket socket = new Socket("127.0.0.1",12345);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

        while(flag){
            System.out.println("entra");
            out.write("ola");
            System.out.println("sai");
            out.flush();
            texto = in.readLine();
            System.out.println(texto);
            if(!texto.equals(""))
                flag=false;
        }

        System.out.println("xau do cliente");
        socket.shutdownOutput();
        socket.shutdownInput();
        socket.close();
    }

}
