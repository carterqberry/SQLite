/* calc.c:  Lame-brain Calculator -
 *
 *          For simplicity in parsing, this program
 *          reads lines of the form:
 *
 *              value operation
 *
 *          where the value is optional in some cases.
 *          For example, the following script computes
 *          the integer part of sqrt(1 + 3.4*3.4):
 *
 *              3.4 =
 *              3.4 *
 *                1 +
 *              sqrt
 *              floor
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define LINSIZ 40

char *getline(char *);

int main()
{
    double  reg = 0.0;
    char    line[LINSIZ];

    while (getline(line) != NULL)
    {
        char *op;
        double val;


        /* Parse command string */
        val = strtod(line,&op);
        while (isspace(*op))
            ++op;
        strupr(op);     /* non-portable */

        /* Perform operation */
        errno = 0;
        if (*op == '+')
            reg += val;
        else if (*op == '-')
            reg -= val;
        else if (*op == '*')
            reg *= val;
        else if (*op == '/')
        {
            if (val != 0)
                reg /= val;
            else
            {
                puts("ERROR>>> invalid divisor");
                continue;
            }
        }
        else if (*op == '=')
            reg = val;
        else if (*op == '^')
        {
            if (val == 0.0)
                reg = 1.0;
            else if (val == 0.5)
                reg = sqrt(reg);
            else
                reg = pow(reg,val);
        }
        else if (strncmp(op,"NEGATE",1) == 0)
            reg = -reg;
        else if (strncmp(op,"MOD",1) == 0)
        {
            if (val == 0.0)
            {
                puts("ERROR>>> invalid modulus");
                continue;
            }
            else
                reg = fmod(reg,val);
        }
        else if (strncmp(op,"CEIL",1) == 0)
            reg = ceil(reg);
        else if (strncmp(op,"FLOOR",1) == 0)
            reg = floor(reg);
        else if (strncmp(op,"ROUND",1) == 0)
            reg = (reg < 0.0) ? ceil(reg - 0.5) : floor(reg + 0.5);
        else if (strncmp(op,"SQRT",1) == 0)
            reg = sqrt(reg);
        else if (strncmp(op,"QUIT",1) == 0)
            exit(0);
        else if (*op != '\0')
        {
            puts("ERROR>>> invalid operation");
            continue;
        }

        if (errno)
            perror("ERROR>>>");
        else
            printf("\t%s => %g\n",line,reg);
    }
    return 0;
}

char *getline(char *buf)
{
    fputs("Calc> ",stdout);
    fflush(stdout);
    return gets(buf);
}

