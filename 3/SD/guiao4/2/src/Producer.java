public class Producer implements Runnable{
    private final BoundedBuffer buffer;

    Producer(BoundedBuffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for(int i = 1; i <= 10; i++)
                buffer.put(i);
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}
