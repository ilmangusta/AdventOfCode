void calcBin(const char* filename){
  FILE* file1=fopen(filename, "r");
  if(!file1){
    printf("Error\n");
    exit(1);
  }
  char row[N]="", buff[N]="", buff1[N]="";
  int i=0, cont1=0, cont0=0;
  while(1){
    if (i==12){
      break;
    }
    while(!feof(file1)){
      fgets(row, N, file1);
      if(row[i]=='0'){
        cont0=cont0+1;
      }
      if(row[i]=='1'){
        cont1=cont1+1;
      }
      strcpy(row,"");
    }
    if (cont0>cont1){
      strcat(buff, "0");
      strcat(buff1, "1");
    }
    if (cont1>cont0){
      strcat(buff, "1");
      strcat(buff1, "0");
    }
    cont1=0;
    cont0=0;
    fseek(file1, 0, SEEK_SET);
    i++;
  }
  printf("Binary1: %s\nBinary2: %s\n", buff, buff1);
}

int main(void) {
  calcBin("input_day3.txt");
  return 0;
}
