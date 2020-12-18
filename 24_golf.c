#include <stdio.h>
#include <math.h>
#define ARR_LENGTH 10

long fact(int x){
  long result=1;
  for(int i=1;i<=x;i++){
    result=result*i;
  }
  return result;
}


void getPossibleValues(int *found,int *available,int N){
  int j=0;
  for(int i=0;i<ARR_LENGTH;i++){
    if( N==0 || found[j]!=i){
      available[i-j]=i;
      printf("%d",i);
    }else if(j<N){
      j++;
    }
  }
}


void getMagicNum(int N){


  int result[ARR_LENGTH];
  int rem=N;
  int dig=1;
  int possible_values[ARR_LENGTH];

  while(dig<=ARR_LENGTH){
    //calculate possible_values
    getPossibleValues(result,possible_values,dig-1);

    int block_size = fact(ARR_LENGTH-dig);
    result[dig-1]=possible_values[rem/block_size];
    rem=rem%block_size;
    dig++;
  }
  printf("\n");
}

int main(){
int found[ARR_LENGTH]={1,5,6};
printf("%d",found[2]);
int available[ARR_LENGTH];
getPossibleValues(found,available,3);




  return 0;
}
