package com.company;

import java.io.*;
import java.util.Collection;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Space {
    private final Collection<Shape> shapes;
    private static Space spaceInstance=null;
    public double maxTotalWeight;
    public static final int CUBE_ID =1;
    public static final int TRIANGULAR_PYRAMID_ID=2;
    public static final int CYLINDER_ID=3;
    public static final int CONE_ID=4;

    public Space(List<Shape> shapes,double maxTotalWeight){
        this.shapes=shapes;
        setMaxTotalWeight(maxTotalWeight);
    }

    public static synchronized Space getSpaceInstance(List<Shape> shapes,double maxTotalWeight){
        if(spaceInstance==null) spaceInstance= new Space(shapes, maxTotalWeight);
        return spaceInstance;
    }

    private final LinkedList<AddShapeSubscriber> addShapeSubscribers = new LinkedList<>();

    private final LinkedList<DeleteShapeSubscriber> deleteShapeSubscribers = new LinkedList<>();

    public void setAddShapeSubscribers(AddShapeSubscriber subscriber) {
        addShapeSubscribers.add(subscriber);
    }

    public void setDeleteShapeSubscribers(DeleteShapeSubscriber subscriber) {
        deleteShapeSubscribers.add(subscriber);
    }

    public void setMaxTotalWeight(double maxTotalWeight){
        if(maxTotalWeight<=0) throw new IllegalArgumentException("maxTotalWeight can't be equal or less than 0");
        this.maxTotalWeight=maxTotalWeight;
    }

    public Collection<Shape> getShapes() {
        return shapes;
    }

    public boolean add(Shape shp) {
        if(!shapes.add((Shape) shp))  return false;
        for (AddShapeSubscriber subscriber : addShapeSubscribers) {
            subscriber.onSubscribe(((Shape)shp));;
        }
        return true;
    }

    public boolean delete(Shape shp) throws IllegalAccessException {
        if(shapes.remove(shp)) return  false;
        for (DeleteShapeSubscriber subscriber : deleteShapeSubscribers) {
            subscriber.onSubscribe(shp);
        }
        return true;
    }

    public double getMaxTotalWeight() { return this.maxTotalWeight; }

    public double getTotalWeight() {
        return shapes.stream().mapToDouble(shapes->((HasWeight)shapes).getWeight()).sum();
    }

    public double getTotalVolume() {
        return shapes.stream().mapToDouble(Shape::getVolume).sum();
    }

    public double getTotalSurfaceSquare() {
        return shapes.stream().mapToDouble(Shape::getSurfaceSquare).sum();
    }

    public void scaleShapes(double scale) {
        for (Shape s : this.shapes)
            if (s instanceof Cube) {
                Cube cube = (Cube) s;
                cube.setEdgeLength(cube.getEdgeLength() * scale);
            } else if (s instanceof TriangularPyramid) {
                TriangularPyramid pyramid = (TriangularPyramid) s;
                pyramid.setEdgeLength(pyramid.getEdgeLength() * scale);
                pyramid.setHeight(pyramid.getHeight() * scale);
            } else if (s instanceof Cylinder) {
                Cylinder cylinder = (Cylinder) s;
                cylinder.setRadius(cylinder.getRadius() * scale);
                cylinder.setHeight(cylinder.getHeight() * scale);
            } else if (s instanceof Cone) {
                Cone cone = (Cone) s;
                cone.setHeight(cone.getHeight() * scale);
                cone.setRadius(cone.getRadius() * scale);
                cone.setEdgeLength(cone.getEdgeLength() * scale);
            }
    }

    public Collection<Shape> filterBy(Predicate<Shape> shapePredicate) {
        return this.shapes.stream().filter(shapePredicate).collect(Collectors.toList());
    }

    public Collection<Shape> sortedBy(Comparator<Shape> shapeComparator) {
        return this.shapes.stream().sorted(shapeComparator).collect(Collectors.toList());
    }

    public void saveShapesToFile(String fileName) throws IOException {
        DataOutputStream out = new DataOutputStream(new FileOutputStream(fileName));
        for (Shape s : this.shapes)
            if (s instanceof Cube) {
                Cube cube = (Cube) s;
                out.writeInt(CUBE_ID);
                out.writeDouble(cube.getEdgeLength());
                out.writeDouble(cube.getWeight());
            } else if (s instanceof TriangularPyramid) {
                TriangularPyramid pyramid = (TriangularPyramid) s;
                out.writeInt(TRIANGULAR_PYRAMID_ID);
                out.writeDouble(pyramid.getEdgeLength());
                out.writeDouble(pyramid.getHeight());
                out.writeDouble(pyramid.getWeight());
            } else if (s instanceof Cylinder) {
                Cylinder cylinder = (Cylinder) s;
                out.writeInt(CYLINDER_ID);
                out.writeDouble(cylinder.getHeight());
                out.writeDouble(cylinder.getRadius());
                out.writeDouble(cylinder.getWeight());
            } else if (s instanceof Cone) {
                Cone cone = (Cone) s;
                out.writeInt(CONE_ID);
                out.writeDouble(cone.getEdgeLength());
                out.writeDouble(cone.getHeight());
                out.writeDouble(cone.getRadius());
                out.writeDouble(cone.getWeight());
            }
    }

    public void loadShapesFromFile(String fileName) {
        try (
            DataInputStream in = new DataInputStream(new FileInputStream(fileName))) {
            Shape shape = null;
            double edgeLength, height, radius, weight;
            while (in.available() > 0) {
                int num = in.readInt();
                switch (num) {
                    case CUBE_ID:
                        edgeLength = in.readDouble();
                        weight = in.readDouble();
                        shape = new Cube(edgeLength, weight);
                        break;
                    case TRIANGULAR_PYRAMID_ID:
                        edgeLength = in.readDouble();
                        height = in.readDouble();
                        weight = in.readDouble();
                        shape = new TriangularPyramid(edgeLength, height, weight);
                        break;
                    case CYLINDER_ID:
                        height = in.readDouble();
                        radius = in.readDouble();
                        weight = in.readDouble();
                        shape = new Cylinder(radius, weight, height);
                        break;
                    case CONE_ID:
                        edgeLength = in.readDouble();
                        height = in.readDouble();
                        radius = in.readDouble();
                        weight = in.readDouble();
                        shape = new Cone(radius, edgeLength, weight, height);
                        break;
                    default:
                }
                this.shapes.add(shape);
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}