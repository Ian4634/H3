#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20
#define TEST 1
#define Debug 0

int main(void){
    #if TEST
    char word[MAX_WORD_LEN+2];
    int word_len;
    clear_line();
    while (1) {
        #if Debug
        printf("start of loop\n");
        #endif // Debug
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);
        if (word_len == 0) {
            #if Debug
            printf("flushed\n", space_remaining());
            #endif // Debug
            flush_line();
            return 0;
        }
        #if Debug
        printf("\nspacing: %d\n", space_remaining());
        #endif // Debug
        if (word_len > MAX_WORD_LEN) word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
        #if Debug
        printf("end of loop\n");
        #endif // Debug
    }
    #endif // TEST


    return 0;

}
// maybe its the space remaining problem
