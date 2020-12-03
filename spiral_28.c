#include <stdio.h>
#define CELLS 1001

long unsigned int get_corners(int level){
  long unsigned sum=0;
  int last_length=level*2 -1;
  long unsigned inner_area =last_length * last_length;
  long unsigned perimeter= (last_length+1)*4;
  long unsigned cell = inner_area + 2*level;
  for(int i=0;i<4;i++)
  {
    printf("cell:%ld\n",cell);
    sum+= cell;
    cell+=2*level;
  }
  return sum;
}

int main(){
  //create a spiral of values
  long unsigned size = CELLS * CELLS;
  long unsigned sum=1;
  for(int level=1;level<CELLS/2 + 1;level++)
    sum+=get_corners(level);

  printf("last sum:%ld\n",sum);

return 0;
}
