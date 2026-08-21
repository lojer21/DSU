class BankAccount {
    private double balance;

    // Deposit cash
    void deposit(double amount) {
        balance += amount;
        System.out.println("Cash deposited: ₹" + amount);
    }

    // Deposit by cheque
    void deposit(double amount, String chequeNumber) {
        balance += amount;
        System.out.println("Cheque deposited: ₹" + amount + " | Cheque No: " + chequeNumber);
    }

    // Deposit online (UPI or NEFT)
    void deposit(double amount, String upiId, boolean isOnline) {
        balance += amount;
        System.out.println("Online deposit: ₹" + amount + " | UPI/NEFT ID: " + upiId);
    }

    void showBalance() {
        System.out.println("Current Balance: ₹" + balance);
    }
}

public class Main {
    public static void main(String[] args) {
        BankAccount acc = new BankAccount();

        acc.deposit(1000);                              // Cash
        acc.deposit(5000, "CHQ12345");                 // Cheque
        acc.deposit(2500, "giri@upi", true);           // Online

        acc.showBalance();
    }
}
