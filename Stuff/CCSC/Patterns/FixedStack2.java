import java.nio.BufferOverflowException;
import java.nio.BufferUnderflowException;

public class FixedStack2 {
    private FixedStackImpl impl;
    public FixedStack2(int max) {
        impl = new FixedStackImpl(max);
    }
    public void push(Object x) {
        impl.push(x);
    }
    public Object pop() {
        return impl.pop();
    }
    public Object top() {
        return impl.top();
    }
    public int size() {
        return impl.size();
    }
    public static void main(String[] args) {
        FixedStack2 fs = new FixedStack2(3);
        try {
            fs.push(1);
            fs.push(2);
            fs.push(3);
            fs.push(4);
        }
        catch (RuntimeException x) {
            System.out.println(x);
        }
        finally {
            while (fs.size() > 0)
                System.out.println(fs.pop());
        }
    }
}
