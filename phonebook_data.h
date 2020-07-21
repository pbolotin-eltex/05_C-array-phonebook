/************************************
* This is important header file. 
*
* Here, phonebook array variable.
* Here, main limits of program as
* defines describes.
************************************/

#ifndef _PHONEBOOK_DATA_H_

#define _PHONEBOOK_DATA_H_

#define MAX_STR_LEN 32
#define PHONEBOOK_MAX_REC 10

typedef struct abonent_record {
    char name[MAX_STR_LEN];
    char surname[MAX_STR_LEN];
    char phone[MAX_STR_LEN];
} abonent_record;

/* Just about number of records in phonebook */
int how_many_records(abonent_record* phonebook);

/* Maybe our phonebook don't have enough place for new records?  */
int is_place_for_new_record(abonent_record* phonebook);

/* Maybe our phonebook don't have any records at all?  */
int are_records_in_phonebook(abonent_record* phonebook);

/* Where we will place new record? This function gives us an index of this place in array */
int index_of_first_empty_place_in_phonebook(abonent_record* phonebook);

/* Next function just search next exist record in array, because of can be empty places there! */
/* Isn't so short this function name and isn't so clear... :-) Let it be!  */
int get_next_index_from_prev_index_of_exist_record_in_phonebook(abonent_record* phonebook, int view_index);

/* This function do as its name say about */
int delete_record_from_phonebook_by_index(abonent_record* phonebook, int del_index);

/* Next abonent, next, next... [And], [or] modes of search... Return next index, if it's exist.*/
int look_for_next_abonent_index_from_current(abonent_record* phonebook, abonent_record* what_to_search, int view_index, int and_search_flag);

#endif
