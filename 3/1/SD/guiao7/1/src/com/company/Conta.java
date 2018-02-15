package com.company;

import java.util.concurrent.locks.ReentrantLock;

public class Conta{
    private float saldo;
    private ReentrantLock lockConta;

    public Conta() {
        float saldo = 0;
        lockConta= new ReentrantLock();
    }

    public Conta(float saldo) {
        lockConta = new ReentrantLock();
        this.saldo = saldo;
    }
    public float getSaldo() {
        lockConta.lock();
        float f = saldo;
        lockConta.unlock();
        return f;
    }

    public void setSaldo(float saldo) {
        lockConta.lock();
        this.saldo = saldo;
        lockConta.unlock();
    }

    public synchronized  void deposita(float deposito){
        lockConta.lock();
        saldo += deposito;
        lockConta.unlock();
    }

    public synchronized void levanta(float deposito){
        lockConta.lock();
        saldo -= deposito;
        lockConta.unlock();
    }
}

