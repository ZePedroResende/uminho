package com.company;

import java.io.IOException;

public class Main {

    public static void main(String[] args) {
	// write your code here
        try {
            Servidor.servidor();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
