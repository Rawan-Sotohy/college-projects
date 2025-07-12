public class Circle extends GeometricObject{
protected double radius;
public Circle() {
     super ();
     this.radius = 0.0;
 }
 public Circle(double radius) { 
     super();
     this.radius = radius; 
 }
 public Circle(double radius, String color, boolean filled)
 { 
     super(color, filled); 
     this.radius = radius;
 }
 public double getRadius() {
     return radius;
 }
 public void setRadius(double radius) { 
     this.radius = radius;
 }
 public double getArea() { 
     return Math.PI * Math.pow(this.radius, 2);
 }
 public double getperimeter() {
     return 2 * Math.PI * this.radius; 
 }
 }