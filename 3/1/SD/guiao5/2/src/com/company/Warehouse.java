package com.company;

import java.util.HashMap;

public class Warehouse {
    private HashMap<String,Item> warehouse;

    public Warehouse() {
       warehouse = new HashMap<>();
    }

    public void supply(String item, int quantity){
        if(warehouse.containsKey(item)){
            Item tmp = warehouse.get(item);
            tmp.supply(quantity);
            warehouse.put(item,tmp);
        }
        else{
            Item tmp = new Item();
            tmp.supply(quantity);
            warehouse.put(item,tmp);
        }

    }

    public int getStock(String item) {
        Item it = warehouse.get(item);
        return it.getQuantify();
    }

    public void consume(String[] item) throws InterruptedException {
        for(String s : item){
            Item tmp = warehouse.get(s);
            tmp.consume();
            warehouse.put(s,tmp);
        }
    }
}
