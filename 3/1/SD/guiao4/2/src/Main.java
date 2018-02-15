public class Main {

    public static void main(String[] args) throws InterruptedException {
      double maxDeb = 0;

      for(int a=1 ;a<10; a++) {

        int nConsumers = a;
        int nProducers = 10-a;

        int capacity = 10;

        int restoP = 100 % nProducers;
        int restoC = 100 % nConsumers;

        int totalProducer= 100/nProducers;
        int totalConsumer = 100/nConsumers;

        int tot = 0;

        BoundedBuffer buffer = new BoundedBuffer(capacity);
        Thread[] consumers = new Thread[nConsumers];
        Thread[] producers = new Thread[nProducers];

        final double startTime = System.currentTimeMillis();

        for(int i = 0; i < nConsumers; i++) {
          tot = totalConsumer;
          if(restoC > 0){
            tot++;
            restoC--;
          }
            consumers[i] = new Thread(new Consumer(buffer , tot));
            consumers[i].start();
        }

        for(int i = 0; i < nProducers; i++) {
          tot = totalProducer;
          if(restoP > 0){
            tot++;
            restoP--;
          }
            producers[i] = new Thread(new Producer(buffer , tot));
            producers[i].start();
        }

        for(int i = 0; i < nConsumers; i++) {
            consumers[i].join();
        }

        for(int i = 0; i < nProducers; i++) {
            producers[i].join();
        }
        final double endTime = System.currentTimeMillis();

        System.out.println("Total execution time: " + ((endTime - startTime)/1000) );

        double deb = 100 /  ( (endTime - startTime) / 1000) ;

        System.out.println("O deb foi "+ deb);

        if(maxDeb < deb)
          maxDeb = deb;
      }

        System.out.println("O Maxdeb foi "+ maxDeb);
    }

}
