/* preproc.c:  Test # and ## preprocessing operators
 *
 *  NOTE:   DO NOT COMPILE! Preprocess only!
 */

/* Handy stringizing macros */
#define str(s) #s
#define xstr(s) str(s)

/* Handy token-pasting macros */
#define glue(a,b) a##b
#define xglue(a,b) glue(a,b)

/* Some definitions */
#define ID(x) "This is version " ## xstr(x)
#define INCFILE(x) xstr(glue(version,x)) ".h"
#define VERSION 2
#define ION ATILE

/* Expand some macros */
str(VERSION)
xstr(VERSION)
glue(VERSION,3)
xglue(VERSION,3)
glue(VERS,ION)
xglue(VERS,ION)

ID(VERSION)
INCFILE(VERSION)
str(INCFILE(VERSION))
xstr(INCFILE(VERSION))

