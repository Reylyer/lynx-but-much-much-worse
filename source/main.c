#include <stdio.h>
#include <color.h>
#include <interface.h>

int main() {
    browser_t browser = create_browser();
    tab_t tab1 = create_tab();
    tab_t tab2 = create_tab();
    tab_t tab3 = create_tab();

    tab1.name = "Tab 1";
    tab2.name = "Tab 2";
    tab3.name = "Tab 3";
    // printf("%x:%x:%x\n", browser.active_tab, browser.f_tab, browser.f_history);

    insert_tab(&browser, &tab1);
    show_tabs(browser);
    printf("\n\n");
    insert_tab(&browser, &tab2);
    show_tabs(browser);
    printf("\n\n");
    insert_tab(&browser, &tab3);
    show_tabs(browser);
    printf("\n\n");

}