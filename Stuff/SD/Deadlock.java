class Resources {
   static Integer A = new Integer(1);
   static Integer B = new Integer(2);
}

class X extends Thread {
   public void run()
   {
      for (int i = 0; i < 10; ++i) {
         synchronized(Resources.A) {
            synchronized(Resources.B) {
               System.out.println("X in process");
               try {
                  Thread.sleep(1000);
               }
               catch (InterruptedException x) {
               }
            }
         }
      }
   }
}

class Y extends Thread
{
   public void run()
   {
      for (int i = 0; i < 10; ++i) {
         synchronized(Resources.B) {
            synchronized(Resources.A) {
               System.out.println("Y in process");
               try {
                  Thread.sleep(100);
               }
               catch (InterruptedException x) {
               }
            }
         }
      }
   }
}

class Deadlock {
   public static void main(String[] args) {
      (new X()).start();
      (new Y()).start();
   }
}

