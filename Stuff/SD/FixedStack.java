class FixedStack
{
    private int capacity;
    private int size;
    private Object[] data;

    public FixedStack(int cap)
    {
        data = new Object[cap];
        capacity = cap;
        size = 0;
    }

    public void push(Object o)
        throws StackException
    {
        if (size == capacity)
            throw new StackException("overflow");
        data[size++] = o;
    }
    public Object pop()
        throws StackException
    {
        if (size <= 0)
            throw new StackException("underflow");
        return data[--size];
    }

    public Object top()
        throws StackException
    {
        if (size <= 0)
            throw new StackException("underflow");
        return data[size-1];
    }

    public int size()
    {
        return this.size;
    }
}

