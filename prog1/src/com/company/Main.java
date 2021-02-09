package com.company;

import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        AddShapeSubscriber shapeSubscriber;
        shapeSubscriber=(Shape shp_1)->System.out.println("AddShapeSubscriber: " + shp_1.toString());
        DeleteShapeSubscriber delShapeSubscriber;
        delShapeSubscriber=(Shape shp_1)->System.out.println("DeleteShapeSubscriber: " + shp_1.toString());

        Random rand=new Random();
        Double maxWei=1+rand.nextDouble();
        List<Shape> shapes=new Vector<>();
        Space spaces=Space.getSpaceInstance(new ArrayList<>(),maxWei);

        ShapeProducer producer =new ShapeProducer(spaces);
        ShapeConsumer consumer =new ShapeConsumer(spaces);

        spaces.setAddShapeSubscribers(shapeSubscriber);
        spaces.setDeleteShapeSubscribers(delShapeSubscriber);

        producer.start();
        consumer.start();
    }
}
