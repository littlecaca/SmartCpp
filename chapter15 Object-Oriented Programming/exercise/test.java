package chapter15;

class Base {
    int num = 9;
    void print_num() {
        System.out.println(num);
    }
    public void test() {};
}

class Derived extends Base {
    int num;
    Derived(int n) {
        num = n;
    }
    // Can not reduce the visibility of the inherited method of Base
    // private void test() {};
}

public class test {
    public static void main(String args[]) {
        Derived der = new Derived(78);
        der.print_num();
    }
}