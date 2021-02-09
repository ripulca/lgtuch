package com.company;

import java.util.Random;

public class ShapeProducer extends Thread {
    private static Random rand = new Random();
    private final Space space;

    public ShapeProducer(Space spaces) {
        this.space = spaces;
    }

    private double randDouble(){ return rand.nextDouble()*1000 + 1; }

    private double randDouble(double max) {
        return ((double)rand.nextInt((int)max-1)) + rand.nextDouble();
    }

    private Shape createShape() {
        int shapeType = 1 + rand.nextInt(4);
        Shape figure = null;
        switch (shapeType) {
            case Space.CUBE_ID:
                figure = new Cube(randDouble(), randDouble(space.getMaxTotalWeight()));
                break;
            case Space.TRIANGULAR_PYRAMID_ID:
                figure = new TriangularPyramid(randDouble(), randDouble(), randDouble(space.getMaxTotalWeight()));
                break;
            case Space.CYLINDER_ID:
                figure = new Cylinder(randDouble(), randDouble(space.getMaxTotalWeight()), randDouble());
                break;
            case Space.CONE_ID:
                figure = new Cone(randDouble(), randDouble(), randDouble(space.getMaxTotalWeight()), randDouble());
                break;
            default:
                System.out.println("press F to pay respect figure");
        }
        return figure;
    }

    public void run() {
        while (true) {
            Random rand = new Random();
            try {
                long sleepTime = 1000 + rand.nextInt(9000);
                Thread.sleep(sleepTime);
                System.out.println("ShapeProducer have been sleeping for " + sleepTime + "ms");
                Shape figure = createShape();
                synchronized (space) {
                    while (!space.add(figure)) {
                        System.out.println("Start waiting");
                        space.wait();
                    }
                    System.out.println("ShapeProducer have added new figure/ New total weight " + space.getTotalWeight());
                    space.notifyAll();
                }
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
