import java.util.*;

import static java.lang.Math.min;
import static java.lang.StrictMath.max;

class Conta{
   private Integer saldo;

    public Conta() {
        saldo = 0;
    }

    public Integer getSaldo() {
        return saldo = 0;
    }

    public void setSaldo(Integer saldo) {
        this.saldo = saldo;
    }

    public synchronized  void deposita(Integer deposito){
       saldo += deposito;
    }

    public synchronized void levanta(Integer deposito){
        saldo -= deposito;
    }
}

class Banco{
    private Integer nContas ;
    private List<Conta> contas;


    Banco(int nContas) {
        this.nContas = nContas;
        contas = new ArrayList<>(nContas);

        for(int i = 0; i < nContas; i++)
            contas.add(new Conta());
    }

    public Integer consulta (Integer nConta){
        Conta conta = contas.get(nConta);
       return (conta.getSaldo());
    }

    public void deposita (Integer nConta, Integer valor){
        Conta conta = contas.get(nConta);
        conta.deposita(valor);
    }
    public void levanta (Integer nConta, Integer valor){
        Conta conta = contas.get(nConta);
        conta.levanta(valor);
    }

    public void transferencia(Integer nConta1, Integer nConta2, Integer valor){
        Conta c1 = contas.get(nConta1);
        Conta c2 = contas.get(nConta2);
/*
        if (nConta1 < nConta2){
                    synchronized (c1) {
                        synchronized (c2) {
                            c1.levanta(valor);
                            c2.deposita(valor);
                        }
                    }
                } else {
                    synchronized (c2) {
                        synchronized (c1) {
                            c1.levanta(valor);
                            c2.deposita(valor);
                        }
                    }
        }
        */
        Integer a = max(nConta1,nConta2);
        Integer b = min(nConta1,nConta2);
        synchronized (contas.get(a)) {
            synchronized (contas.get(b)) {
                c1.levanta(valor);
                c2.deposita(valor);
            }
        }
    }
}

class Client implements Runnable{
    private Banco banco;

    public Client(Banco b) {
        banco = b;
    }

    public void run(){
        banco.transferencia(1, 2, 50);
		banco.transferencia(1, 2, 50);
		banco.transferencia(2, 1, 25);
		banco.transferencia(1, 2, 10);
		banco.transferencia(2, 1, 25);
		banco.transferencia(1, 2, 40);
		banco.transferencia(1, 2, 10);
		banco.transferencia(1, 2, 50);
		banco.transferencia(2, 1, 25);
		banco.transferencia(1, 2, 40);
		banco.transferencia(1, 2, 10);
		banco.transferencia(2, 1, 25);
        banco.transferencia(1, 2, 10);    }

}

class Main{

    public static void main(String[] args) throws InterruptedException {
        Integer nContas = 100;
        Integer nClients = 3;
        Banco banco = new Banco(nContas);

        Thread[] threads = new Thread[nClients];

        banco.deposita(1, 1000);
        banco.deposita(2, 1000);

        for(int i = 0; i < nClients; i++) {
            threads[i] = new Thread(new Client(banco));
            threads[i].start();
        }

        for(int i = 0; i < nClients; i++)
            threads[i].join();

        System.out.println("Conta1:" + banco.consulta(1));
        System.out.println("Conta2:" + banco.consulta(2));
    }
}

