class StackTest
{
    public static void main(String[] args)
    {
        FixedStack s = new FixedStack(3);
        doTest(s);
    }

    public static void doTest(FixedStack s)
    {
        try
        {
            System.out.println("Initial size = "
                               + s.size());
            s.push("one");
            s.push(new Integer(2));
            s.push(new Float(3.0));

            s.push("one too many");  // error!
        }
        catch(StackException x)
        {
            x.printStackTrace(System.out);
        }
        try
        {
            System.out.println("Top: " + s.top());
            System.out.println("Popping...");

            while (s.size() > 0)
                System.out.println(s.pop());
        }
        catch(StackException x)
        {
            throw new InternalError(x.toString());
        }
    }
}

/* Output:
Initial size = 0
StackException: overflow
Top: 3.0
Popping...
3.0
2
one
*/

