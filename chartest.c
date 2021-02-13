#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
char *a = malloc(100);
strcpy(a,"aaa");
a[0]++;
printf("a:%s\n",a);
}
