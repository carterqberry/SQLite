struct C
{
   ~C(){}
};

void g();

void f()
{
   C c;
   g();
}

