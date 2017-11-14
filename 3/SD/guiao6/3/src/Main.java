import java.io.IOException;

public class Main {
    public static void main(){
        try {
            Client.client();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }
}
