/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author oem
 */
public class Consumidor implements Runnable{
    private BoundedBuffer buffer;
    private int nrConsumir;
    
    public Consumidor(BoundedBuffer b, int n){
        this.buffer = b;
        this.nrConsumir = n;
    }
    
    public void run(){
        int tmp;
        
        for(int i=0; i<this.nrConsumir; i++){
            try {
                tmp = this.buffer.get();
                Thread.sleep(500);
                //System.out.println("C: "+tmp);
            } catch (InterruptedException ex) {
                Logger.getLogger(Consumidor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
