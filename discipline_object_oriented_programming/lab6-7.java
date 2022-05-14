//Lab6.1

package com.Danik;
import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        LocalDate today = LocalDate.now();
        Scanner input = new Scanner(System.in);

        System.out.println("Enter products company name, discount of this company, product name, product price, product year of release: ");
       Product prod = new Product(input.next(), input.nextDouble(), input.next(), input.nextDouble(), input.nextInt());

        int days = (today.getYear() - prod.getYear_of_release()) * 365 + today.getMonthValue() * 30 + today.getDayOfMonth();

        if (today.getYear() - prod.getYear_of_release() > 2) {
            double price_of_product = prod.getPrice();
            prod.setPrice(price_of_product - (price_of_product * prod.getDiscount()));
        }

        System.out.println("Amount of days after year of release until this day: " + days);
        prod.display_info();
    }
}



package com.Danik;

public class Company {
    private String company_name;
    private double discount;

    public Company(String company_name, double discount) {
        this.company_name = company_name;
        this.discount = discount;
    }

    public void setName (String company_name) {
        this.company_name = company_name;
    }
    public String getName () {
        return company_name;
    }
    public void setDiscount (double discount) {
        this.discount = discount;
    }
    public double getDiscount() {
        return discount;
    }
}



package com.Danik;

public class Product extends Company {
    private String prod_name;
    private double price;
    private int year_of_release;

    public Product (String company_name, double discount, String prod_name, double price, int year_of_release) {
        super(company_name, discount);
        this.prod_name = prod_name;
        this.price = price;
        this.year_of_release = year_of_release;
    }

    public void setProd_name (String prod_name) {
        this.prod_name = prod_name;
    }
    public String getProd_name () {
        return prod_name;
    }
    public void setPrice (double price) {
        this.price = price;
    }
    public double getPrice () {
        return price;
    }
    public void setYear_of_release (int year_of_release) {
        this.year_of_release = year_of_release;
    }
    public int getYear_of_release () {
        return year_of_release;
    }

    public void display_info () {
        System.out.println("Product info: " + this.getName() + " " + this.getDiscount() + " " + this.prod_name + " " + this.price + " " + this.year_of_release);
    }
}

//Lab6.2

//Main.java
package com.Danik;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Library library = new Library();

        int choice = -1;

        while (choice != 0) {
            System.out.println("Welcome to the IITU Library");
            System.out.println("1. Add book");
            System.out.println("2. Add student");
            System.out.println("3. Give book to student");
            System.out.println("4. Return book from student");
            System.out.println("5. Print books information");
            System.out.println("6. Print students information");
            System.out.println("7. Print student's books");
            System.out.println("0. Exit");

            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Add book title, author, isbn, year and quantity separated with whitespaces: ");
                    Book book = new Book(input.next(), input.next(), input.next(), input.nextInt(), input.nextInt());
                    library.addBook(book);
                    break;
                case 2:
                    System.out.print("Add student id, name, surname, group separated with whitespaces: ");
                    Student student = new Student(input.nextInt(), input.next(), input.next(), input.next());
                    library.addStudent(student);
                    break;
                case 3:
                    System.out.println("Choose student by id: ");
                    int id_of_student = input.nextInt();
                    System.out.println("Choose book by isbn: ");
                    String isbn_of_book = input.next();
                    library.addBookToStudent(id_of_student, isbn_of_book);
                    break;
                case 4:
                    System.out.println("Choose student by id: ");
                    id_of_student = input.nextInt();
                    System.out.println("Choose book by isbn: ");
                    isbn_of_book = input.next();
                    library.returnBookFromStudent(id_of_student, isbn_of_book);
                    break;
                case 5:
                    library.printBooksInformation();
                    break;
                case 6:
                    library.printStudentsInformation();
                    break;
                case 7:
                    System.out.println("Choose student by id: ");
                    id_of_student = input.nextInt();
                    library.printStudentsBooks(id_of_student);
                    break;
            }
        }
    }
}

//Library.java
package com.Danik;
import java.util.ArrayList;

public class Library {
    private ArrayList<Book> books = new ArrayList<Book>();
    private ArrayList<Student> students = new ArrayList<Student>();

    public Library() {
        ArrayList<Book> books = new ArrayList<Book>();
        ArrayList<Student> students = new ArrayList<Student>();
    }

    public void addBook(Book book) {
        this.books.add(book);
    }

    public void addStudent(Student student) {
        this.students.add(student);
   }
    public void increaseBookQuantity(Book book) {
        book.setQuantity(book.getQuantity() + 1);
    }
    public void decreaseBookQuantity(Book book) {
        book.setQuantity(book.getQuantity() - 1);
    }

    public void addBookToStudent(int id, String isbn) {
        for (Book book: books) {
            if (isbn.equals(book.getIsbn())) {
                if (book.getQuantity() > 0) {
                    for (Student student : students) {
                        if (id == student.getId()) {
                            student.borrowBook(book);
                            this.decreaseBookQuantity(book);
                            break;
                        }
                    }
                }
                else {
                    System.out.println("This book is over");
                    break;
                }
            }
        }
    }

    public void returnBookFromStudent(int id, String isbn) {
        for (Book book: books) {
            if (isbn.equals(book.getIsbn())) {
                for (Student student: students) {
                    if (id == student.getId()) {
                        student.returnBook(book);
                        this.increaseBookQuantity(book);
                        break;
                    }
                }
            }
        }
    }

    public void printBooksInformation() {
        int count = 0;
        for (Book book: this.books) {
            book.show();
            count++;
        }
        System.out.println("Overall: " + count);
    }

    public void printStudentsInformation() {
        int count = 0;
        for (Student student: this.students) {
            student.show();
            count++;
        }
        System.out.println("Overall: " + count);
    }

    public void printStudentsBooks(int id) {
        for (Student student : students) {
            if (id == student.getId()) {
                student.printBooks();
            }
        }
   }
}

//Student.java
package com.Danik;
import java.util.ArrayList;

public class Student {
    private int id;
    private String name;
    private String surname;
    private String group;
    private ArrayList<Book> borrowedBooks = new ArrayList<Book>();

    public Student(int id, String name, String surname, String group) {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.group = group;
        ArrayList<Book> borrowedBooks = new ArrayList<Book>();
    }

    public void borrowBook(Book book) { this.borrowedBooks.add(book); }
    public void returnBook(Book book) { this.borrowedBooks.remove(book); }

    public void printBooks() {
        if (this.borrowedBooks.size() > 0) {
            for (Book borrowedBook : this.borrowedBooks) {
                borrowedBook.show();
            }
        }
        else System.out.println("This student has no books");
    }

    public int getId() { return this.id; }
    public void show() { System.out.println(this.id + " " + this.name + " " + this.surname + " " + this.group); }
}

//Book.java
package com.Danik;

public class Book {
    private String title;
    private String author;
    private String isbn;
    private int year;
    private int quantity;

    public Book(String title, String author, String isbn, int year, int quantity) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.year = year;
        this.quantity = quantity;
    }

    public int getQuantity() { return this.quantity; }
    public void setQuantity(int quantity) { this.quantity = quantity; }
    public String getIsbn() { return this.isbn; }

    public void show() { System.out.println(this.title + " " + this.author + " " + this.isbn + " " + this.year + " " + this.quantity); }
}

//Lab7

//Main.java:
package com.Danik;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Library library = new Library();

        int choice = -1;

        while (choice != 0) {
            System.out.println("Welcome to the IITU Library");
            System.out.println("1. Add book");
            System.out.println("2. Add student");
            System.out.println("3. Give book to user");
            System.out.println("4. Return book from user");
            System.out.println("5. Print books information");
            System.out.println("6. Print user`s information");
            System.out.println("7. Print user`s books");
            System.out.println("8. Check user by id");
            System.out.println("0. Exit");

            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Add book title, author, isbn, year, quantity and is it for children separated with whitespaces: ");
                    Book book = new Book(input.next(), input.next(), input.next(), input.nextInt(), input.nextInt(), input.nextBoolean());
                    library.addBook(book);
                    break;
                case 2:
                    System.out.print("Add user id, name, surname, group separated with whitespaces: ");
                    User user = new User(input.nextInt(), input.next(), input.next(), input.next());
                    library.addGuest(user);
                    break;
                case 3:
                    System.out.println("Choose user by id: ");
                    int id_of_user = input.nextInt();
                    System.out.println("Choose book by isbn: ");
                    String isbn_of_book = input.next();
                    if (10000 <= id_of_user)
                        library.addBookToGuest(id_of_user, isbn_of_book);
                    else
                        System.out.println("Please enter correct id");
                    break;
                case 4:
                    System.out.println("Choose user by id: ");
                    id_of_user = input.nextInt();
                    System.out.println("Choose book by isbn: ");
                    isbn_of_book = input.next();
                    if (10000 <= id_of_user)
                        library.returnBookFromGuest(id_of_user, isbn_of_book);
                    else
                        System.out.println("Please enter correct id");
                    break;
                case 5:
                    library.printBooksInformation();
                    break;
                case 6:
                    library.printGuestsInformation();
                    break;
                case 7:
                    System.out.println("Choose user by id: ");
                    id_of_user = input.nextInt();
                    if (10000 <= id_of_user)
                        library.printGuestsBooks(id_of_user);
                    else
                        System.out.println("Please enter correct id");
                    break;
                case 8:
                    System.out.println("Enter user`s id: ");
                    id_of_user = input.nextInt();
                    ArrayList<User> guests = library.getGuests();
                    boolean flag = false;
                    for (User guest : guests) {
                        if (guest.getId() == id_of_user) {
                            flag = true;
                            if (guest.check())
                                System.out.println("This user is pupil");
                            else
                                System.out.println("This user is student");
                            break;
                        }
                    }
                    if (!flag)
                        System.out.println("There are no such user");
            }
        }
    }
}

//Library.java:
package com.Danik;
import java.util.ArrayList;

public class Library {
    private ArrayList<Book> books = new ArrayList<Book>();
    private ArrayList<User> guests = new ArrayList<>();

    public void addBook(Book book) {
        this.books.add(book);
    }

    public void addGuest(User user) {
        if (user.check()) {
            Pupil pupil = new Pupil(user.getId(), user.getName(), user.getSurname(), user.getGroup());
            guests.add(pupil);
        } else {
            Student student = new Student(user.getId(), user.getName(), user.getSurname(), user.getGroup());
            guests.add(student);
        }
    }
    public void increaseBookQuantity(Book book) {
        book.setQuantity(book.getQuantity() + 1);
    }
    public void decreaseBookQuantity(Book book) {
        book.setQuantity(book.getQuantity() - 1);
    }

    public void addBookToGuest(int id, String isbn) {
        for (Book book: books) {
            if (isbn.equals(book.getIsbn())) {
                if (book.getQuantity() > 0) {
                    for (User user : guests) {
                        if (id == user.getId()) {
                            if (user.check()) {
                                if (!book.isForChildren()) {
                                    System.out.println("Since you pupil you can only take book for children");
                                    break;
                                }
                            }
                            user.borrowBook(book);
                            decreaseBookQuantity(book);
                            break;
                        }
                    }
                }
                else {
                    System.out.println("This book is over");
                    break;
                }
            }
        }
    }

    public void returnBookFromGuest(int id, String isbn) {
        for (Book book: books) {
            if (isbn.equals(book.getIsbn())) {
                for (User user : guests) {
                    if (id == user.getId()) {
                        user.returnBook(book);
                        this.increaseBookQuantity(book);
                        break;
                    }
                }
            }
        }
    }

    public void printBooksInformation() {
        int count = 0;
        for (Book book: books) {
            book.show();
            count++;
        }
        System.out.println("Overall: " + count);
    }

    public void printGuestsInformation() {
        int count = 0;
        for (User user: guests) {
            user.show();
            count++;
        }
        System.out.println("Overall: " + count);
    }

    public void printGuestsBooks(int id) {
        for (User user: guests) {
            if (id == user.getId()) {
                user.printBooks();
            }
        }
   }

    public ArrayList<User> getGuests() { return guests; }
}

//Book.java:
package com.Danik;

public class Book {
    private String title;
    private String author;
    private String isbn;
    private int year;
    private int quantity;
    private boolean isForChildren;

    public Book(String title, String author, String isbn, int year, int quantity, boolean isForChildren) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.year = year;
        this.quantity = quantity;
        this.isForChildren = isForChildren;
    }

    public int getQuantity() { return this.quantity; }
    public void setQuantity(int quantity) { this.quantity = quantity; }
    public String getIsbn() { return this.isbn; }

    public boolean isForChildren() { return isForChildren; }

    public void show() { System.out.println("Book: " + this.title + " " + this.author + " " + this.isbn + " " + this.year + " " + this.quantity + " " + this.isForChildren); }
}

//User.java:
package com.Danik;
import java.util.ArrayList;

public class User {
    protected int id;
    protected String name;
    protected String surname;
    protected String group;
    protected ArrayList<Book> borrowedBooks = new ArrayList<Book>();

    public User(int id, String name, String surname, String group) {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.group = group;
    }

    public void borrowBook(Book book) { this.borrowedBooks.add(book); }
    public void returnBook(Book book) { this.borrowedBooks.remove(book); }

    public void printBooks() {
        if (this.borrowedBooks.size() > 0) {
            for (Book borrowedBook : this.borrowedBooks) {
                borrowedBook.show();
            }
        }
        else if (id < 20000)
            System.out.println("This pupil has no books");
        else
            System.out.println("This student has no books");
    }

    public int getId() { return this.id; }

    public String getName() { return name; }

    public String getSurname() { return surname; }

    public String getGroup() { return group; }

    public boolean check(){
        return this.id < 20000;
    }

    public void show() { System.out.println(this.id + " " + this.name + " " + this.surname + " " + this.group); }
}

//Pupil.java:
package com.Danik;

public class Pupil extends User{

    public Pupil(int id, String name, String surname, String group) {
        super(id, name, surname, group);
    }

    @Override
    public void show() { System.out.println("Pupil: " + this.id + " " + this.name + " " + this.surname + " " + this.group); }
}

//Student.java:
package com.Danik;

public class Student extends User{

    public Student(int id, String name, String surname, String group) {
        super(id, name, surname, group);
    }

    @Override
    public void show() { System.out.println("Student: " + this.id + " " + this.name + " " + this.surname + " " + this.group); }
}

