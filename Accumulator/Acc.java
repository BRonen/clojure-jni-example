package Accumulator;

public class Acc {
    private int value = 0;

    public native void accumulate(int x);
    public native int getValue();

    static {
        System.loadLibrary("acc");
    }
}
