#include <tab.h>
#include <stdlib.h>
#include <stdio.h>

tab_t* create_tab(char* name){

    tab_t* tab = (tab_t*) malloc(sizeof(tab_t));
    tab->next = NULL;
    tab->prev = NULL;
    tab->active_page = NULL;
    tab->f_page = NULL;

    page_t* page = create_page(name);
    insert_page(tab, page);

    return tab;
}

void print_page_name(page_t page){
    printf(" %s ", page.name);
}

void insert_page(tab_t* tab, page_t* page){

    if (tab->active_page) {
        if (tab->active_page->next) {
            delete_all_after_page(tab->active_page);
        } 
        insert_last_page(tab, page);

        tab->active_page = tab->active_page->next;
    } else {
        insert_first_page(tab, page);
        tab->active_page = tab->f_page;
    }
}

void insert_after_page(tab_t* tab, page_t* page, page_t* prec){
    page->next = prec->next;
    prec->next = page;
    page->prev = prec;
    page->next->prev = page;
}

void insert_first_page(tab_t* tab, page_t* page) {
    if (tab->f_page) {
        tab->f_page->prev = page;
        page->next = tab->f_page;
        tab->f_page = page;
    }
    tab->f_page = page;
}

void insert_last_page(tab_t* tab, page_t* page) {
    page_t* last = last_page(*tab);
    if (last) {
        last->next = page;
        page->prev = last;
    } else {
        insert_first_page(tab, page);
    }
}

page_t* last_page(tab_t tab) {
    page_t* last = tab.f_page;

    if (last) {
        while (last->next) {
            last = last->next;
        }
        return last;
    }
    return NULL;
}

void delete_all_after_page(page_t* page){
    page_t* curr = page->next;
    page_t* next;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    page->next = NULL;
}

// tab1      ->   tab2 
//  V             V         
// #page         page
// page         #page
// page         page

// insert new page in tab1, and insert new tab3:
// tab1      ->   tab2    ->     tab3
//  V             V               V
// page          page            #page
// #page         #page
//               page
