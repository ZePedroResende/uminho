package src;

public class Barreira {
    int NumeroBlock;
    int count;
    int etapa;
    //para ter a certeza que se pertence a uma batch entao quando a condiçao e comprida esta
    // vai e nao vai ser bloqueada sempre que chega uma thread nova e aumenta o counter

    public Barreira(int numeroBlock) {
        NumeroBlock = numeroBlock;
        count = 0;
        etapa = 0;
    }

    public synchronized void esperar() throws InterruptedException {
       int e = etapa ;
       count+=1;


       if(count == NumeroBlock){
          notifyAll();
          count = 0;
          etapa++;
       }

       else{
           while(count < NumeroBlock && etapa == e)
               wait();
       }
    }
}
