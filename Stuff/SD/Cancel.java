// Stops a task safely
import java.io.*;

class Counter implements Runnable
{
   private int count = 0;
   private volatile boolean cancelled = false;
   
   public void run()
   {
      while (!cancelled)
      {
         System.out.println(count++);
         try
         {
            Thread.sleep(1000);
         }
         catch (InterruptedException x){}
      }
      System.out.println("Counter Finished");
   }
   void cancel()
   {
      cancelled = true;
   }
}

class Cancel
{
   public static void main(String[] args) {
      System.out.println("Press Enter to Cancel:");
      Counter c = new Counter();
      Thread t = new Thread(c);
      t.setPriority(Thread.NORM_PRIORITY-1);
      t.start();

      try {
         System.in.read();	// Wait for Enter keypress
      }
      catch (IOException x) {
         System.out.println(x);
      }
      c.cancel();      // Don't forget this!
      System.out.println("Exiting main");
   }
}

