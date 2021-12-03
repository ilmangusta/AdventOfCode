#include <stdio.h>
#define N 100000
#include <string.h>
#include <stdlib.h>

int main(void) {
  FILE* file1=fopen("imput.txt", "r");
  char row[N]="";
  int deep[N], i=0;
  
  while(!feof(file1)){
    fgets(row, N, file1);
    deep[i]=atoi(row);
    i++;
    strcpy(row," ");
  }
  
  int count=0;
  for (int j=0; j<i-1; j++){
    if (deep[j]<deep[j+1]){
      count=count+1;
    }
  }
  printf("count: %d", count); //Result
  return 0;
}
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
