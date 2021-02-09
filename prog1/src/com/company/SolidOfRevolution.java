package com.company;

public abstract class SolidOfRevolution extends Shape{
    protected double radius;
    protected SolidOfRevolution(double radius){
        setRadius(radius);
    }

    public double getRadius() {
        return this.radius;
    }

    public void setRadius(double radius) {
        if(radius<=0) throw new IllegalArgumentException("radius can't be equal or less than 0");
        this.radius = radius;
    }
}
