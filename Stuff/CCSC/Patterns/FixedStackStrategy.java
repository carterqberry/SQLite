public class FixedStackStrategy implements IFixedStack {
    private IFixedStack impl;
    public FixedStackStrategy(IFixedStack fs) {
        impl = fs;
    }
    public void push(Object o) {
        impl.push(o);
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
    public void setImpl(IFixedStack fs) {
        impl = fs;
    }
}
