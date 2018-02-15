package src;

import src.Barreira;
import src.Mostra;

public class Main {
    private static final int nThreads = 100;
    public static void main(String[] args) throws InterruptedException {
            Barreira barreira = new Barreira(nThreads);
            Thread[] threads = new Thread[nThreads];

            for(int i = 0; i < nThreads; i++) {
                threads[i] = new Thread(new Mostra(barreira));
                threads[i].start();
            }
        }
    }
