//Books_class
class Book {
    String title;
    String author;
    double price;

    // Default constructor
    Book() {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
    }

    // Constructor with title and author
    Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.price = 0.0;
    }

    // Constructor with all fields
    Book(String title, String author, double price) {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    void printDetails() {
        System.out.println("Title: " + title + ", Author: " + author + ", Price: " + price);
    }
}

public class Main {
    public static void main(String[] args) {

        // 3 books
        Book b1 = new Book("This Thing Called Love", "Deblina Bhattacharya", 299.00);
        Book b2 = new Book("The Psychology of Money", "Morgan Housel", 399.00);
        Book b3 = new Book("The Alchemist", "Paulo Coelho", 350.00);

        b1.printDetails();
        b2.printDetails();
        b3.printDetails();
    }
}
