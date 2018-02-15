package com.company;

import static java.lang.Thread.sleep;

public class Writer implements Runnable{
    private RWLock rwLock;
    private int id;

    public Writer(RWLock rwLock, int id) {
        this.rwLock = rwLock;
        this.id = id;
    }

    @Override
    public void run() {
        try {
            rwLock.writeLock();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("WRITE ENTRA ID:"+ id);
        try {
            sleep(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("WRITE SAI ID:"+ id);
        rwLock.writeUnlock();
    }
}
