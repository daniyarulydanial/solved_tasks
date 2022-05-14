//Lab8

//Main.java:
package com.Danik;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
        System.out.println("Enter name of processor, frequency and RAM with spaces: ");
        String processor = in.next();
        double frequency = in.nextDouble();
        int RAM = in.nextInt();
        First first = new First(processor, frequency, RAM);
        System.out.println("Enter volume of winchester: ");
        Second second = new Second(processor, frequency, RAM, in.nextDouble());

        first.quality();
        first.getInfo();
        second.quality();
        second.getInfo();
    }
}

//First.java:
package com.Danik;

public class First {
    protected String name_of_processor;
    protected double frequency;
    protected int memory;
    protected double Q;

    public First(String name_of_processor, double frequency, int memory) {
        this.name_of_processor = name_of_processor;
        this.frequency = frequency;
        this.memory = memory;
    }

    public double quality() {
        Q = (0.1 * this.frequency) + this.memory;
        return this.Q;
    }

    public void getInfo() {
        System.out.println("Object Q: " + this.name_of_processor + " " + this.frequency + " " + this.memory + " " + this.Q);
    }
}

//Second.java:
package com.Danik;

public class Second extends First{
    private double P;
    private double Qp;

    public Second(String name_of_processor, double frequency, int memory, double P) {
        super(name_of_processor, frequency, memory);
        this.P = P;
    }

    @Override
    public double quality() {
        this.Qp = super.quality() + (0.5 * this.P);
        return this.Qp;
    }

    @Override
    public void getInfo() {
        System.out.println("Object Qp: " + this.name_of_processor + " " + this.frequency + " " + this.memory + " " + this.P + " " + this.Qp);
    }
}

//Lab10

//Main.java:
package Danik;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter warriors name: ");
        String name = in.next();
        System.out.print("Enter warriors health: ");
        int health = in.nextInt();
        System.out.print("Enter warriors damage level: ");
        int damageLevel = in.nextInt();
        Warrior warrior1 = new Warrior(name, health, damageLevel);

        System.out.print("Enter second warriors name: ");
        name = in.next();
        System.out.print("Enter second warriors health: ");
        health = in.nextInt();
        System.out.print("Enter second warriors damage level: ");
        damageLevel = in.nextInt();
        Warrior warrior2 = new Warrior(name, health, damageLevel);

        warrior1.fire(warrior2);
        System.out.println(warrior1);
        System.out.println(warrior2);

        warrior1.fire(warrior2);
        System.out.println(warrior1);
        System.out.println(warrior2);

        warrior2.fire(warrior1);
        System.out.println(warrior1);
        System.out.println(warrior2);

        warrior1.heal();
        warrior2.heal();
        System.out.println(warrior1);
        System.out.println(warrior2);
    }
}

//Character.java:
package Danik;

public interface Character {
    void fire(Warrior warrior);
    void heal();
}

//Player.java:
package Danik;

public class Player{
    private int health;
    private int damageLevel;
    private String name;

    public Player(String name, int health, int damageLevel) {
        this.health = health;
        this.damageLevel = damageLevel;
        this.name = name;
    }

    public int getHealth() {return health;}
    public int getDamageLevel() {return damageLevel;}
    public String getName() {return name;}

    public void setHealth(int health) {this.health = health;}
    public void setDamageLevel(int damageLevel) {this.damageLevel = damageLevel;}
    public void setName(String name) {this.name = name;}
}

//Warrior.java:
package Danik;

public class Warrior extends Player implements Character {

    public Warrior(String name, int health, int damageLevel) {
        super(name, health, damageLevel);
    }

    public void fire(Warrior warrior) {
        warrior.setHealth(warrior.getHealth() - this.getDamageLevel());
        if (warrior.getHealth() <= 0) {
            System.out.println("you killed " + warrior.getName());
            warrior = null;
        }
    }

    public void heal() {
        this.setHealth(this.getHealth() + 5);
    }

    @Override
    public String toString() {
        return this.getName() + " " + this.getHealth() + " " + this.getDamageLevel();
    }
}

