class Main{

    public static void main(String[] args) throws InterruptedException {
        Banco banco = new Banco();

        Thread[] threads = new Thread[2];
        banco.criarConta(10);
        banco.criarConta(10);

        for(int i = 0; i < 2; i++){
            threads[i] = new Thread(new Client1(banco));
            threads[i].start();
        }

        for(int i = 0; i < 2; i++)
            threads[i].join();

        System.out.println("Conta1:" + banco.consultarTotal(new Integer[] {1}));
        System.out.println("Conta2:" + banco.consultarTotal(new Integer[] {2}));
    }
}

