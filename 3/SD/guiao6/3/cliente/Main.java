import java.io.IOException;
public class Main {

    public static void main(String[] args) {
        // write your code here
        try {
            Client.client();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

