package com.company;

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

