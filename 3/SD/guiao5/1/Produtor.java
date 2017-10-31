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
public class Produtor implements Runnable{
    private BoundedBuffer buffer;
    private int nrProduzir;
    
    public Produtor(BoundedBuffer b, int n){
        this.buffer = b;
        this.nrProduzir = n;
    }
    
    public void run(){
        for(int i=0; i<this.nrProduzir; i++){
            try {
                this.buffer.put(i);
                Thread.sleep(1000);
                //System.out.println("P: "+i);
            } catch (InterruptedException ex) {
                Logger.getLogger(Produtor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
