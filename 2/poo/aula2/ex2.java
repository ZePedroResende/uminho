import java.util.Arrays;
import java.util.Scanner;

/**
 * Write a description of class ex2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class ex2
{
    public static void main(String[] argv)
    {
        int teste[] = lerArrayInt(10);
        int minimo = minPos(teste);
    }

   private static int[] lerArrayInt(int n)
   {
        int teste[] = new int[n];
        Scanner novo = new Scanner(System.in);
        for(int i = 0; i< teste.length; i++)
            teste[i] = novo.nextInt();
        return teste;
   }

    private  static int minPos(int [] arr)
    {
       int min = arr[0];
       for(int i = 0; i < arr.length ; i++){
          if (min > arr[i]) min = arr[i]; 
       }

       return  min;
    }
}
