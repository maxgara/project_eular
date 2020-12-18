#include <stdio.h>
#include <stdlib.h>

int printstr(char (*ptr)[2][15]);

int main(){

  char x[100];
  char str[2][15] = {"You know what,","C is powerful."};
  printstr(&str);
  /*
  printf("string to repeat:");
  scanf("%s",x);
  printf("%s",x);
  */
}

int printstr(char (*ptr)[2][15]){
  printf("%s%s",(*ptr)[0],(*ptr)[1]);
}
