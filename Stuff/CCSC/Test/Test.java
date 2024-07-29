// Test.java: Simple automated test scaffolding
// Author: Chuck Allison, 2003-2007
// Permission to use granted provided source is cited

public class Test {
   static int nPass = 0;
   static int nFail = 0;

   public static void test(String label, boolean condition) {
      if (!condition)
         fail(label);
      else
         succeed();
   }
   public static final void test(boolean condition) {
      if (!condition)
         fail();
      else
         succeed();
   }
   public static void fail(String label) {
      System.out.println("FAILURE: " + label);
      ++nFail;
   }
   public static void fail() {
      // The failure is 2 levels back from here in the call chain
      // (which will be 3 by the time we call fail again)
      fail(3);
   }
   public static void fail(int level) {
      try
      {
          throw new RuntimeException();
      }
      catch (RuntimeException x)
      {
          // Extract file/line number where test was called
          StringBuffer message = new StringBuffer(x.getStackTrace()[level].toString());
          message.delete(0, message.indexOf("(")+1);
          message.deleteCharAt(message.length()-1);
          System.out.println("failure in line " + message);
      }
      ++nFail;
   }
   public static void succeed() {
      ++nPass;
   }
   public static int report() {
      System.out.println("Test Report:");
      System.out.println("\tPassed: " + nPass);
      System.out.println("\tFailed: " + nFail);
      return nFail;
   }
   public static void main(String[] args) {
       int x = 1;
       test(x == 1);
       report();
   }
}
