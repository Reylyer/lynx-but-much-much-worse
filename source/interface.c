#include <interface.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <color.h>


void interface_loop(browser_t* browser) {
    char ch;
    char* tab_name; 
    char* page_name; 
    tab_t* tab;
    page_t* page;
    refresh_view(browser);
    do {
        ch = getch();
        switch (ch) {
            case 'w':
            case 'W': 
                // to_previous_page(browser);
                break;
            case 'a':
            case 'A':
                to_previous_tab(browser);
                break;
            case 's':
            case 'S': 
                // to_next_page(browser);
                break;
            case 'd':
            case 'D': 
                to_next_tab(browser); 
                break;
            case 'M': 
                show_prompt("Nama page: ");
                page_name = malloc(100);
                scanf("%[^\n]s\n", page_name); getchar();
                reset_color();
                // page->name = page_name;
                page = create_page(page_name);
                insert_page(tab, page);
                break;
            case 'n':
                show_prompt("Nama tab: ");
                tab_name = malloc(100);
                scanf("%[^\n]s\n", tab_name); getchar();
                reset_color();
                // tab->name = tab_name;
                tab = create_tab(tab_name);
                insert_tab(browser, tab);
                break;
            case 'q':
                return;
        }
        refresh_view(browser);

    } while (ch != 'q');
}

void show_tabs(browser_t browser) {
    tab_t* tab = browser.f_tab;
    set_color(1, BCYAN);
    printf("   ");
    while(tab) {
        if(tab == browser.active_tab) {
            set_color(1, BGREEN);
            print_tab_name(*tab);
            set_color(1, BCYAN);
        } else {
            print_tab_name(*tab);
        }
        printf("   ");
        tab = tab->next;
    }
    reset_color();
    printf("\n\n");
}

void show_header() {

}

void print_help_key(char* key, char* desc) { 
    set_color(1, BCYAN);
    printf("%2s", key);
    reset_color();
    printf(" %s", desc);
    printf("\t\t");
}
void show_menu() {
    print_help_key("N", "new tab");
    print_help_key("Q", "quit");
    print_help_key("W",  "prev page");
    print_help_key("M",  "new page");
    printf("\n");
    print_help_key("H", "history");
    print_help_key("A", "prev tab");
    print_help_key("S",  "next page");
    print_help_key("D",  "next tab");
    printf("\n");
}

void show_prompt(char* prompt) {
    printf("\n");
    set_color(1, BCYAN);
    printf("%s", prompt);
}

void refresh_view(browser_t* browser) {
    system("cls");
    show_header();
    show_tabs(*browser);
    printf("\n\n\n\n\n");
    show_menu();
}

void main_view(browser_t browser) {

}


void history_view(browser_t browser) {

}
