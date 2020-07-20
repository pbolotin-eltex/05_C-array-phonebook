#include "phonebook_data.h"

int main_menu(abonent_record* phonebook);

int add_menu(abonent_record* phonebook);

int view_menu(abonent_record* phonebook, int view_index);

int del_menu(abonent_record* phonebook, int view_index);

int search_menu(abonent_record* phonebook, abonent_record* what_to_search, int view_index);

int quit_menu(abonent_record* phonebook);

int add_dialog(abonent_record* phonebook);

int get_data_for_search(abonent_record* phonebook, int *and_search_flag);

int get_data_for_search_dialog(abonent_record* what_to_search, int *and_search_flag);
