package com.company;

import java.util.Objects;

public class Cylinder extends SolidOfRevolution implements HasWeight{
    private double height;
    private double weight;

    public Cylinder(double radius, double weight, double height){
        super(radius);
        setWeight(weight);
        setHeight(height);
    }

    public void setHeight(double height) {
        if(height<=0) throw new IllegalArgumentException("height can't be equal or less than 0");
        this.height = height;
    }

    public double getHeight() {
        return this.height;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Cylinder cylinder = (Cylinder) o;
        return Double.compare(cylinder.height, height) == 0 &&
                Double.compare(cylinder.weight, weight) == 0 &&
                Double.compare(cylinder.radius, radius) == 0;
    }

    @Override
    public int hashCode() { return Objects.hash(radius, weight, height); }

    @Override
    public double getVolume() {
        return (Math.PI*Math.pow(radius,2)*height);
    }

    @Override
    public double getSurfaceSquare() {
        return (2*Math.PI*Math.pow(radius, 2)+2*Math.PI*radius*height);
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
    public double getDensity() {return this.weight/(Math.PI*Math.pow(radius,2)*height);}
}