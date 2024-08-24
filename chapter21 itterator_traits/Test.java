

class Foo
{
    public int i;

    Foo(int val)
    {
        i = val;
    }
};

public class Test
{
    public static void main(String[] args) {
        Foo f = new Foo(2);
        System.out.println(f.i);
        func(f);
        System.out.println(f.i);
        int i = 2;
        func2(i);
    }

    static void func(Foo f)
    {
        f.i = f.i + 1;
    }
    
    static void func2(int i)
    {
        // 引用
        i = i + 1; //2
        i = 3;
    }

    static Foo f3()
    {
        Foo f = new Foo(3);
        Foo f2 = new Foo(2);
        f = f2;
        return f;
    }
}
