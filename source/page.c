#include <page.h>
#include <stdlib.h>

page_t* create_page(char* name){
    page_t* page = (page_t*) malloc(sizeof(page_t));
    page->name = name;
    
    page->next = NULL;
    page->prev = NULL;
    return page;
}

