#include <stdio.h>
#include <string.h>
#include "phonebook_data.h"

int how_many_records(abonent_record* phonebook) {
    if(NULL == phonebook) return -1;

    int counter = 0;
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 != phonebook[i].name[0] ||
           0 != phonebook[i].surname[0] ||
           0 != phonebook[i].phone[0]) counter++;
    }
    return counter;
}

int is_place_for_new_record(abonent_record* phonebook) {
    return how_many_records(phonebook) - PHONEBOOK_MAX_REC;
}

int is_records_in_phonebook(abonent_record* phonebook) {
    return how_many_records(phonebook);
}

int index_of_first_empty_place_in_phonebook(abonent_record* phonebook) {
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 == phonebook[i].name[0] ||
           0 == phonebook[i].surname[0] ||
           0 == phonebook[i].phone[0]) return i;
    }
    return -1;
}

int get_next_index_from_prev_index_of_exist_record_in_phonebook(abonent_record* phonebook, int view_index) {
    if(view_index < 0) {
        view_index = -1;
    }
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 != phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].name[0] ||
           0 != phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].surname[0] ||
           0 != phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].phone[0]) {
            return (i + view_index + 1)%PHONEBOOK_MAX_REC;
        }
    }
    return -1;
}

int delete_record_from_phonebook_by_index(abonent_record* phonebook, int view_index) {
    phonebook[view_index].name[0] = 0;
    phonebook[view_index].surname[0] = 0;
    phonebook[view_index].phone[0] = 0;
    return 0;
}

int look_for_next_abonent_index_from_current(abonent_record* phonebook, abonent_record* what_to_search, int view_index, int and_search_flag) {
    if(view_index < 0) {
        view_index = -1;
    }
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(and_search_flag) {
            if(strcmp(phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].name, what_to_search->name) == 0 &&
               strcmp(phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].surname, what_to_search->surname) == 0 &&
               strcmp(phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].phone, what_to_search->phone) == 0) return (i + view_index + 1)%PHONEBOOK_MAX_REC;        
        } else {
            if(strcmp(phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].name, what_to_search->name) == 0 ||
               strcmp(phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].surname, what_to_search->surname) == 0 ||
               strcmp(phonebook[(i + view_index + 1)%PHONEBOOK_MAX_REC].phone, what_to_search->phone) == 0) return (i + view_index + 1)%PHONEBOOK_MAX_REC;                
        }
    }
    return -1;
}
