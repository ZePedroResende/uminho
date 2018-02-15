/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author oem
 */
public class BoundedBuffer {
    
    private int[] values;
    int poswrite;
    Lock lock;
    Condition empty, full;
    
   public BoundedBuffer(int capacidade){
       this.values = new int[capacidade];
       this.poswrite = 0;
       lock = new ReentrantLock();
       empty = lock.newCondition();
       full = lock.newCondition();
   }
   
   public void put(int v) throws InterruptedException{
       lock.lock();
       while(!(poswrite < values.length)){
           full.await();
       }
       
       values[poswrite] = v;
       poswrite++;
       empty.signalAll();
       lock.unlock();
   }
   
   public synchronized int get() throws InterruptedException{
       lock.lock();
       while(!(poswrite > 0)){
           empty.await();
       }

       int valor = this.values[poswrite-1];
       poswrite--;
       full.signalAll();
       lock.unlock();
       return valor;
   }
}
