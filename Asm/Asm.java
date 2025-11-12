package Asm;

public class Asm {
    public native void inlineasm(String sometext);

    static {
        System.loadLibrary("asm");
    }
}
