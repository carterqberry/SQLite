// stack.d: A stack template
class Stack(T) {
   T[] data;
   void push(T t) { 
      data ~= t;
   }
   T pop() {
      T t = data[length-1];   // Note "length" without prefix
      data.length = data.length - 1;
      return t;
   }
   int length() { return data.length; }
}

int main() {
   Stack!(int) s = new Stack!(int);
   s.push(1);
   assert(s.length == 1);  // Property access
   printf("popping %d\n", s.pop());
   assert(s.length == 0);
   return 0;
}  
  
