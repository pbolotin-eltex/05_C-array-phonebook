#include "phonebook_menu_logic.h"
#include "phonebook_show.h"
#include "phonebook_interactions.h"

int main_menu(abonent_record* phonebook) {
    int quit_choice = 0;

    while(!quit_choice) {
        show_main_menu();
        switch(get_user_choice()) {
        case 1:
            if(is_place_for_new_record(phonebook)) {
                add_menu(phonebook);
            } else {
                show_no_place_message();
                get_user_reaction();
            }
            break;
        case 2:
            if(is_records_in_phonebook(phonebook)) {
                int view_index = -1;
                do {
                    view_index = get_next_index_from_prev_index_of_exist_record_in_phonebook(phonebook, view_index);
                    view_menu(phonebook, view_index);
                } while(get_user_choice() == 1);
            } else {
                show_no_records_message();
                get_user_reaction();
            }
            break;
        case 3:
            if(is_records_in_phonebook(phonebook)) {
                int view_index = -1;
                int user_choice = 1;
                do {
                    view_index = get_next_index_from_prev_index_of_exist_record_in_phonebook(phonebook, view_index);
                    del_menu(phonebook, view_index);
                    user_choice = get_user_choice();
                    if(user_choice == 2) {
                        delete_record_from_phonebook_by_index(phonebook, view_index);
                    }
                } while((1 == user_choice || 2 == user_choice) && is_records_in_phonebook(phonebook));
            } else {
                show_no_records_message();
                get_user_reaction();
            }
            break;
        case 4:
            if(is_records_in_phonebook(phonebook)) {
                abonent_record what_to_search;
                int and_search_flag = 0;
                get_data_for_search(&what_to_search, &and_search_flag);
                int view_index = -1;
                int user_choice = 1;
                int was_found = 0;
                do {
                    view_index = look_for_next_abonent_index_from_current(phonebook, &what_to_search, view_index, and_search_flag);
                    if(view_index == -1) {
                        show_no_found_message();
                        get_user_reaction();
                    } else {
                        was_found = 1;
                        search_menu(phonebook, &what_to_search, view_index);
                        user_choice = get_user_choice();
                    }
                } while(1 == user_choice && was_found);
            } else {
                show_no_records_message();
                get_user_reaction();
            }
            break;
        case 5:
            quit_choice = quit_menu(phonebook);
            break;
        default:;
        }
    }
    return 0;
}

int add_menu(abonent_record* phonebook) {
    show_add_menu();
    add_dialog(phonebook);
    return 0;
}

int view_menu(abonent_record* phonebook, int view_index) {
    clear_screen();
    show_name(phonebook[view_index].name, MAX_STR_LEN);
    show_surname(phonebook[view_index].surname, MAX_STR_LEN);
    show_phone(phonebook[view_index].phone, MAX_STR_LEN);
    show_view_menu();
    return 0;
}

int del_menu(abonent_record* phonebook, int view_index) {
    clear_screen();
    show_name(phonebook[view_index].name, MAX_STR_LEN);
    show_surname(phonebook[view_index].surname, MAX_STR_LEN);
    show_phone(phonebook[view_index].phone, MAX_STR_LEN);
    show_del_menu();
    return 0;
}

int search_menu(abonent_record* phonebook, abonent_record* look_for_abonent, int view_index) {
    clear_screen();
    show_name(phonebook[view_index].name, MAX_STR_LEN);
    show_surname(phonebook[view_index].surname, MAX_STR_LEN);
    show_phone(phonebook[view_index].phone, MAX_STR_LEN);
    show_search_menu();
    return 0;
}

int quit_menu(abonent_record* phonebook) {
    clear_screen();
    show_quit_menu();
    if(get_user_choice() == 2) return 1;
    else return 0;
}

int add_dialog(abonent_record* phonebook) {
    int index = index_of_first_empty_place_in_phonebook(phonebook);
    show_name_invoice();
    get_field_data_from_user(phonebook[index].name, MAX_STR_LEN);
    show_surname_invoice();
    get_field_data_from_user(phonebook[index].surname, MAX_STR_LEN);
    show_phone_invoice();
    get_field_data_from_user(phonebook[index].phone, MAX_STR_LEN);
    return 0;
}

int get_data_for_search(abonent_record* phonebook, int* and_search_flag) {
    clear_screen();
    show_invoice_geting_data_for_search();
    get_data_for_search_dialog(phonebook, and_search_flag);
    return 0;    
}

int get_data_for_search_dialog(abonent_record* what_to_search, int* and_search_flag) {
    show_name_invoice();
    get_field_data_from_user(what_to_search->name, MAX_STR_LEN);
    show_surname_invoice();
    get_field_data_from_user(what_to_search->surname, MAX_STR_LEN);
    show_phone_invoice();
    get_field_data_from_user(what_to_search->phone, MAX_STR_LEN);
    show_flag_invoice();
    if(get_user_choice() != 0) *and_search_flag = 1;
    return 0;
}
