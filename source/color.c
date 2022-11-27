#include <stdio.h>
#include <color.h>
#include <stdarg.h>


void set_color(int count, ...) {
    va_list args;
    va_start(args, count);

    while(count--){
        printf("\033[%dm", va_arg(args, int));
    }

    va_end(args);
}

void reset_color() {
    set_color(1, RESET);
}

