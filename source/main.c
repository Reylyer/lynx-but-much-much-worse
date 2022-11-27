#include <stdio.h>
#include <color.h>
#include <interface.h>

int main() {
    browser_t browser = create_browser();
    tab_t* tab1 = create_tab();
    tab1->name = "New tab";
    insert_tab(&browser, tab1);
    interface_loop(&browser);
}