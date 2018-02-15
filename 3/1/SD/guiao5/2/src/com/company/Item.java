package com.company;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class Item {
    ReentrantLock lock;
    Condition cond;
    int quantify;

    Item(){
        lock = new ReentrantLock();
        cond = lock.newCondition();
        quantify = 0;
    }

    void supply(int quantify){
        lock.lock();
        this.quantify += quantify;
        lock.unlock();
    }

    void consume() throws InterruptedException {
        lock.lock();
        if(quantify>0){
            this.quantify--;
            cond.signalAll();
        }
        else{
            cond.await();
        }
        lock.unlock();
    }

    public int getQuantify() {
        return quantify;
    }
}
