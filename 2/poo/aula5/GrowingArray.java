import java.util.Arrays;
public class GrowingArray{

    private Veiculo[] carros;
    private int size;
    private int capacidade;
    
    public static final int capacidade_inicial = 10;
    
    public GrowingArray(){
        this.size = 0;
        this.carros = new Veiculo[capacidade_inicial];
        this.capacidade = capacidade_inicial;
    }


    public GrowingArray(int capacidade){
        this.size = 0;
        this.carros = new Veiculo[capacidade_inicial];
        this.capacidade = capacidade;
    }

    public GrowingArray(GrowingArray a){
        this.size = a.size;
        this.carros.copyOf(a.carros,capacidade); 
        this.capacidade = a.capacidade;
    }
    public GrowingArray clone(){
        return new GrowingArray(this);
    }
    public boolean equals(Object o){
        if (o == this) return true;
        if (o == null || this.getClass() != o.getClass()) return false;
        else{
            GrowingArray s = (GrowingArray) o;
            boolean flag = true;
            for(Veiculo car : this.carros){
                if (!s.existeVeiculo(car)) flag = false;
            }
            return (flag && this.nomeStand.equals(s.getNomeStand()) && s.getCapacidade() == this.capacidade 
            && s.getNVeiculos() == this.nveiculos);
        }
    }

    public Veiculo remove(int indice){
        if(indice > size)
            return null;
        Veiculo v = carros[indice];
        int d = size -indice -1;
        if(d > 0)
            System.arrayCopy(carros,indice+1,this.carros,indice, (this.size-indice-1));
        this.carros[size]=null;
        return v;
    }
    public Veiculo get (int indice){
        return this.carros[indice].clone;
    }

    public void add(Veiculo v){

    }

    public void add(int indice, Veiculo v){

    }

    public void set(int indice, Veiculo v){

    }

    public Veiculo remove(int indice){

    }

    public boolean remove(Veiculo v){

    }

    public int size(){

    }

    public int indexOF(Veiculo v){

    }

    public boolean contains(Veiculo v){

    }

    public boolean contains(Veiculo v){

    }

    public boolean isEmpty(){

    }
}
