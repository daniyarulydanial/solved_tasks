//Lab1

package com.company;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Input number of repetitions: ");
        int repetitions = in.nextInt();
        for (int i = 0; i < repetitions; i++) {
            System.out.print("Input an operation('+','-','*','/','%','^'): ");
            String operator = in.next();

            System.out.print("Input a first number: ");
            double first = in.nextDouble();
            System.out.print("Input a second number: ");
            double second = in.nextDouble();

            double number = 0;

            if (operator.equals("+")) {
                number = first + second;
            }
            else if (operator.equals("-")) {
                number = first - second;
            }
            else if (operator.equals("*")) {
                number = first * second;
            }
            else if (operator.equals("/")) {
                number = first / second;
            }
            else if (operator.equals("%")) {
                number = first % second;
            }
            else if (operator.equals("^")) {
                number = Math.pow(first, second);
            }
            else {
                System.out.println("Input correct operation");
                continue;
            }

            System.out.println("Answer: " + number);

            if (number % 1 == 0) {
                System.out.println("It is integer");
            }
            else {
                System.out.println("It is double");
            }
        }

        in.close();
    }
}

//Lab 2 – Basic Java Syntax
//You will have 10 tasks overall. Some of them should be submitted during the class (classwork) whereas the rest before the deadline (homework).

//Task1 (classwork)
//Write a Java program which should multiply A and B (both taken as input from keyboard) without * (use loops instead)
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
//        String str1 = "1235421415454545454545454544";
//        String str2 = "1714546546546545454544548544544545";
//        2118187521397235888154583183918321221520083884298838480662480
        System.out.print("Enter first number: ");
        double first = input.nextDouble();
        System.out.print("Enter second number: ");
        double second = input.nextDouble();
        StringBuilder text1 = new StringBuilder(Double.toString(first));
        StringBuilder text2 = new StringBuilder(Double.toString(second));

        int count = 0;
        for (int i = text1.length() - 1; i > 0; i--){
            if (text1.charAt(i) == '.'){
                text1.deleteCharAt(i);
                break;
            }
            count++;
        }
        for (int i = text2.length() - 1; i > 0; i--){
            if (text2.charAt(i) == '.') {
                text2.deleteCharAt(i);
                break;
            }
            count++;
        }
        String str1 = String.valueOf(text1);
        String str2 = String.valueOf(text2);

        if ((str1.charAt(0) == '-' || str2.charAt(0) == '-') &&
                (str1.charAt(0) != '-' || str2.charAt(0) != '-'))
            System.out.print("Answer: -");

        if (str1.charAt(0) == '-')
            str1 = str1.substring(1);

        if (str2.charAt(0) == '-')
            str2 = str2.substring(1);

        StringBuilder answer = new StringBuilder(multiply(str1, str2));
        answer.insert(answer.length() - count,',');
        System.out.print(answer);

    }
    static String multiply(String num1, String num2)
    {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0 || len2 == 0)
            return "0";

        int[] result = new int[len1 + len2];
        int i_n1 = 0;
        int i_n2 = 0;

        for (int i = len1 - 1; i >= 0; i--)
        {
            int carry = 0;
            int n1 = num1.charAt(i) - '0';
            i_n2 = 0;

            for (int j = len2 - 1; j >= 0; j--)
            {
                int n2 = num2.charAt(j) - '0';
                int multiple = 0;
                for (int k = 0; k < n2; k++){
                    multiple += n1;
                }
                int sum = multiple + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }

            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }

        int i = result.length - 1;
        while (i >= 0 && result[i] == 0)
            i--;

        if (i == -1)
            return "0";

        StringBuilder s = new StringBuilder();
        while (i >= 0)
            s.append(result[i--]);

        return s.toString();
    }
}

//Task2 (classwork)
//Write a Java program which will take integer numbers as an input until 0 is entered; 
//Program also should display overall amount of entered numbers and their average meaning
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int count = 0;
        double sum = 0, average;
        while (true) {
            System.out.print("Input number: ");
            int number = in.nextInt();
            if (number == 0) {
                break;
            }
            sum += number;
            count++;
        }
        average = sum / count;

        System.out.print("Amount of entered numbers: " + count + "\nTheir sum: " + sum + "\nTheir average: " + average);
        in.close();
    }
}

//Task3 (classwork)
//Write a Java program which will take integer numbers as an input until 0 is entered; 
//Program also should display the maximum number among them (do not use arrays) 
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int count = 1, max, number;
        System.out.print("Input number: ");
        number = in.nextInt();
        if (number == 0) {
            System.out.print("There is no max number");
        }
        else {
            max = number;
            while (number != 0) {
                if (max <= number) {
                    max = number;
                }
                System.out.print("Input number: ");
                number = in.nextInt();
                count++;
            }
            System.out.print("Max number: " + max);
        }

        in.close();
    }
}

//Task4 (homework)
//Write a Java program which will take integer N as an input; 
//Program also should compute the sum of the first N numbers from the following sequence: 1, 3, 5, 7 … and so on
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = in.nextInt();
        int sum = 0;
        for (int i = 0, j = 1; i < n; i++, j+= 2){
            sum += j;
        }
        System.out.print("Sum: " + sum);
        in.close();
    }
}

//Task5 (homework)
//Write a Java program which will take integer numbers as an input until 0 is entered; Program also should display the sum of all “odd” entered numbers 
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int sum_of_odd = 0;
        while (true) {
            System.out.print("Input number: ");
            int number = in.nextInt();
            if (number == 0) {
                break;
            }
            if (number % 2 != 0) {
                sum_of_odd += number;
            }
        }

        System.out.print("Sum of odd numbers: " + sum_of_odd);
        in.close();
    }
}

//Task6 (classwork)
//Write a method which will take three integer numbers as parameters and returns maximum among them
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int a = in.nextInt();
        System.out.print("Enter the second number: ");
        int b = in.nextInt();
        System.out.print("Enter the third number: ");
        int c = in.nextInt();

        System.out.print("Maximum is: " + findMax(a, b, c));
        in.close();
    }
    static int findMax(int a, int b, int c) {
        if (a >= b && a >= c){
            return a;
        }
        else if (b >= a && b >= c){
            return b;
        }
        else{
            return c;
        }
    }
}

//Task7 (classwork)
//Write a method which will take string as parameter and returns number of vowels in it
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String text = in.nextLine();

        System.out.print("Number of vowels is: " + numberOfVowels(text));
        in.close();
    }
    static int numberOfVowels(String text) {
        char[] symbols = text.toCharArray();
        int count = 0;
        for (char symbol : symbols) {
            if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u'
                || symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U') {
                count++;
            }
        }
        return count;
    }
}

//Task8 (classwork)
//Write a method which will take array of strings as parameter and returns array of strings with more than 4 vowels in each
package com.company;
import java.util.Scanner;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the amount of strings: ");
        int number = Integer.parseInt(in.nextLine());
        ArrayList<String> myArray = new ArrayList<>();

        for (int i = 0; i < number; i++){
            System.out.print("Enter your text: ");
            myArray.add(in.nextLine());
        }

        ArrayList<String> newArray = removeSomeStrings(myArray);

        for (String s : newArray) {
            System.out.println(s);
        }
        in.close();
    }
    static ArrayList<String> removeSomeStrings(ArrayList<String> text) {
        ArrayList<String> newArray = new ArrayList<String>();
        for (String s : text) {
            char[] symbols = s.toCharArray();
            int count = 0;
            for (char symbol : symbols) {
                if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u'
                        || symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U') {
                    count++;
                }
            }
            if (count > 4) {
                newArray.add(s);
            }
        }
        return newArray;
    }
}


//Task9 (homework)
//Write a method which will take 2 strings as parameters (text1 and text2) and returns YES if text1 contains text2, otherwise it returns NO
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String text1, text2;
        System.out.print("Enter first text: ");
        text1 = in.nextLine();
        System.out.print("Enter second text: ");
        text2 = in.nextLine();

        System.out.print(contain(text1, text2));
        in.close();
    }
    static String contain(String text1, String text2) {
        if (text1.contains(text2)){
            return "YES";
        }
        return "NO";
    }
}

//Task10 (homework)
//Write a method which will take string as parameter and returns YES if the given string is palindrome, otherwise it returns NO
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String text;
        System.out.print("Enter your text: ");
        text = in.nextLine();

        System.out.print(isPalindrome(text));
        in.close();
    }
    static String isPalindrome(String text) {
        char[] symbols = text.toCharArray();
        char[] reversed = new char[symbols.length];
        for (int i = symbols.length - 1, j = 0; i >= 0; i--, j++){
            reversed[j] = symbols[i];
        }
        String newText = String.valueOf(reversed);
        if (text.equals(newText)){
            return "YES";
        }
        return "NO";
    }
}


//Additional class work
//Task11 
//Write a method which will took integer number and then as a return will reverse it without a certain numbers (278345 and 8 -> 54372)
package com.company;
import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your number: ");
        int number = input.nextInt();
        System.out.print(reversed(number));
        input.close();
    }
    static StringBuilder reversed(int number) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter number which you want to delete: ");
        int to_delete = in.nextInt();

        ArrayList<Integer> numbers = new ArrayList<>();
        for (; number != 0; number /= 10)
            numbers.add(number % 10);

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers.get(i) == to_delete) {
                numbers.remove(i);
                i--;
            }
        }

        StringBuilder answer = new StringBuilder();
        for (Integer integer : numbers) {
            answer.append(integer);
        }

        return answer;
    }
}

//Task12 
//Write a method which will return the amount of characters of the longest word in a given string
package com.company;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter your text: ");
        String text = in.nextLine();

        System.out.print("Amount of characters of the longest word: " + find(text));
        in.close();
    }
    static int find(String text) {
        String[] words = text.split(" ");
        int max = 0;
        for (String word : words) {
            if (max <= word.length()) {
                max = word.length();
            }
        }
        return max;
    }
}


//Task13
//You are given two int arrays: А[n] и B[m]. You need to create third one with elements which is not common for them without repeating any
//Example
//A 1 4 2 3 2 7 8
//B 5 1 6 13 4
//New array: 3 7 8 5 6 13
package com.company;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your first array: ");
        String a = input.nextLine();
        String[] first = a.split(" ");
        int[] firstArray = new int[first.length];
        for (int i = 0; i < first.length; i++) {
            firstArray[i] = Integer.parseInt(first[i]);
        }

        System.out.print("Enter your second array: ");
        String b = input.nextLine();
        String[] second = b.split(" ");
        int[] secondArray = new int[second.length];
        for (int i = 0; i < second.length; i++) {
            secondArray[i] = Integer.parseInt(second[i]);
        }

        HashSet<Integer> have_copies = new HashSet<>();

        for (int i = 0; i < firstArray.length; i++) {
            for (int j = 1 + i; j < firstArray.length; j++) {
                if (firstArray[i] == firstArray[j]) {
                    have_copies.add(firstArray[i]);
                }
            }
        }

        for (int i = 0; i < secondArray.length; i++) {
            for (int j = 1 + i; j < secondArray.length; j++) {
                if (secondArray[i] == secondArray[j]) {
                    have_copies.add(secondArray[i]);
                }
            }
        }

        for (int value : firstArray) {
            for (int k : secondArray) {
                if (value == k) {
                    have_copies.add(value);
                }
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (int value : firstArray) {
            if (!have_copies.contains(value)) {
                result.add(value);
            }
        }
        for (int value : secondArray) {
            if (!have_copies.contains(value)) {
                result.add(value);
            }
        }

        System.out.print("Result:");
        for (Integer number : result) {
            System.out.print(" " + number);
        }
        input.close();
    }
}
