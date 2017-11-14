package com.company;



import sun.security.jgss.spnego.NegTokenTarg;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class RWLock {

    private int maxReader;
    private int totalReaders;
    private int totalWriters;
    private int reading;
    private int waitingWriting;
    private boolean writing;
    private ReentrantLock lock;
    private Condition noWrite;
    private Condition noRead;

    public RWLock(int maxReader) {
        this.maxReader = maxReader;
        this.totalWriters = maxReader;
        this.totalReaders = 0;
        this.reading = 0;
        this.waitingWriting = 0;
        this.writing = false;
        this.lock = new ReentrantLock();
        this.noWrite = lock.newCondition();
        this.noRead = lock.newCondition();
    }

    public void readLock() throws InterruptedException {
        lock.lock();
        while (writing == true || totalReaders == maxReader){
            noWrite.await();
        }
        totalReaders++;
        reading++;
        lock.unlock();
    }

    public void readUnlock(){
        lock.lock();
        reading--;
        if(waitingWriting == 0 && reading > 0){
            noRead.signalAll();
        }
        else if(reading == 0){
            totalReaders = 0;
            noWrite.signalAll();
        }
        lock.unlock();
    }

    public void writeLock() throws InterruptedException {
        lock.lock();
        waitingWriting++;

        while(writing == true || reading > 0 || (totalWriters >= maxReader && waitingReaders>0) ){
            noRead.await();
        }

        writing= true;
        waitingWriting--;
        lock.unlock();
    }

    public void writeUnlock(){
        lock.lock();
        totalReaders = 0;
        writing = false;
        noRead.signalAll();
        noWrite.signalAll();
        lock.unlock();
    }
}
