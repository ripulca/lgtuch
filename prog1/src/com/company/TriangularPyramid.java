package com.company;

import java.util.Objects;

public class TriangularPyramid  extends Shape implements HasWeight{
    private double edgeLength;
    private double height;
    private double weight;

    public TriangularPyramid (double edgeLength, double height, double weight) {
        setWeight(weight);
        setEdgeLength(edgeLength);
        setHeight(height);
    }

    public void setEdgeLength(double edgeLength) {
        if(edgeLength<=0) throw new IllegalArgumentException("length can't be equal or less than 0");
        this.edgeLength = edgeLength;
    }

    public void setHeight(double height) {
        if(height<=0) throw new IllegalArgumentException("height can't be equal or less than 0");
        this.height = height;
    }

    public double getHeight() {
        return this.height;
    }

    public double getEdgeLength() {
        return this.edgeLength;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TriangularPyramid pyramid = (TriangularPyramid) o;
        return Double.compare(pyramid.edgeLength, edgeLength) == 0 &&
                Double.compare(pyramid.height, height) == 0 &&
                Double.compare(pyramid.weight, weight) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(edgeLength, height, weight);
    }

    @Override
    public double getSurfaceSquare() {
        return (Math.pow(edgeLength, 2) * Math.pow(3, 0.5));
    }

    @Override
    public double getVolume() {
        return (Math.pow(edgeLength, 2) * Math.pow(2, 0.5)/ 12);
    }

    @Override
    public void setWeight(double weight) {
        if(weight<=0) throw new IllegalArgumentException("weight can't be equal or less than 0");
        this.weight = weight;
    }

    @Override
    public double getWeight() {
        return this.weight;
    }

    @Override
    public double getDensity() {return this.weight/(Math.pow(edgeLength, 2) * Math.pow(2, 0.5)/ 12);}
}
