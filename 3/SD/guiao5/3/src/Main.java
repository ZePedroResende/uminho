import com.company.*;
public class Main {

    public static void main(String[] args) {
        RWLock rw = new RWLock(15);

        Thread[] read = new Thread[15];
        Thread[] write = new Thread[15];

        for(int i= 0 ; i<15; i++){
            read[i]= new Thread(new Reader(rw,i));
            write[i]= new Thread(new Writer(rw,i));
        }

        for(int i= 0 ; i<15; i++){
            read[i].start();
            write[i].start();
        }

        for(int i= 0 ; i<15; i++){
            try {
                read[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            try {
                write[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
