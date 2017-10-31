package com.company;

public class Main {
    public static void main(String[] args){
        Warehouse wh = new Warehouse();

        Thread c = new Thread( new Consumer(wh));
        Thread p = new Thread(new Producer(wh));
        c.start();
        p.start();

        try {
            c.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
            p.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        for(int i = 1; i <= 3; i++)
            System.out.println(wh.getStock("" + i));
    }
}

