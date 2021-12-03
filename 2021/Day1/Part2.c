#include <stdio.h>
#define N 100000
#include <string.h>
#include <stdlib.h>

int main(void) {
  FILE* file1;
  file1=fopen("imput.txt", "r");
  char row[N]="";
  int deep[N];
  int val;
  int i=0;
  while(1){
    if (feof(file1)){
      break;
    }
    fgets(row, N, file1);
    val=atoi(row);
    deep[i]=val;
    i++;
    strcpy(row," ");
  }
  int count=-1;
  int sum=0;
  int prev_sum=0;
  for (int j=0; j<i; j++){
    sum=deep[j]+deep[j+1]+deep[j+2];
    if (sum>prev_sum){
      count=count+1;
    }
    prev_sum=sum;
  }
  printf("count: %d", count);
  return 0;
}
