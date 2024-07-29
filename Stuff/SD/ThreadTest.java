class MyThread extends Thread
{
    public void run()
    {
        System.out.println("Throwing in MyThread");
        throw new RuntimeException();
    }
}

class ThreadTest
{
    public static void main(String[] args)
    {
        MyThread t = new MyThread();
        try
        {
        t.start();
            Thread.sleep(1000);
        }
        catch (Exception x)
        {
            System.out.println("Caught it");
        }
        System.out.println("Exiting main");
    }
}

