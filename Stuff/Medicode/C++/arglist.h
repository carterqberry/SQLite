// arglist.h

#include <string>
#include <vector>
using std::vector;

class Arglist
{
public:
    Arglist(int, const char **);
    size_t count() const
    {
        return args.size();
    }
    const std::string& operator[](size_t i) const;

private:
    vector<std::string> args;

    void expand(const char *);
    void add(const char *arg)
    {
        args.push_back(arg);
    }
};
    
