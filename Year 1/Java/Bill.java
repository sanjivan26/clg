import java.util.Scanner;

public class Bill {
    int consumerNumber;
    String consumerName;
    int previousMonthReading;
    int currentMonthReading;
    String connectionType;

    public Bill(int consumerNumberInput, String consumerNameInput, int previousMonthReadingInput, int currentMonthReadingInput, String connectionTypeInput) {
        this.consumerNumber = consumerNumberInput;
        this.consumerName = consumerNameInput;
        this.previousMonthReading = previousMonthReadingInput;
        this.currentMonthReading = currentMonthReadingInput;
        this.connectionType = connectionTypeInput;
    }

    public int newMonthReading(int readingInput) {
        if (this.currentMonthReading > readingInput) {
            return -1;
        }
        this.previousMonthReading = this.currentMonthReading;
        this.currentMonthReading = readingInput;
        return 1;
    }


    public double calculateAmount() {
        int readingDiff = this.currentMonthReading - this.previousMonthReading;
        if (readingDiff<100) {
            if (this.connectionType.equals("domestic")) {
                return readingDiff;
            }
            else if (this.connectionType.equals("commercial")) {
                return 2*readingDiff;
            }
        }
        else if (readingDiff <200) {
            if (this.connectionType.equals("domestic")) {
                return (100 + (2.5 * (readingDiff - 100)));
            }
            else if (this.connectionType.equals("commercial")) {
                return (200 + (4.5 * (readingDiff - 100)));
            }            
        }
        else if (readingDiff <500) {
            if (this.connectionType.equals("domestic")) {
                return (350 + (4 * (readingDiff - 200)));
            }
            else if (this.connectionType.equals("commercial")) {
                return (650 + (6 * (readingDiff - 200)));
            }            
        }     
        System.out.println(this.connectionType);
        if (this.connectionType.equals("domestic")) {
            return (1550 + (6 * (readingDiff - 500)));
        }
        else if (this.connectionType.equals("commercial")) {
            return (2450 + (7 * (readingDiff - 500)));
        }
        return -1;
    }

    public static void main(String[] args) {
        int state = 0;
        Scanner Scan = new Scanner(System.in);
        System.out.println("Enter Consumer Number");
        int consumerNumberInput = Scan.nextInt();
        Scan.nextLine();
        System.out.println("Enter Consumer Name");
        String consumerNameInput = Scan.nextLine();
        System.out.println("Enter Previous Month Reading");
        int previousMonthReadingInput = Scan.nextInt();
        Scan.nextLine();
        System.out.println("Enter Current Month Reading");
        int currentMonthReadingInput = Scan.nextInt();
        Scan.nextLine();
        System.out.println("Enter Connection Type");
        String connectionTypeInput = Scan.nextLine();
        Bill customer1 = new Bill(consumerNumberInput, consumerNameInput, previousMonthReadingInput, currentMonthReadingInput, connectionTypeInput);
        while (state != 3) {
            System.out.println("Enter 1 to calculate amount, 2 to input month reading, 3 to exit.");
            state = Scan.nextInt();
            if (state == 1) {
                System.out.println("The amount to be paid is "+customer1.calculateAmount());
            }
            else if (state == 2) {
                System.out.println("Enter Current Month Reading");
                customer1.newMonthReading(Scan.nextInt());
            }
            else {
                state = 3;
            }
        }
        Scan.close();
    }
}



