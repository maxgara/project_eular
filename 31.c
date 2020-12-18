#include <stdio.h>
#include <stdlib.h>

#define COMPLEXITY 8
int denominations[]={1,2,5,10,20,50,100,200};
int coin_count[COMPLEXITY];

void clear_upto(int limit){
  for(int i=0;i<limit;i++){
    coin_count[i]=0;
  }
}
void print_arr(){
  for(int i=0;i<COMPLEXITY;i++){
    printf("%d:%d ",denominations[i],coin_count[i]);
  }
  printf("\n");
}
int sum_arr(){
  int sum=0;
  for(int i=0;i<COMPLEXITY;i++){
    sum+=coin_count[i] * denominations[i];
  }
  return sum;
}

int get_combinations(int target_sum,int limit){
  static int total_combinations=0;
  clear_upto(limit+1);
  if(limit==0){
    total_combinations++;
    coin_count[0]=target_sum-sum_arr();
    print_arr(denominations,coin_count,COMPLEXITY);
  }
  else{
    int max_coin_count = (target_sum-sum_arr()) / denominations[limit];
    for(int i=max_coin_count;i>=0;i--){
      coin_count[limit]=i;
      get_combinations(target_sum,limit-1);
    }
  }
return total_combinations;
}

int main(int argc, char *argv[]){
int target_sum = (argc>1) ? atoi(argv[1]) : 200;
int denominations[]={1,2,5};
int coin_count[COMPLEXITY];
clear_upto(COMPLEXITY);
int total_combinations=get_combinations(target_sum,COMPLEXITY-1);
printf("total_combinations:%d\n",total_combinations);
}
