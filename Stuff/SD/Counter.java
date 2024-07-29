import java.util.*;

class Counter
{
   private int count;	// # of clients

   public Counter()
   {
      count = 0;
   }
   public synchronized void increment()
   {
      ++count;
   }
   public synchronized void decrement()
   {
      --count;
   }
   public synchronized int get()
   {
      return count;
   }
}
