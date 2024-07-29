import java.io.*;
import TestSuite.*;

class MyOtherTest extends Test
{
    public void run()
        throws IOException
    {
        test("2 > 3", 2 > 3);
        test("2 < 3", 2 < 3);
    }
}

