
typedef struct page {
    char* name;
    struct page* next;
    struct page* prev;
} page_t;

page_t* create_page(char* name);



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
