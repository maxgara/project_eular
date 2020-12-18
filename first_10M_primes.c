#include <stdio.h>
#include <gmp.h>

#define MAXLOOPS 100000000

int main(){
//calculate the first term of the fibonacci sequence to have 1000 terms
  mpz_t p;
  mpz_t p_confirmed;
  mpz_init_set_ui(p,3);
  gmp_printf("%Zd\n",p);

  for(int i=2;i<MAXLOOPS;i++)
  {
    mpz_set_ui(p,i);
    int isprime = mpz_probab_prime_p(p,30);
    if(isprime==2)
    {
      mpz_set(p_confirmed,p);
    }
  }
  gmp_printf("%Zd\n",p_confirmed);

  mpz_clear(p);
  return 0;
}
