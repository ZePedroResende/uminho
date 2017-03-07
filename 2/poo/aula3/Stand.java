/**
 * Classe que representa um Stand de automóveis
 * 
 * @author anr
 * @version 2014.03.16  
 * @version 2017.03.03
 */

public class Stand {
  //variáveis de instância
  private String nomeStand;
  private Veiculo[] carros;
  private int nveiculos;   //número veículos no stand
  
  //capacidade do stand (em número de veículos)
  private int capacidade;
  
  //capacidade inicial do Stand: valor por omissão
  public static final int capacidade_inicial = 10;
  
  public Veiculo[] getCarros(){ 
      Veiculo[] r = new Veiculo[nveiculos];
      int i=0;
      for(Veiculo c: carros){
          if(c != null){ 
            r[i++]=c.clone();
          
          }
      }
      return r ; 
  }


  //construtores
  public Stand() {
      this.nomeStand = new String();
      this.carros = new Veiculo[capacidade_inicial];
      this.capacidade = capacidade_inicial;
      this.nveiculos = 0;
  }

  public Stand(String nome, int capacidade) {
      this.nomeStand = nome;
      this.carros = new Veiculo[capacidade];
      this.capacidade = capacidade;
      this.nveiculos = 0;
  }

  public Stand(Stand umStand) {
      this.nomeStand  = umStand.getNomeStand();
      this.carros     = umStand.getCarros();
      this.capacidade = umStand.getCapacidade();
      this.nveiculos  = umStand.getNVeiculos();
  }

  //métodos de instância

  //gets e sets: fazer!

  //outros métodos

  /**
   * Método que insere um veículo no stand
   * 
   */
  public void insereVeiculo(Veiculo v) {
    if (nveiculos<capacidade){
    carros[nveiculos]= v.clone();
    nveiculo++;
    }
}


  /**
   * Método que verifica se um determinado veículo está no
   * stand.
   */
  public boolean existeVeiculo(Veiculo v) {
    
    for (int i=0; i<nveiculos; i++){
        
        if (carros[i]==v) return true;    
    }

    return false;
}

  /**
   * Método que verifica se um veículo, cuja matrícula é conhecida, 
   * está no stand.
   */
  public boolean existeVeiculoPorMatricula(String matricula) {
    
    for (int i=0; i<nveiculos; i++){
        
        if (carros[i].matricula==matricula) return true;    
    }

    return false;
    
    
    }


  /** 
   * Método que devolve o veículo com mais kms.
   * 
   */
  public Veiculo veiculoComMaisKms() {
    
   int max=0;
   for (int i=0; i<nveiculos; i++){
        
        if (carros[i].kmsTotal>max) max=carros[i]-getkmsTotal;    
    }
    return max;    
    }

  /**
   * Método que devolve o veículo mais gastador (em termos de
   * combustível).
   */
  public Veiculo veiculoMaisGastador() {
    
    
    
    
    
    }

  /**
   * Método que determina o número de kms de todos os veículos
   * da garagem.
   * 
   */
  public double totalKmsTodosVeiculos() {}


  /**
   * equals
   * 
   */
 
  public boolean equals(Object o){
      if(!this.getClass().equals( o.getClass() ))
          return false;
      Stand s =(Stand) o;
      if(nomeStand != this.nomeStand)
          return false;
      if(nveiculos != s.nveiculos)
          return false;
      for(int i = 0; i < nveiculos;i++){
          if(!s.existeVeiculo(carros[i]))
              return false;
      }
      return true;
  }
  /**
   * toString
   */

  public String toString() {
      String r = new String("Stand:" + nomeStand + "com" + nveiculos + "viaturas");
      for(int i=0; i < nveiculos; i++){
          r = r.concat(carros[i].toString()+"\n");
      }
      return r;
  }

  public Stand clone() {}
}
