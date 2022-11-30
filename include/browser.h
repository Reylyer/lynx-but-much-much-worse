#include <tab.h>

typedef struct {
    tab_t* f_tab;
    tab_t* active_tab;
} browser_t;

browser_t create_browser();
void print_tab_name(tab_t tab);

void insert_tab(browser_t* browser, tab_t* tab);
void insert_first_tab(browser_t* browser, tab_t* tab);
void insert_after_tab(browser_t* browser, tab_t* tab, tab_t* prec);
void insert_last_tab(browser_t* browser, tab_t* tab);

void to_previous_tab(browser_t* browser);
void to_next_tab(browser_t* browser);