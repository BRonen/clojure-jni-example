package Callbacks;
import java.util.function.BiFunction;

public class Callbacks {
    public interface IncCallback { int callback(int something); }

    public native int apply_callback(int value, IncCallback callback);
    public native Integer apply_bicallback(int x, int y, BiFunction<Integer, Integer, Integer> callback);

    static {
        System.loadLibrary("callbacks");
    }
}
