#define MAX_STR_LEN 32
#define PHONEBOOK_MAX_REC 10

typedef struct abonent_record {
    char name[MAX_STR_LEN];
    char surname[MAX_STR_LEN];
    char phone[MAX_STR_LEN];
} abonent_record;

abonent_record phonebook[PHONEBOOK_MAX_REC];

int how_many_records(abonent_record* phonebook);

int is_place_for_new_record(abonent_record* phonebook);

int is_records_in_phonebook(abonent_record* phonebook);

int index_of_first_empty_place_in_phonebook(abonent_record* phonebook);

int get_next_index_from_prev_index_of_exist_record_in_phonebook(abonent_record* phonebook, int view_index);

int delete_record_from_phonebook_by_index(abonent_record* phonebook, int del_index);

int look_for_next_abonent_index_from_current(abonent_record* phonebook, abonent_record* what_to_search, int view_index, int and_search_flag);
