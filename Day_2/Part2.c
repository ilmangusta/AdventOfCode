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
  int aim=0;
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
      if (aim!=0){ //part 2
        deep=deep+(number*aim);
      }
      continue;
    }
    if (strcmp(move,"down")==0){
      aim=aim+number;  //parte 2
      continue;
    }
    if (strcmp(move,"up")==0){
      aim=aim-number; //parte2
      continue;
    }
    strcpy(row," ");
  }
  printf("Horizontal: %d\nDeep: %d\n", horizontal, deep);\
  printf("Result: %d\n", horizontal*deep);
  return 0;
}
