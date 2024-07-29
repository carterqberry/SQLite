/* ANSI screen escape sequences */

#include <stdio.h>

#define setcur(row, col) \
  fprintf(stderr,"\033[%d;%dH",(row),(col))
#define save_cur()      fputs("\033[s",stderr)
#define restore_cur()   fputs("\033[u",stderr)
#define cls()           fputs("\033[2J\033[H",stderr)
#define beep()          putc('\007',stderr)
#define home()          fputs("\033[H",stderr)
#define clear_line()    fputs("\033[2K",stderr)
#define clear_eol()     fputs("\033[K",stderr)
#define up(n)           fprintf(stderr,"\033[%dA",(n))
#define down(n)         fprintf(stderr,"\033[%dB",(n))
#define right(n)        fprintf(stderr,"\033[%dC",(n))
#define left(n)         fprintf(stderr,"\033[%dD",(n))
#define reset()         fputs("\033[0m",stderr)
#define bold()          fputs("\033[1m",stderr)
#define underl()        fputs("\033[4m",stderr)
#define blink()         fputs("\033[5m",stderr)
#define rvs()           fputs("\033[7m",stderr)
