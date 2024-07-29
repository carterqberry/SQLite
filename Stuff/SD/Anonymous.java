// Illustrates an anonymous "starter"
class MyTask
{
   private int delay;
   private int count;
   private String name;
   public MyTask(String name, int delay, int count)
   {
      this.delay = delay;
      this.count = count;
      this.name = name;
   }
   public void start() {
      new Thread() {
         public void run() {doit();}
      }.start();
   }
   private void doit()
   {
      for (int i = 0; i < count; ++i)
      {
         try
         {
            Thread.sleep(delay);
            System.out.println(name);
         }
         catch (InterruptedException x)
         {}
      }
   }
}

public class Anonymous
{
   public static void main(String[] args)
   {
      MyTask t1 = new MyTask("DessertTopping", 100, 8);
      MyTask t2 = new MyTask("FloorWax", 200, 4);
      t1.start();
      t2.start();
   }
}

