package servidor;

import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;

public class Hub {
    private ArrayList<BufferedWriter> hub ;
    private ReentrantLock lock;

    public Hub() {
        this.hub = new ArrayList<>();
        lock = new ReentrantLock();
    }

    public void add(BufferedWriter string){
        lock.lock();
        hub.add(string);
        lock.unlock();
    }

    public void remove(BufferedWriter string){
        lock.lock();
        hub.remove(string);
        lock.unlock();

    }

    public void call(String texto){
        try {
            lock.lock();
            for(BufferedWriter out: hub) {
                out.write(texto);
                out.newLine();
                out.flush();
            }
            lock.unlock();
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
