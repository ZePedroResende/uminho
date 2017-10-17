public class BoundedBuffer {
    private int[] buffer;
    private int poswrite;

    public BoundedBuffer(int buffer) {
        this.buffer = new int[buffer];
        this.poswrite = 0;
    }


    public synchronized void put(int v) throws InterruptedException {
        while(poswrite == buffer.length)
            wait();

        buffer[poswrite] = v;
        poswrite++;

        notifyAll();
    }

    public synchronized int get() throws InterruptedException {
        int item;

        while (poswrite == 0)
            wait();

        item = buffer[poswrite];
        poswrite--;

        notifyAll();
        return item;
    }
}

