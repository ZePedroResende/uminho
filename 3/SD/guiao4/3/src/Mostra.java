package src;

public class Mostra extends Thread {
    private Barreira barreira;

    public Mostra(Barreira barreira) {
        this.barreira = barreira;
    }

    public void run() {
        try {
            for(int i = 0; i < 5; i++){
                System.out.println(i);
                barreira.esperar();
            }
        } catch(InterruptedException e) {
            System.out.println("Oops!");
        }
    }
}
