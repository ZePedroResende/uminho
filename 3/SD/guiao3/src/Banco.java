import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.ReentrantLock;

import static java.lang.Math.max;
import static java.lang.StrictMath.min;

public class Banco{
    private int nextIdConta;
    private ReentrantLock lockBanco;
    private Map<Integer,Conta> contas;


    Banco() {
        lockBanco = new ReentrantLock();
        this.nextIdConta= 1;
        contas = new HashMap<>();
    }

    public int criarConta(float initialBalance) {
        lockBanco.lock();
        int id = this.getNextIdConta();
        contas.put(id , new Conta(initialBalance));
        this.setNextIdConta(id++);
        lockBanco.unlock();
        return id;
    }

    public void deposita (Integer nConta, Integer valor){
        Conta conta = contas.get(nConta);
        conta.deposita(valor);
    }
    public void levanta (Integer nConta, Integer valor) throws InvalidAccount{
        Conta conta = contas.get(nConta);
        if(conta== null)
            throw new InvalidAccount();
        conta.levanta(valor);
    }


    public float fecharConta(Integer id) throws InvalidAccount {
        lockBanco.lock();
        Conta conta = contas.get(id);
        if(conta== null)
            throw new InvalidAccount();
        if(conta == null)
            throw new InvalidAccount();
        float saldo = conta.getSaldo();
        contas.remove(id);
        lockBanco.unlock();
        return saldo;
    }

    public void transfere(int nConta1, int nConta2, float valor) throws InvalidAccount, NotEnoughFunds {

        Conta c1 = contas.get(nConta1);
        if(c1== null)
            throw new InvalidAccount();
        Conta c2 = contas.get(nConta2);
        if(c2== null)
            throw new InvalidAccount();
        if(c1.getSaldo() < valor)
            throw new NotEnoughFunds();
        else {
            c1.levanta(valor);
            c2.deposita(valor);
        }

    }

    public float consultarTotal(Integer accounts[]) {
        float total = 0;
        lockBanco.lock();
        for (Integer c : accounts) {
            total = contas.get(c).getSaldo();
        }
        lockBanco.unlock();
        return (total);
    }

    public void setNextIdConta(int nextIdConta) {
        this.nextIdConta = nextIdConta;
    }

    public int getNextIdConta() {
        return nextIdConta;
    }
}



