#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *(argv[])){

  if(!argc){
    printf("need args\n");
    return 1;
  }

  printf("input:%d",(int)*argv[1]);
  
  return 0;
}
