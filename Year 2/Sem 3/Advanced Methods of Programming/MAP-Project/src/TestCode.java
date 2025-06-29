
abstract class A1 {
    abstract int getS1(int x);
    abstract int MihneaSuge();
}

class A2 extends A1 {
    static int f1;
    static int s1 = 0;

    public A2(int a) {
        this.f1 = a * s1;
        s1 = s1 + 1;
    }

    static int getS() {
        A2 ob = new A2(10);
        return ob.getS1(2);
    }

    int getS1(int g) {
        return f1;
    }
    int MihneaSuge() {
        return 0;
    }
}


// Main class to test the code
public class TestCode {
    public static void main(String[] args) {
        System.out.println(A2.getS()); // Call the static method and print the result
    }
}
