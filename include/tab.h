typedef struct tab {
    char* link;
    char* name;
    char* content;

    struct tab* next;
    struct tab* prev;
} tab_t;

tab_t create_tab();