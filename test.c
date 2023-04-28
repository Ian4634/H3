#include <stdio.h>
#include <string.h>
#include "line.h"
#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20
#include<stdlib.h>
#define Debug 0
// Each node in the list will store a single word

/******* my variables *******/
struct line{
    char *str;
    struct line *next;
};

typedef struct line Line;
Line *head = NULL; // new 'line' variable
Line *current;
/******* my variables *******/

int line_len = 0;
int num_words = 0;

/******* my func *******/
void insert_first(){
    char *str = malloc(MAX_WORD_LEN+2);
    Line *new_node = malloc(sizeof(Line));
    scanf("insert: %s", str);
    strcpy(new_node->str, str);
    new_node->next = head;
    head = new_node;
}

/******* my func *******/

void clear_line(void)
{

  // line[0] = '\0'; original code
    Line *temp;
    for(;head;head = temp){
        temp = head->next;
        free(head->str);
        free(head);
    }
    line_len = 0;
    num_words = 0;
    current = NULL;
}

void add_word(const char *str)
{
  /* original code
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
  */

// point previous to new_node, set new_node->next_node to null
    Line *new_node = malloc(sizeof(Line));
    line_len += strlen(str);
    num_words++;

    if(head == NULL){
        current = new_node;
        new_node->next = NULL;
        head = new_node;
        new_node->str = malloc(strlen(str)+1);
        strcpy(new_node->str, str);
        return;
    }
    line_len++; // because the space need to be counted from the second line.
    current->next = new_node;
    current = new_node;
    new_node->next = NULL; // since the new node is the last, set its next_node to null
    new_node->str = malloc(strlen(str)+1);
    strcpy(new_node->str, str);

}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
/*
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ') // if not space
      putchar(line[i]);
    else { // if is space
      spaces_to_insert = extra_spaces / (num_words - 1); // extra_spaces / gaps
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
*/

    int extra_spaces, spaces_to_insert, i, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    Line *cur_print = head;
    for(;cur_print;cur_print = cur_print->next){
        printf("%s", cur_print->str);
        if(cur_print->next == NULL){ // not the last word in line, if so, no need spaces
        }else{
            #if Debug
            printf("in else");
            #endif // Debug
            spaces_to_insert = extra_spaces / (num_words - 1); // extra_spaces / gaps
            for (j = 1; j <= spaces_to_insert + 1; j++){
                putchar(' ');
                extra_spaces -= spaces_to_insert;
                num_words--;
            }
        }
    }
    putchar('\n');
}

void flush_line(void)
{
/*
  if (line_len > 0)
    puts(line);
*/
    Line *cur_print = head;
    for(;cur_print;cur_print = cur_print->next){
        printf("%s", cur_print->str);
        if(cur_print->next != NULL){ // not the last word in line, if so, no need spaces

        }else{
            printf(" ");
        }

    }
    putchar('\n');

}

