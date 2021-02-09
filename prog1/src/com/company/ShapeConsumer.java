package com.company;

import java.util.ArrayList;
import java.util.Random;

public class ShapeConsumer extends Thread {
    private final Space space;

    public ShapeConsumer(Space spaces) {
        this.space = spaces;
    }

    @Override
    public void run() {
        while (true) {
            try{
            Random rand = new Random();
                long sleepTime = 1000 + rand.nextInt(9000);
                Thread.sleep(sleepTime);
                synchronized (space) {
                    while (this.space.getShapes().isEmpty()) {
                        System.out.println("Start waiting");
                        space.wait();
                    }
                    ArrayList<Shape> tmp = (ArrayList<Shape>) space.getShapes();
                    Shape removeInd = tmp.get(rand.nextInt(tmp.size()));
                    tmp.remove(removeInd);
                    System.out.println("ShapeConsumer deleted figure/ New total weight " + space.getTotalWeight());
                    space.notifyAll();
                }
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }
}
