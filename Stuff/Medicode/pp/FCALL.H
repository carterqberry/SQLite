#define fcall(expr) (_fcall(#expr,__FILE__,__LINE__) , expr)

fcall(f())

fcall(f(x,y))

