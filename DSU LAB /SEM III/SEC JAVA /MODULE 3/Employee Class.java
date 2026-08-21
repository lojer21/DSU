class Employee {
    private int salary;
    private String name;

    public Employee(int salary, String name) {
        this.salary = salary;
        this.name = name;
    }

    public int getSalary() {
        return salary;
    }

    public String getName() {
        return name;
    }

    public void setName(String newName) {
        name = newName;
    }
}

public class Main {
    public static void main(String[] args) {
        Employee emp = new Employee(50000, "John");

        System.out.println("Name: " + emp.getName());
        System.out.println("Salary: " + emp.getSalary());

        emp.setName("David");
        System.out.println("Updated Name: " + emp.getName());
    }
}
