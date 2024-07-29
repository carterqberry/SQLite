// tstr.cpp:     Test the C++ string class

#include <iostream.h>
#include <stddef.h>
#include <cstring.h>

// Handy display macros
#define result(exp) \
    cout << #exp ":  \"" << (exp) << '\"' << endl
#define test(obj,exp) \
    exp, print(#obj ", after " #exp ":\n",obj)

// Print a string in quotes
inline void print(const char *p, const string& s)
{
    cout << p << '"' << s << '"' << endl;
}

main()
{
    string s1("Now is the time for all worthy carbon units"),
           s2 = "to come to the aid of their sector.",
           s3 = '\n',
           s4(s1);
    size_t len = s1.length();

    // Test some operators
    result(s1 == s4);
    result(s1 < s4);
    result(s1 + s3 + s2);
    test(s1,s1 += s3 + s2);
    result(s1 == s4);
    test(s1,s1.resize(len));
    result(s1 == s4);
    cout << endl;

    // Search and replace
    size_t pos = s1.find("all");
    if (pos != NPOS)
        test(s1,s1.replace(pos,3,"some"));
    pos = s1.find("worthy");
    if (pos != NPOS)
    {
        result(s1.substr(pos,5));
        test(s1,s1.insert(pos,"un"));
    }
    cout << endl;

    // More searching
    result(s1.find_first_of("aeiou"));
    result(s1.find_first_not_of("aeiou"));
    result(s1.find_last_of("aeiou"));
    result(s1.find_last_not_of("aeiou"));
    cout << endl;

    // Subscripting
    pos = s2.find_first_of('d');
    test(s2,s2[pos] = 'l');
    return 0 ;
}
