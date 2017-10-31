package com.company;

import static java.lang.Thread.sleep;

public class Producer implements Runnable{
    private Warehouse wh;

    public Producer(Warehouse wh) {
        this.wh = wh;
    }

    public void run() {
       this.wh.supply("item1",1);
        try {
            sleep(3);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        this.wh.supply("item2",1);
        try {
            sleep(3);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        this.wh.supply("item3",1);
        try {
            sleep(3);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
