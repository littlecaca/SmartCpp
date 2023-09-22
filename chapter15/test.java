package chapter15;

class Base {
    int num = 9;
    void print_num() {
        System.out.println(num);
    }
}

class Derived extends Base {
    int num;
    Derived(int n) {
        num = n;
    }
}

public class test {
    public static void main(String args[]) {
        Derived der = new Derived(78);
        der.print_num();
    }
}