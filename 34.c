#include <stdio.h>
#include <stdlib.h>
int fact(int x){
  int out = 1;
  for(int i=2;i<=x;i++){
    out = out*i;
  }
  return out;
}
int test(int n_in){
  int n=n_in;
  int dig=1;
  int sum=0;
  while(n && dig<10){
    sum+=fact(n%10);
    n=n/10;
    dig++;
  }
  int result = (sum==n_in);
  return result;
}
int main(int argc, int *argv){
  int lim=fact(9)*10;
  for(int n=1;n<lim*100;n++){
    if(test(n)){
      printf("%d\n",n);
    };
  }
}
