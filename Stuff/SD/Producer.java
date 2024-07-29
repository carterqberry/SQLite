import java.util.Random;

class Producer extends Thread
{
   private static Random numbers = new Random();
   private Counter counter;

   Producer(String id, Counter counter)
   {
      super(id);
      this.counter = counter;
   }

   int genNumber()
   {
      // Generate a random number in [1, 1000]
      return numbers.nextInt(1000)+1;
   }
   public void run()
   {
      counter.increment();	// ?
      
      // Generate some elements for the Queue
      for (int i = 0; i < 8; ++i) {
         int number = genNumber();
         System.out.println(getName() +
                            " producing " + number);
         synchronized(Queue.store) {
            Queue.store.put(new Integer(number));
            Queue.store.notify();
         }
      }
      synchronized(Queue.store) {
         // Prevent infinite loop
         // (because there are multiple consumers)
         counter.decrement();
         Queue.store.notifyAll(); 	// ?
      }
      System.out.println("\t" + getName() +
                         " finished");
   }
}
   
