class Cylinder {
    private double radius;
    private double height;

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getRadius() {
        return radius;
    }

    public double getHeight() {
        return height;
    }
}

public class Main {
    public static void main(String[] args) {
        Cylinder c = new Cylinder();

        c.setRadius(5.0);
        c.setHeight(10.0);

        System.out.println("Radius: " + c.getRadius());
        System.out.println("Height: " + c.getHeight());
    }
}
