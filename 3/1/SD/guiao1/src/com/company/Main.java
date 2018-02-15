package com.company;

import sun.net.www.protocol.http.HttpURLConnection;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Runnable1 implements Runnable{
    int i = 0 ;

    public Runnable1(int i) {
        this.i = i;
    }

    public void run(){
       for( int a= 1 ; a <i; a++)
           System.out.print("T" + Thread.currentThread().getName() + ":"+ a+ "\n");
    }

}
class Counter {
    int num;

    Counter() {
        num = 0;
    }

    public int getNum() {
        return num;
    }

    public void increment() {
        num += 1;
    }

    public String toString() {
        return Integer.toString(num);
    }
}

class Runnable2 implements Runnable{
    Counter C;

    public Runnable2() {
        C = new Counter();
    }

    public void run(){
        C.increment();
    }

}

class Runnable3 implements Runnable{
    Counter C;

    public Runnable3() {
        C = new Counter();
    }

    public void run(){
        C.num++;
    }

}
/*
public class Main  {

    public static void main(String[] args) throws InterruptedException {
        int N = 10 ;
        int i = 5;

        Thread[] ThreadArray = new Thread[N];

        for(int a = 0 ; a < N; a++){
            ThreadArray[a] = new Thread(new Runnable1(i));
            ThreadArray[a].setName(String.valueOf(a));
        }

        for(int a = 0 ; a < N; a++){
            ThreadArray[a].start();
        }
        for(int a = 0 ; a < N; a++){
            ThreadArray[a].join();
        }
    }
}
*/

public class Main  {

    public static void main(String[] args) throws InterruptedException {
        int N = 10 ;
        int i = 5;

        Thread[] ThreadArray = new Thread[N];
        Runnable2 r2 = new Runnable2();
        for(int a = 0 ; a < N; a++){
            ThreadArray[a] = new Thread(r2);
        }

        for(int a = 0 ; a < N; a++){
            ThreadArray[a].start();
        }
        for(int a = 0 ; a < N; a++){
            ThreadArray[a].join();
        }

        System.out.print(r2.C.getNum());
    }
}
