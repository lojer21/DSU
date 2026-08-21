import java.util.Scanner;

public class EvenOddTernary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input from user
        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        // Ternary operator check
        String result = (num % 2 == 0) ? "Even" : "Odd";

        // Output
        System.out.println("The number is: " + result);
    }
}
