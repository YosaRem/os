// Simple implementation of cprintf console output for the kernel,
// based on printfmt() and the kernel console's cputchar().

#include <inc/types.h>
#include <inc/stdio.h>
#include <inc/stdarg.h>


// use console api to put char on the console
// increase amount of printed chars
static void putch(int ch, int *cnt) {
    cputchar(ch);
    *cnt++;
}

// init counter for printed chars
// use vprintfmt to parse input string and args
int vcprintf(const char *fmt, va_list ap) {
    int cnt = 0;

    vprintfmt((void *) putch, &cnt, fmt, ap);
    return cnt;
}

// parse args into stdargs struct
// return amount of printed chars
int cprintf(const char *fmt, ...) {
    va_list ap;
    int cnt;

    va_start(ap, fmt);
    cnt = vcprintf(fmt, ap);
    va_end(ap);

    return cnt;
}

