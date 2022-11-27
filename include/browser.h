#include <tab.h>

typedef struct {
    tab_t* f_tab;
    tab_t* active_tab;

    tab_t* f_history;
} browser_t;

browser_t create_browser();
void print_tab_name(tab_t tab);

void insert_tab(browser_t* browser, tab_t* tab);
void insert_first_tab(browser_t* browser, tab_t* tab);
void insert_last_tab(browser_t* browser, tab_t* tab);