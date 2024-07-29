class Consumer extends Thread
{
   private Counter counter;

   Consumer(String id, Counter counter)
   {
      super(id);
      this.counter = counter;
   }
   public void run()
   {
      for (;;) {
         synchronized(Queue.store) {
            while (Queue.store.size() == 0) {
               if (counter.get() == 0) {
                  // Producers done and queue is empty
                  System.out.println("\t" + getName()
                                     + " terminating");
                  return;
               }
               try {
                  Queue.store.wait();
               }
               catch (InterruptedException x) {}
            }
            System.out.println(getName() + " consuming "
                               + Queue.store.get());
         }
      }
   }
}

