template<class T>
class stack {
   vector<T> data;
public:
   void push(T x) { data.push_back(x); }
   T pop() {
      T t = data.back();
      data.resize(data.size() - 1);
      return t;
   }
   size_t size() { return data.size(); }
};

