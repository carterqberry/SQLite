package testsuite;

import java.io.*;
import java.util.*;

public final class Suite
{
    String name;
    BufferedWriter sink;
    ArrayList tests = new ArrayList();

    public Suite(String name)
        throws IOException
    {
        this.sink =
            new BufferedWriter(
                new OutputStreamWriter(System.out)
                              );
        this.name = name;
    }
    public Suite(String name,
                 BufferedWriter sink)
    {
        this.sink = sink;
        this.name = name;
    }

    public void addTest(Test t)
    {
        t.setSink(sink);
        tests.add(t);
    }

    public void run()
        throws IOException
    {
        for (int i = 0; i < tests.size(); ++i)
        {
            Test t = (Test) tests.get(i);
            t.run();
        }
    }
    public void report()
        throws IOException
    {
        String label = "Suite \"" + name + "\"";
        sink.write(label);
        sink.newLine();
        dashes(sink, label.length());

        for (int i = 0; i < tests.size(); ++i)
        {
            Test t = (Test) tests.get(i);
            t.report();
        }
        dashes(sink, label.length());
        sink.flush();
    }
    static void dashes(BufferedWriter sink, int len)
        throws IOException
    {
        for (int i = 0; i < len; ++i)
            sink.write("=");
        sink.newLine();
    }
    public void flush()
        throws IOException
    {
        sink.flush();
    }

    public void close()
        throws IOException
    {
        sink.close();
    }
}
