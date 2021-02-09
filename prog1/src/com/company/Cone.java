package com.company;

import java.util.Objects;

public class Cone extends SolidOfRevolution implements HasWeight{
    private double height;
    private double weight;
    private double edgeLength;

    public Cone (double radius, double edgeLength, double weight, double height) {
        super(radius);
        setWeight(weight);
        setEdgeLength(edgeLength);
        setHeight(height);
    }

    public void setHeight(double height) {
        if(height<=0) throw new IllegalArgumentException("height can't be equal or less than 0");
        this.height = height;
    }

    public void setEdgeLength(double edgeLength) {
        if(edgeLength<=0) throw new IllegalArgumentException("length can't be equal or less than 0");
        this.edgeLength = edgeLength;
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
        Cone cone = (Cone) o;
        return Double.compare(cone.edgeLength, edgeLength) == 0 &&
                Double.compare(cone.height, height) == 0 &&
                Double.compare(cone.weight, weight) == 0 &&
                Double.compare(cone.radius, radius) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(radius, edgeLength, weight, height);
    }

    @Override
    public double getSurfaceSquare() {
        return (Math.PI*radius*(radius+edgeLength));
    }

    @Override
    public double getVolume() {
        return (Math.PI*Math.pow(radius,2)*height)/3;
    }

    @Override
    public double getDensity() {return this.weight/(Math.PI*Math.pow(radius,2)*height)/3;}

    @Override
    public void setWeight(double weight) {
        if(weight<1) throw new IllegalArgumentException("weight can't be equal or less than 0");
        this.weight = weight;
    }

    @Override
    public double getWeight() {
        return this.weight;
    }
}
