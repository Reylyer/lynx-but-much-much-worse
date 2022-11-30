#include <page.h>
typedef struct tab {
    // char* link;
    // char* name;
    page_t* active_page;
    page_t* f_page;
    // char* content;

    struct tab* next;
    struct tab* prev;
    
} tab_t;

tab_t* create_tab(char* name);
void insert_page(tab_t* tab, page_t* page);
void insert_after_page(tab_t* tab, page_t* page, page_t* prec);
void insert_first_page(tab_t* tab, page_t* page);
void insert_last_page(tab_t* tab, page_t* page);
page_t* last_page(tab_t tab);

void print_page_name(page_t page);