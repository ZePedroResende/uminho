import java.util.Arrays;
import java.util.Scanner;
/**
 * Write a description of class ex7 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ex7
{
    public static void main(String [] argv)
    {
        int vencimentos [] = new int [20];
    
        int cargos [] = new int [20];

        double tabela [] = new double [4];
        tabela[0] = 1.05;
        tabela[1] = 1.10;
        tabela[2] = 1.20;
        tabela[3] = 1.30;
        
        double total [] = new double[20];

        System.out.println("digite os vencimentos separados por espaços !");
        
        Scanner ven = new Scanner(System.in); 
        for(int i = 0; i<vencimentos.length ; i++){
            System.out.println("Digite vencimento");

            vencimentos[i] = ven.nextInt();
        }
    

        System.out.println("Digite os cargos");
        System.out.println("0 -> Developer");
        System.out.println("1 -> Gestor");
        System.out.println("2 -> Administrador");
        System.out.println("3 -> CEO");
        Scanner carg = new Scanner(System.in); 
        for(int i = 0; i<cargos.length ; i++){
            System.out.println("Cargos");
            cargos[i] = carg.nextInt();
        }
    

       for(int i = 0; i<total.length ; i++){
           total[i] = vencimentos[i] * tabela[cargos[i]];
       }

       System.out.println(Arrays.toString(total)) ;

    }
}
