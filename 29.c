#include <stdio.h>
#include <math.h>
#include <gmp.h>
#define MAXVAL 10000000
#define MAXINDEX 500000


typedef struct
{
   unsigned long long primes[MAXINDEX];
   unsigned long long mults[MAXINDEX];
}Primes;

unsigned long int init_primes(Primes *pst, unsigned long int limit){

unsigned long int pcount=0;
int guilty;
unsigned long int root;
for(unsigned long int i=2;i<limit;i++)
{

  if(pcount==MAXINDEX)
  {
    printf("maxed out primes array\n");
    break;
  }

  guilty=0;
  root = sqrt(i);
  for(unsigned long int j=0;j<pcount;j++)
  {
    if(pst->primes[j]>root)
    {
      break;
    }
    else if(i%(pst->primes[j])==0)
    {
      guilty=1;
    }
  }
  if(!guilty)
  {
    pst->primes[pcount]=i;
    pst->mults[pcount]=0;
    pcount++;
  }
}
return pcount;

return 0;
}



int set_push(int x, int *arr, int N){
// x to a set, unless it's already there
for(int i=0;i<N;i++)
  if(arr[i]==x)
    return 0;
arr[N]=x;
return N+1;
}

int main(){
Primes my_pst;
unsigned long int count = init_primes(&my_pst,MAXVAL);

printf("count:%ld\n",count);
/*
for(unsigned long int i=0;i<count;i++)
  printf("prime[%ld]:%ld\n",i,my_pst.primes[i]);
*/


  return 0;
}
