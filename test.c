#include <stdio.h>
#include <string.h>
#include<stdlib.h>



#define MAX_WORD_LEN 20
#define TEST 0

char line[60];
int line_len = 0;
int num_words = 0;
void add_word(const char *str)
{
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, str);
  line_len += strlen(str);
  num_words++;

}
int main(void){
    printf("%d", strlen("Cisquirky,flawed,andanenormoussuccess.Althoughaccidentsof"));

    return 0;

}

