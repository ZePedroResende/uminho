/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import static java.lang.Thread.sleep;

/**
 *
 * @author oemjn
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException{
        BoundedBuffer buffer = new BoundedBuffer(10);
        int i, consumir, produzir, C, P, restoC, restoP;
        double tempoInicio, tempoFim, debito;
        
        for(int n=1; n<10; n++){
            C = n;
            P = 10-n;
            restoC = 100 % C;
            restoP = 100 % P;
        
            consumir = 100 / C;
            produzir = 100 / P;
        
            Thread[] t1 = new Thread[C];
            Thread[] t2 = new Thread[P];
        
            for(i=0; i<C; i++){
                if(restoC > 0){
                    t1[i] = new Thread(new  Consumidor(buffer, consumir+1));
                    restoC--;
                }
                else t1[i] = new Thread(new  Consumidor(buffer, consumir));
            }
        
            for(i=0; i<P; i++){
                if(restoP > 0){
                    t2[i] = new Thread(new  Produtor(buffer, produzir+1));
                    restoP--;
                }
                else t2[i] = new Thread(new  Produtor(buffer, produzir));
            }
        
            tempoInicio = System.currentTimeMillis();
        
            for(i=0; i<C; i++){
                t1[i].start();
            }
        
            for(i=0; i<P; i++){
                t2[i].start();
            }
       
            try{
                for(i=0; i<C; i++){
                    t1[i].join();
                }
                for(i=0; i<P; i++){
                    t2[i].join();
                }
            } catch (InterruptedException e){
                System.err.println("Erro na join");
                e.printStackTrace();
            }
        
            tempoFim = System.currentTimeMillis();

            System.out.println( "Total execution time:" + ((tempoFim - tempoInicio) /1000));
            debito = 100 / ((tempoFim - tempoInicio) * Math.pow(10, -3));
        
            System.out.println("Debito"+n+": "+debito);
        }
    }
    
}
