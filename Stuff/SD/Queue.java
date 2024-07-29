import java.util.*;

class Queue
{
   // The shared buffer:
   static Queue store = new Queue();

   private LinkedList data = new LinkedList();
    
   public void put(Object o)
   {
      data.addFirst(o);
   }
   public Object get()
   {
      return data.removeLast();
   }
   public int size()
   {
      return data.size();
   }
}
