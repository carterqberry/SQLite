import java.nio.BufferOverflowException;
import java.nio.BufferUnderflowException;

public class FixedStack {
    private Object[] data;
    private final int max;
    private int count = 0;
    public FixedStack(int max) {
        this.max = max;
        data = new Object[max];
    }
    public void push(Object x) {
        if (count < max) {
            data[count++] = x;
        }
        else
            throw new BufferOverflowException();
    }
    public Object pop() {
        if (count == 0) {
            throw new BufferUnderflowException();
        }
        return data[--count];
    }
    public Object top() {
        if (count == 0) {
            throw new BufferUnderflowException();
        }
        return data[count-1];
    }
    public int size() {
        return count;
    }
}
