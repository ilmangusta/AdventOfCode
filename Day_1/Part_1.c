#include <stdio.h>
#define N 100000
#include <string.h>
#include <stdlib.h>

int main(void) {
  FILE* file1;
  file1=fopen("imput.txt", "r");
  char row[N]="";
  int deep[N];
  int i=0;
  while(1){
    if (feof(file1)){
      break;
    }
    fgets(row, N, file1);
    deep[i]=atoi(row);
    i++;
    strcpy(row," ");
  }
  int count=0;
  for (int j=0; j<i; j++){
    if (deep[j]==2682){
      break;
    }
    if (deep[j]<deep[j+1]){
      count=count+1;
    }
  }
  printf("count: %d", count);
  return 0;
}
