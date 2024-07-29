import java.nio.BufferOverflowException;
import java.nio.BufferUnderflowException;

public class FixedStackImpl {
    private Object[] data;
    private final int max;
    private int count = 0;
    public FixedStackImpl(int max) {
        this.max = max;
        data = new Object[max];
    }
    public void push(Object x) {
        if (count < max)
            data[count++] = x;
        else
            throw new BufferOverflowException();
    }
    public Object pop() {
        if (count == 0)
            throw new BufferUnderflowException();
        return data[--count];
    }
    public Object top() {
        if (count == 0)
            throw new BufferUnderflowException();
        return data[count-1];
    }
    public int size() {
        return count;
    }
    public static void main(String[] args) {
        FixedStackImpl fs = new FixedStackImpl(3);
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
            for (Object x: fs.data)
                System.out.println(x);
        }
    }
}
