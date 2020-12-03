#include <stdio.h>
#define MAXLOOPS 1000
#define MAXREMAINDERS 1000


int loopsize(int denom)
//factor the ratio 1/n until you get a repeated remainder or 0
{

int factors[MAXREMAINDERS];
int remainders[MAXREMAINDERS];
int remainder=1;
int hit=0;
int i;

for(i=0;i<MAXREMAINDERS;i++)
{
  factors[i]=(remainder/denom);
  remainders[i]=(remainder%denom)*10;
  remainder=remainders[i];
  printf("%d",factors[i]);

  //check if this remainder has occurred before
  hit=-1;
  for(int j=0;j<i;j++)
  {
    if(remainders[j]==remainders[i])
      hit=j;
  }
  if(remainder==0)
    break;
  else if(hit!=-1)
    return i-hit;
  }
return 0;
}

int main(){
int max = 0;
int maxn;
int size;
for(int i=2;i<MAXREMAINDERS;i++)
{
  size = loopsize(i);
  printf("\n");
  printf("1/%d size:%d\n",i,size);
  if(size>max)
  {
    max = size;
    maxn=i;
  }
}

printf("max%d maxn:%d\n",max,maxn);


  return 0;
}
