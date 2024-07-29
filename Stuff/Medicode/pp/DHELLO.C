/* dhello.c:    Greet program using C++ digraphs */
#include <stdio.h>

main(int argc, char *argv<::>)
<%
    if (argc > 1 and argv<:0:> != NULL)
        printf("Hello, %s!??/n",argv<:1:>);
    else
        printf("Hello, world!??/n");
    return 0;
%>
