
public class Rectangle extends GeometricObject{
protected double len , wid;
    public Rectangle() {
        super();
        len= 0.0;
        wid= 0.0;
    }

    
    public Rectangle(double len, double wid) {
         super();
        this.len = len;
        this.wid = wid;

}

    public Rectangle(double len, double wid, String color, boolean filled) {
        super(color, filled);
        this.len = len;
        this.wid = wid;
    }

    public double getLen() {
        return len;
    }

    public void setLen(double len) {
        this.len = len;
    }

    public double getWid() {
        return wid;
    }

    public void setWid(double wid) {
        this.wid = wid;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }
    
 public double getArea() { 
     return this.len * this.wid; 
 }
 public double getperimeter() { 
     return 2*(this.len + this.wid); 
 }
   
    
    
}

