public class Producer implements Runnable{
    private final BoundedBuffer buffer;
    private int numOPs;

    Producer(BoundedBuffer buffer, int numOPs) {
        this.buffer = buffer;
        this.numOPs = numOPs;
    }

    public void run() {
        try {
          for(int i = 1; i <= numOPs; i++){
                buffer.put(i);
                Thread.sleep(1000);
          }
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}
