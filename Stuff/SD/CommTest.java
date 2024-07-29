class CommTest2
{
   public static void main(String[] args)
   {
      // Start Producers
      Counter counter = new Counter();
      new Producer("Producer1", counter).start();
      new Producer("Producer2", counter).start();

      // Start Consumers
      new Consumer("Consumer1", counter).start();
      new Consumer("Consumer2", counter).start();
   }
}
