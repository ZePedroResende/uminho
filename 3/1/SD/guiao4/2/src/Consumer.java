public class Consumer implements Runnable{
    private final BoundedBuffer buffer;
    private int numOPs;

    Consumer(BoundedBuffer buffer, int numOPs) {
        this.buffer = buffer;
        this.numOPs = numOPs;
    }

    public void run() {
        int item;
        try {
            for(int i = 0; i < numOPs; i++) {
                item = buffer.get();
                Thread.sleep(500);
            //    System.out.println(item);
            }
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}
