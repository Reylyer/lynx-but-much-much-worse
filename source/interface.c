#include <interface.h>
#include <stdio.h>
#include <color.h>

void show_tabs(browser_t browser) {
    tab_t* tab = browser.f_tab;
    set_color(1, BCYAN);
    printf("   ");
    while(tab) {
        if(tab == browser.active_tab) {
            set_color(2, FYELLOW, BGREEN);
            print_tab_name(*tab);
            set_color(2, FBLACK, BCYAN);
        } else {
            print_tab_name(*tab);
        }
        printf("   ");
        tab = tab->next;
    }
    reset_color();
    printf("\n\n");
}

void main_view(browser_t browser) {

}


void history_view(browser_t browser) {

}