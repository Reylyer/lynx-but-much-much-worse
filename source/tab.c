#include <tab.h>
#include <stdlib.h>

tab_t create_tab(){
    tab_t* tab = (tab_t*) malloc(sizeof(tab_t));
    tab->link = NULL;
    tab->name = NULL;
    
    tab->next = NULL;
    tab->prev = NULL;
    return *tab;
}