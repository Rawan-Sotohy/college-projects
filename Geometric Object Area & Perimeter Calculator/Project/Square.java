
public class Square extends Rectangle {

    public Square() {
        super();
    }

    public Square(double side) {
        super(side, side);
    }

    public Square(String color, boolean filled, double side) {
        super(side, side, color, filled);
    }

    public void setSide(double side) {
        this.len = side;
        this.wid = side;
    }

    public double getside() {
        return this.len;
    }

    public void setLen(double side) {
        this.len = side;
    }

    public void setWid(double side) {
        this.wid = side;
    }

}

