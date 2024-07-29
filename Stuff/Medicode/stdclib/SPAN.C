/* span.c */
#include <stdio.h>
#include <string.h>

void display_span(const char *, int);

int main()
{
    const char *s = "Eeek! A mouse device!";
    const char *vowels = "AEIOUaeiou";
    const char *punct = "`~!@#$%^&*()-_=+\\|[{]};:'\",<.>/?";
    char *ptr;

    display_span(s,strspn(s,vowels));
    display_span(s,strspn(s,punct));
    display_span(s,strcspn(s,vowels));
    display_span(s,strcspn(s,punct));

    ptr = strpbrk(s,vowels);
    puts(ptr);

    ptr = strpbrk(s,punct);
    puts(ptr);

    return 0;
}

void display_span(const char *s, int index)
{
    printf("%d characters spanned: %.*s\n",
            index,index,s);
}
