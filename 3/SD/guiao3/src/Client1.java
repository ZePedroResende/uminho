public class Client1 implements Runnable{
    private Banco banco;

    public Client1(Banco b) {
        banco = b;
    }

    public void run() {
        banco.criarConta(0);
        try {
            banco.transfere(0, 2, 5);
        } catch (InvalidAccount invalidAccount) {
            invalidAccount.printStackTrace();
        } catch (NotEnoughFunds notEnoughFunds) {
            notEnoughFunds.printStackTrace();
        }
        Integer contas[] = {0,1,2};
        banco.consultarTotal(contas);
    }
}

