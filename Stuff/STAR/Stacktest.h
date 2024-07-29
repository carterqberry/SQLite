// Test of Stack Template
#include "stack.h"
#include "test.h"
#include <iostream>
using namespace std;

class StackTest : public Test
{
    enum {SIZE = 5};	// fixed size
    Stack<int> stk;

public:
    StackTest() : stk(SIZE)
    {}

    void run()
    {
        testUnderflow();
        testPopulate();
        testOverflow();
        testPop();
        testBadSize();
    }
    void reset()
    {
       stk.clear();     // truncate stack
       Test::reset();   // reset counters
    }
    void testBadSize()
    {
        try
        {
            Stack<int> s(0);
            fail_("Bad Size");
        }
        catch (StackError&)
        {
            succeed_();
        }
    }
    void testUnderflow()
    {
        reset();
        test_(stk.size() == 0);

        try
        {
            stk.top();
            fail_("Underflow");
        }
        catch (StackError&)
        {
            succeed_();
        }

        try
        {
            stk.pop();
            fail_("Underflow");
        }
        catch (StackError&)
        {
            succeed_();
        }
    }
    void testPopulate()
    {
        reset();
        try
        {
            for (int i = 0; i < SIZE; ++i)
                stk.push(i);
            succeed_();
        }
        catch (StackError&)
        {
            fail_("Populate");
        }

        test_(stk.size() == SIZE);
        test_(stk.top() == SIZE-1);
    }
    void testOverflow()
    {
        // Must be called immediately after testPopulate()
        try
        {
            stk.push(SIZE);
            fail_("Overflow");
        }
        catch (StackError&)
        {
            succeed_();
        }
    }

    void testPop()
    {
        // Must be called on after testPopulate()
        for (int i = 0; i < SIZE; ++i)
           test_(stk.pop() == SIZE-i-1);
        test_(stk.size() == 0);
    }
};

int main()
{
   StackTest t;
   t.run();
   t.report();
}
