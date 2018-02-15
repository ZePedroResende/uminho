package com.company;

public class InvalidAccount extends Exception {
    InvalidAccount() {
        super("Conta falsa");
    }
}
