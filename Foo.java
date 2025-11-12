import Accumulator.Acc;
import Asm.Asm;

public class Foo {
    public native void helloworld();
    public native String echo(String sometext);
    public native int arraysum(int[] numbers);

    static {
        System.loadLibrary("foo");
    }

    public static void main(String[] args) {
        Foo jniobj = new Foo();

        jniobj.helloworld();

        System.out.println("[Java] ------------");

        String result = jniobj.echo("Hello World!");
        System.out.println("[Java] Returned from C: " + result);

        System.out.println("[Java] ------------");

        int[] numbers = {1, 2, 3, 4, 5};
        int sum = jniobj.arraysum(numbers);
        System.out.println("[Java] Sum: " + sum);

        System.out.println("[Java] ------------");

        Acc acc = new Acc();
        acc.accumulate(10);
        acc.accumulate(20);
        System.out.println("[Java] Total from accumulator: " + acc.getValue());

        System.out.println("[Java] ------------");

        Asm jniasm = new Asm();
        jniasm.inlineasm("[Inline Assembly] String printed directly from assembly\n");
    }
}
