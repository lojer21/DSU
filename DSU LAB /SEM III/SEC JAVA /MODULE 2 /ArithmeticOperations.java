import java.util.Scanner;

public class ArithmeticOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input from user
        System.out.print("Enter first integer: ");
        int a = sc.nextInt();

        System.out.print("Enter second integer: ");
        int b = sc.nextInt();

        // Performing operations
        int sum = a + b;
        int diff = a - b;
        int prod = a * b;
        int quotient = a / b;      // assumes b != 0
        int remainder = a % b;

        // Displaying results
        System.out.println("\n--- Arithmetic Results ---");
        System.out.println("Sum: " + sum);
        System.out.println("Difference: " + diff);
        System.out.println("Product: " + prod);
        System.out.println("Quotient: " + quotient);
        System.out.println("Remainder: " + remainder);
    }
}
