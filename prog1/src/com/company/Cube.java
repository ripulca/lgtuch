package com.company;

import java.util.Objects;

public class Cube  extends Shape implements HasWeight{
    private double edgeLength;
    private double weight;

    public Cube(double edgeLength, double weight){
        setWeight(weight);
        setEdgeLength(edgeLength);
    }

    public void setEdgeLength(double edgeLength) {
        if(edgeLength<=0) throw new IllegalArgumentException("length can't be equal or less than 0");
        this.edgeLength = edgeLength;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Cube cube = (Cube) o;
        return Double.compare(cube.edgeLength, edgeLength) == 0 &&
                Double.compare(cube.weight, weight) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(edgeLength, weight);
    }

    @Override
    public void setWeight(double weight) {
        if(weight<=0) throw new IllegalArgumentException("weight can't be equal or less than 0");
        this.weight = weight;
    }

    public double getEdgeLength() {
        return this.edgeLength;
    }

    @Override
    public double getSurfaceSquare() { return (6*Math.pow(edgeLength, 2)); }

    @Override
    public double getVolume() {
        return Math.pow(edgeLength, 3);
    }

    @Override
    public double getWeight() {
        return this.weight;
    }

    @Override
    public double getDensity() {return this.weight/Math.pow(edgeLength, 3);}
}
