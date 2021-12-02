#include <stdio.h>
#define N 100000
#include <string.h>
#include <stdlib.h>

int main(void) {
  FILE* file1;
  file1=fopen("input_day2.txt", "r");
  char row[N]="";
  char move[N]="";
  int number;
  int deep=0;
  int horizontal=0;
  while(1){
    if (feof(file1)){
      break;
    }
    fgets(row, N, file1);
    char *ptr=strtok(row, " "); //move
    strcpy(move,ptr); 
    ptr=strtok(NULL, " "); //number
    number=atoi(ptr);

    if (strcmp(move,"forward")==0){
      horizontal=horizontal+number;
      printf("horizontal: %d\n", horizontal);
      continue;
    }
    if (strcmp(move,"down")==0){
      deep=deep+number;
      printf("deep: %d\n", deep);
      continue;

    }
    if (strcmp(move,"up")==0){
      deep=deep-number;
      printf("deep: %d\n", deep);
      continue;
    }
    strcpy(row," ");
  }
  printf("Horizontal: %d\nDeep: %d\n", horizontal, deep);\
  printf("Result: %d\n", horizontal*deep);
  return 0;
}
