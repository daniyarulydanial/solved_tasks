//Lab3

//Checking for existence of such triangle:
package com.company;
import java.util.Scanner;
public class Test {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a: ");
        int a = input.nextInt();
        System.out.print("Enter b: ");
        int b = input.nextInt();
        System.out.print("Enter c: ");
        int c = input.nextInt();
        if (a < (b + c) && b < (a + c) && c < (a + b)) {
            System.out.print("Triangle exists");
        }
        else {
            System.out.print("Triangle not exist");
        }
    }
}

//Defining a leap year:
package com.company;
import java.util.Scanner;
import java.time.LocalDate;
import java.util.ArrayList;

public class LeapYear {
    public static void main(String[] args) {
        LocalDate thisDate = LocalDate.now();
        int thisYear = thisDate.getYear();

        Scanner input = new Scanner(System.in);
        System.out.print("Input date: ");
        String date = input.next();
        try {
            int newDate = Integer.parseInt(date);
            if (newDate < 0) throw new Exception("A year cannot have a negative value");
            System.out.println("Valid entry");
            System.out.println(CheckForLeapYear(newDate) ? (newDate + " is a leap year") : (newDate + " not a leap year"));
        } catch (NumberFormatException e) {
            System.out.println(date + " is not valid entry. Please enter non-negative integer");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        ArrayList<Integer> leapYears = new ArrayList<>();
        for (int i = 1885; i <= thisYear; i++) {
            if (CheckForLeapYear(i)) {
                leapYears.add(i);
            }
        }

        System.out.print("Leap years from 1885 to this year(" + thisYear + "):");
        for (int year: leapYears) {
            System.out.print(" " + year + ";");
        }

        input.close();
    }
    public static boolean CheckForLeapYear(int year) {
        return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
    }
}

//Lab4.1

package com.company;
import java.time.DateTimeException;
import java.util.Scanner;
import java.time.LocalDate;

public class Test1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[][] categories = new String[4][2];
        System.out.print("Введите четыре возрастные категории через Enter: ");
        for (int i = 0; i < categories.length; i++) {
            for (int j = 0; j < 1; j++) {
                categories[i][j] = input.next();
            }
        }

        System.out.print("Введите характерную черту возрастной категории через Enter: ");
        for (int i = 0; i < categories.length; i++) {
            for (int j = 1; j < 2; j++) {
                categories[i][j] = input.next();
            }
        }

        LocalDate today = LocalDate.now();
        System.out.print("Введите вашу дату рождения(день-месяц-год): ");
        try {
            String birthDate = input.next();
            if (!birthDate.matches("(0?[1-9]|[12][0-9]|3[01])[- /.](0?[1-9]|1[012])[- /.](19|20)\\d\\d"))
                throw new Exception("К сожалению вы ввели дату не правильно. Пожайлуста следуйте шаблону: " +
                        "ДД.ММ.ГГГГ или ДД/ММ/ГГГГ или ДД-ММ-ГГГГ. Год должен быть выше 1899.");

            String[] dateOfBirth = birthDate.split("[.\\-/]");
            int year = Integer.parseInt(dateOfBirth[2]);
            int month = Integer.parseInt(dateOfBirth[1]);
            int day = Integer.parseInt(dateOfBirth[0]);
            LocalDate _birthDate = LocalDate.of(year, month, day);


            int age = today.getYear() - year;
            if (today.getMonthValue() < month || (today.getMonthValue() == month && today.getDayOfMonth() < day)) {
                age--;
            }

            boolean flag = false;
            for (String[] category : categories) {
                for (int j = 0; j < 1; j++) {
                    String[] range = category[j].split("-");
                    if (Integer.parseInt(range[0]) <= age && age <= Integer.parseInt(range[1])) {
                        System.out.println("Вы являетесь: " + category[1]);
                        flag = true;
                        break;
                    }
                }
            }

            if (!flag) {
                System.out.println("К сожалению вы не входите ни в одну категорию");
            }

        }
        catch (DateTimeException e) {
            System.out.println("Введенный день должен совпадать с допустимым количеством дней введенного месяца");
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }

}

//Lab4.2

package com.company;
import java.time.DateTimeException;
import java.util.Scanner;
import java.time.LocalDate;

public class Harvard {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        LocalDate today = LocalDate.now();
        System.out.print("Hello this is a validation form for students who would like to know if they can apply to Harvard.\n" +
                "First of all, enter your birth date (DD.MM.YYYY): ");

        int age = 0;
        try {
            String birthDate = input.next();
            if (!birthDate.matches("(0?[1-9]|[12][0-9]|3[01])[- /.](0?[1-9]|1[012])[- /.](19|20)\\d\\d"))
                throw new Exception("Unfortunately you entered date incorrectly. Please follow the pattern: " +
                        "DD.MM.YYYY or DD/MM/YYYY or DD-MM-YYYY. Year should be higher than 1899.");

            String[] dateOfBirth = birthDate.split("[.\\-/]");
            int year = Integer.parseInt(dateOfBirth[2]);
            int month = Integer.parseInt(dateOfBirth[1]);
            int day = Integer.parseInt(dateOfBirth[0]);
            LocalDate _birthDate = LocalDate.of(year, month, day);

            age = today.getYear() - year;
            if (today.getMonthValue() < month || (today.getMonthValue() == month && today.getDayOfMonth() < day)) {
                age--;
            }

        } catch (DateTimeException e) {
            System.out.println("Введенный день должен совпадать с допустимым количеством дней введенного месяца");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        if (check(age)) {
            System.out.println("You can apply to the Harvard. \n" +
                    "Would you like to choose bachelor`s or master`s degree? (B/M)");
            String certificate = input.next();

            if (certificate.equals("B")) {
                System.out.println("Can you provide a certification of graduation? (Y/N)");
                String ans = input.next();

                if (check(ans)) {
                    System.out.println("Please enter your gpa (max is 5.0): ");
                    double gpa = input.nextDouble();

                    if (check(certificate, gpa))
                        System.out.println("You can apply to the grant to the bachelor`s degree");
                    else
                        System.out.println("You can only apply for paid university tuition to the bachelor`s degree");
                }
                else System.out.println("Unfortunately you cannot apply to the bachelor`s degree without certificate about your graduation.");
            }
            else if (certificate.equals("M")) {
                if (age >= 22) {
                    System.out.println("Can you provide a bachelor's degree? (Y/N)");
                    String ans = input.next();

                    if (check(ans)) {
                        System.out.println("Please enter your gpa (max is 4.0): ");
                        double gpa = input.nextDouble();

                        if (check(certificate, gpa))
                            System.out.println("You can apply to the grant to the master`s degree");
                        else
                            System.out.println("You can only apply for paid university tuition to the master`s degree");
                    }
                    else System.out.println("Unfortunately you cannot apply to the master`s degree without bachelor`s degree.");
                }
                else System.out.println("Unfortunately you cannot apply to the master`s degree because you are younger than 22.");
            }
        }
        else System.out.println("Unfortunately you are not in the appropriate age category.");
    }

    public static boolean check(int age) {
        return 16 <= age && age <= 35;
    }

    public static boolean check(String ans) {
        return ans.equals("Y");
    }

    public static boolean check(String certificate, double gpa) {
        if (certificate.equals("B")) {
            return gpa >= 4.5;
        }
        return gpa >= 3.4;
    }
}

//Lab5

package com.Danik;
import Loan.NationalBank;
import Loan.SecondTierBank;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter how much money you want to invest: ");
        double money = input.nextDouble();
        System.out.println("Enter for how many months you want to open a deposit: ");
        int duration = input.nextInt();
        System.out.println("Enter which type of client you are (individual or legalEntity): ");
        String type_of_client = input.next();

        System.out.println("Which bank would you want to chose? (1: National bank; 2: Second tier bank) ");
        int bank = input.nextInt();
        switch (bank) {
            case 1 -> {
                NationalBank nb = new NationalBank();
                System.out.println(nb.calculateDeposit(money, duration, type_of_client));
            }
            case 2 -> {
                SecondTierBank sb = new SecondTierBank();
                System.out.println(sb.calculateDeposit(money, duration, type_of_client));
            }
        }
    }
}



package Loan;

public class NationalBank {
    private final double FIXEDBANKREWARD = 0.01;
    private Calculator calculator;

    public NationalBank(){
        this.calculator = new Calculator();
    }

    public double calculateDeposit(double money, int duration, String type_of_client){
        return calculator.depositReward(money, duration, type_of_client) * FIXEDBANKREWARD;
    }
}



package Loan;

public class SecondTierBank {
    private final double FIXEDBANKREWARD = 0.02;
    private Calculator calculator;

    public SecondTierBank(){
        this.calculator = new Calculator();
    }

    public double calculateDeposit(double money, int duration, String type_of_client){
        return calculator.depositReward(money, duration, type_of_client)* FIXEDBANKREWARD;
    }
}



package Loan;

public class Calculator {
    private final double RATEFORLEGALENTITIES = 0.08;
    private final double RATEFORINDIVIDUALS = 0.1;

    public double depositReward(double money, int duration, String type_of_client){
        if(type_of_client.equals("individual")){
            return money + money * RATEFORINDIVIDUALS * duration / 12.0;
        }else if (type_of_client.equals("legalEntity")){
            return money + money * RATEFORLEGALENTITIES * duration / 12.0;
        }else{
            System.out.println("error!");
            return 0;
        }
    }
}


