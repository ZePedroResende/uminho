package com.company;

import java.io.*;
import java.net.Socket;
import java.util.ArrayList;

public class Worker implements Runnable{
    private Socket socket;
    private Banco banco;
    private BufferedReader in  = null;
    private ArrayList<BufferedWriter> outList;

    public Worker(Socket socket, Banco banco, ArrayList<BufferedWriter> outList) throws IOException {
      this.socket = socket;
      this.banco = banco;
      in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      outList.add(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())));
      this.outList = outList ;
    }

    @Override
    public void run() {
        String texto = "";
        int total = 0;
        try{

            while((texto = in.readLine()) != null) {
              total = Integer.parseInt(texto);
              if(total == 1){
                  total = (int) banco.consultar(1);
              }
              else if( total == 2 ){
                banco.deposita(1,100);
                total = 100;
              }
                for(BufferedWriter out: this.outList) {
                    System.out.println("entrei");
                    out.write(Integer.toString(total));
                    out.newLine();
                    out.flush();
                }
            }

            System.out.println(banco.consultar(1));

            /*
            out.newLine();
            out.flush();
            out.write("quit");
            out.newLine();
            out.flush();
            */

            socket.shutdownOutput();
            socket.shutdownInput();
            socket.close();
        }
         catch (IOException e) {
            e.printStackTrace();
        }

    }
}
