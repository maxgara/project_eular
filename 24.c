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


int getPossibleValues(int *arr,int *arrount,int N){
  int availability[ARR_LENGTH];
  //innocent until proven guilty
  for(int i=0;i<ARR_LENGTH;i++){
    availability[i]=1;
  }
  //remove offenders
  for(int i=0;i<N;i++){
      availability[arr[i]]=0;
  }
  //consolidate survivors
  int index=0;
  for(int i=0;i<ARR_LENGTH;i++){
    if(availability[i]){
      arrount[index]=i;
      index++;
    }
  }
  return index;
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
    //search for digit
    for(int i=0;i<ARR_LENGTH;i++){
      //found digit case
      if(rem-block_size<=0){
        result[dig-1]=possible_values[i];
        printf("%d",result[dig-1]);
        dig++;
        break;
        }
      // normal case
        else{
        rem=rem-block_size;
      }
    }
  }
  printf("\n");
}

int main(){

for(int i=1;i<1000001;i++){
  getMagicNum(i);
}




  return 0;
}
