package com.company;

import static java.lang.Thread.sleep;

public class Reader implements Runnable{
    private RWLock rwlock;
    private int id;
    public Reader(RWLock rwlock, int id) {
        this.rwlock = rwlock;
        this.id = id;
    }


    @Override
    public void run() {
        try {
            rwlock.readLock();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("READ ENTRA ID:"+ id);
        try {
            sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("READ SAI ID:"+ id);
        rwlock.readUnlock();
    }
}
