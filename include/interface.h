#include <browser.h>

void interface_loop(browser_t* browser);
void show_tabs(browser_t browser);
void main_view(browser_t browser);
void history_view(browser_t browser);

void show_header();
void show_menu();
void show_prompt(char* prompt);
void print_help_key(char* key, char* desc);
void refresh_view(browser_t* browser);