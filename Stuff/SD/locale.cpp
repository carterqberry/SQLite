#include <locale>
#include <iostream>
using namespace std;

main()
{
    locale global;
    cout << global.name() << endl;
    cout << 1.2 << endl;
    cout << 12345678L << endl;
    typedef numpunct<char> T;
    char pt = use_facet<T>(global).decimal_point();
    cout << pt << endl;
    
    locale loc("german");
    cout << loc.name() << endl;
    cout.imbue(loc);
    cout << 1.2 << endl;
    cout << 12345678L << endl;
    pt = use_facet<T>(loc).decimal_point();
    cout << pt << endl;
    use_facet<ctype<char> >(loc).truename()
}

