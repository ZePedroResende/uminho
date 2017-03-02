import java.util.Scanner;
/**
 * Write a description of class Veiculo here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Veiculo
{
    // instance variables - replace the example below with your own
    private String matricula;
    private double kmsTotal;
    private double kmsParcial;
    private double consumoMedio;
    private int capacidade; 
    private int conteudo;


    public String getmatricula(){
        return matricula;
    }
    public void setmatricula(String matricula){
        this.matricula = matricula;
    }


    public double getKmsTotal(){
        return kmsTotal;
    }
    public void setKmsTotal( double kmsTotal){
        this.kmsTotal = kmsTotal;
    }

    public double getKmsParcial(){
        return kmsParcial;
    }
    public void setKmsParcial(double kmsParcial){
        this.kmsParcial = kmsParcial;
    }

    public double getConsumoMedio(){
        return consumoMedio;
    }
    public void setConsumoMedio(double consumoMedio){
        this.consumoMedio = consumoMedio;
    }

    public int getCapacidade(){
        return capacidade;
    }
    public void setCapacidade(int capacidade){
        this.capacidade = capacidade;
    }

    public int getConteudo(){
        return conteudo;
    }
    public void setConteudo(int conteudo){
        this.conteudo = conteudo;
    }

    public void abastecer(int litros){
        this.conteudo = this.conteudo + litros;
        if(this.conteudo > this.capacidade) this.conteudo = this.capacidade;
    }

    public void resetKms(){
        this.kmsParcial = 0;
        this.consumoMedio = 0;
    }

    public double autonomia(){
        return (this.conteudo/this.consumoMedio)*100;
    }

    public void registarViagens(int kms, double consumo){
        this.consumoMedio = consumo*100/kms;
        this.kmsTotal += kms;
        this.kmsParcial += kms;
        this.conteudo-=consumo;
    }

    public boolean naReserva(){
        return (this.conteudo <= 10);
    }

    public double totalCombustivel(double custoLitro){
        return this.conteudo*custoLitro;
    }

    public double custoMedioKms(double custoLitro){
        return (this.consumoMedio*custoLitro)/100;
    }
}
