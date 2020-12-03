#include <stdio.h>
#include <gmp.h>

#define MAXLOOPS 100000

int main(){
//calculate the first term of the fibonacci sequence to have 1000 terms
  mpz_t x[2];
  mpz_init_set_ui(x[0],1);
  mpz_init_set_ui(x[1],1);

  int id_low_t=0;
  int size_high_t;
  int i;
  for(i=3;i<MAXLOOPS;i++){
    //store ith term in x[id_low_t];
    mpz_add(x[id_low_t],x[0],x[1]);
    char oneChar;
    size_high_t = gmp_snprintf (&oneChar, 1, "%Zd", x[id_low_t]);
    if(size_high_t>=1000)
      break;
    else
      id_low_t =(id_low_t + 1)%2;
    }

    printf("index:%d\n",i);
    printf("size_s:%d\n",size_high_t);
    gmp_printf("%Zd\n",x[id_low_t]);





  return 0;
}
