import java.io.*;
import TestSuite.*;

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

