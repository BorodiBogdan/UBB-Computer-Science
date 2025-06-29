import java.util.ArrayList;

interface D {}

class A implements D {}

class B extends A implements D {}

class C extends A implements D {}

class Main {
    A method1(ArrayList<? extends A> list) {
        if (list.isEmpty()) return null;
        else return list.get(1);
    }

    void method2(ArrayList<? super C> list, C elem) {
        list.add(elem);
    }

    void method3(A elem) {
        ArrayList<A> listA = new ArrayList<>();
        listA.add(new C());
        listA.add(new C());

        ArrayList<B> listB = new ArrayList<>();
        listB.add(new B());
        listB.add(new B());

        ArrayList<C> listC = new ArrayList<>();
        listC.add(new C());
        listC.add(new C());

        // method1 should work with lists of A, B, and C (since they all extend/implement D)
        this.method1(listA);
        this.method1(listB);
        this.method1(listC);

        // method2 should work with listA but not listB, because it must be able to accept a C
        this.method2(listA, elem);
        this.method2(listC, elem);
    }

    public static void main(String[] args) {
        Main obj = new Main();
        obj.method3(new C()); // Calling method3 with an instance of B
    }
}
