#include <browser.h>
#include <stdio.h>
#include <stdlib.h>

browser_t create_browser() {
    browser_t* browser = (browser_t*) malloc(sizeof(browser_t));
    browser->active_tab = NULL;
    browser->f_tab = NULL;
    browser->f_history = NULL;
    return *browser;
}

void print_tab_name(tab_t tab) {
    printf(" %s ", tab.name);
}

void insert_tab(browser_t* browser, tab_t* tab) {
    if (browser->active_tab) {
        if (browser->active_tab->next) {
            tab->next = browser->active_tab->next->next;
            browser->active_tab->next = tab;
            tab->prev = browser->active_tab;
            tab->next->prev = tab;
        } else {
            insert_last_tab(browser, tab);
        }
        browser->active_tab = browser->active_tab->next;
    } else {
        insert_first_tab(browser, tab);
        browser->active_tab = browser->f_tab;
    }
}

void insert_first_tab(browser_t* browser, tab_t* tab) {
    if (browser->f_tab) {
        browser->f_tab->prev = tab;
        tab->next = browser->f_tab;
        browser->f_tab = tab;
    }
    browser->f_tab = tab;
}

tab_t* last_tab(browser_t browser) {
    tab_t* last = browser.f_tab;

    if (last) {
        while (last->next) {
            last = last->next;
        }
        return last;
    }
    return NULL;
}

void insert_last_tab(browser_t* browser, tab_t* tab) {
    tab_t* last = last_tab(*browser);
    if (last) {
        last->next = tab;
        tab->prev = last;
    } else {
        insert_first_tab(browser, tab);
    }
}

void to_previous_tab(browser_t* browser){
    if (browser->active_tab) {
        if (browser->active_tab->prev) {
            browser->active_tab = browser->active_tab->prev;
        }
    }
}
void to_next_tab(browser_t* browser){
    if (browser->active_tab) {
        if (browser->active_tab->next) {
            browser->active_tab = browser->active_tab->next;
        }
    }
}