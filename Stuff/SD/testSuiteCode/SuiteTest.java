/* Java TestSuite Example */
import java.io.*;
import testsuite.*;

class MyTest extends Test
{
    public void run()
        throws IOException
    {
        test("1 + 1 == 2", 1 + 1 == 2);
        test("1 + 1 == 3", 1 + 1 == 3);
    }
}

class MyOtherTest extends Test
{
    public void run()
        throws IOException
    {
        test("2 > 3", 2 > 3);
        test("2 < 3", 2 < 3);
    }
}

class SuiteTest
{
    public static void main(String[] args)
        throws IOException
    {
       Suite s = new Suite("My Test Suite");
       s.addTest(new MyTest());
       s.addTest(new MyOtherTest());
       s.run();
       s.report();
       s.close();
    }
}

