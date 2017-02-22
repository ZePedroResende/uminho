import java.util.Scanner;
class exe8{
    
    public static void main(String[] argv){
        Scanner diaScanner = new Scanner(System.in);
        int dia = diaScanner.nextInt();
        int mes = diaScanner.nextInt();
        int ano = diaScanner.nextInt();
        int resultado = (ano -1900) * 365;
        
        resultado += (ano-1900)/4;
        if( bissexto(ano) && (mes == 1 || mes == 2)){
            ano -- ;
        }
        ano = ano%7;
        System.out.println(ano);
    }
    
    public static boolean bissexto(int year){
    return ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0));
    }
}

