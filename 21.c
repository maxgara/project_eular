#include <math.h>
#include <stdio.h>
#define N 20000

int getPrimes(long maxprime,long *primes){
//get all primes less than or equal to maxprime and put them in the primes array


  primes[0]=2;
  int primecount=1;
  int is_prime=0;
  for(long i=2;i<=maxprime;i++){
    long sqrt_i = (long) sqrt((double) i);
    //guilty until proven innocent
    is_prime=1;
    //check if i is prime
    for(int j=0;j<primecount;j++){
      long prime=primes[j];
      //not prime condition
      if(i%prime==0){
        is_prime=0;
        break;
      }
      //if i is prime, then it must have a prime factor p where p<=sqrt(i).
      //therefore break if you have already checked all the primes through sqrt(i)
      else if(prime>sqrt_i){
        break;
      }
    }
    if(is_prime){
      primes[primecount]=i;
      primecount++;
    }
  }
  return primecount;
}

int getPrimeFactorization(long x,long *primes, int primes_size,long (*factorArray)[2]){
//get prime factorization of x, return as factorArray
//factorArray[primes_size][2] => [0]:prime factor, [1]: number of occurances

  long remainder = x;
  int i=0; //iterator for primes array
  long prime; //current prime to check
  long lastprime=0; //previous prime found
  int primes_hit=-1; //index for factorArray
  while (i<primes_size){
    prime =primes[i];

    //case in which new prime factor is found
    if(remainder%prime==0 && lastprime!=prime){
      primes_hit++;
      remainder=remainder/prime;
      factorArray[primes_hit][0]=prime;
      factorArray[primes_hit][1]=1;
      lastprime=prime;
      i=0;
    }

    //case in which prime factor is found that has already been counted
    else if(remainder%prime==0 && lastprime==prime){
      //don't add prime to sum
      remainder=remainder/prime;
      factorArray[primes_hit][1]++;
      i=0;
    }
    //normal end condition
    else if(remainder==1){
      break;
    }
    //failure condition
    else if(prime>remainder){
      printf("breaking on prime:%ld with remainder:%ld\n",prime,remainder);
      break;
    }
    //continue iterating through the array if you don't hit a special condition
    else{
    i++;
  }
  }
  return primes_hit+1;
}

long combinePrimes_getSum(long (*pfactorArray)[2],int arr_size){
  //get all factors from prime factors, return the sum of these factors


  long totalFactors=1;
  long mod_arr[arr_size]; //this variable holds the iterator values of each prime, so that as we iterate through i each factor is found exactly once
  for(int i=0;i<arr_size;i++){
    //figure out how many factors there will be and set up mod_arr
    long occurances= pfactorArray[i][1];
    mod_arr[i]=totalFactors;
    totalFactors=totalFactors*(occurances+1);
    //printf("mod_arr[%d]:%ld\n",i,mod_arr[i]);
  }

  long factors[totalFactors];
  //simulate a series of nested loops over a multidimensional array with an index for each prime, by looping through i and using mod_arr
  for(int i=0;i<totalFactors;i++){
    //calculate the factor corresponding to i
    long factor=1;
    for(int j=0;j<arr_size;j++){
      int modulus = pfactorArray[j][1]+1;
      int div = mod_arr[j];
      int power = (i /div) % modulus;
      long primeterm = (long) pow((double) pfactorArray[j][0] ,(double) power);
      factor=factor*primeterm;
    }
    factors[i]=factor;
    //printf("factor:%ld\n",factor);
  }
  //sum the resulting array of factors
  long sum=0;
  for(int i=0;i<totalFactors-1;i++){
    sum+=factors[i];
  }
  return sum;
}



int main(){
int primes_size;
long primes[N];
primes_size=getPrimes(N,primes);

long factorArray[100][2];
int primefcount = getPrimeFactorization(220,primes,primes_size,factorArray);
long factorsum = combinePrimes_getSum(factorArray,primefcount);
printf("factorsum[%d]:%ld\n",220,factorsum);



//make factor sums
long sums[N];
for(int i=2;i<N;i++){
  int primefcount = getPrimeFactorization(i,primes,primes_size,factorArray);
  printf("summing %d\n",i);
  sums[i] = combinePrimes_getSum(factorArray,primefcount);
  //printf("factorsum[%d]:%ld\n",i,factorsum);
}
//check sums for amicability, sum amicables
long amsum=1;
for(int i=2;i<N/2;i++){
  long sum1=sums[i];
  long sum2=0;
  if(sum1<N && sum1>0){
    sum2=sums[sum1];
  }
  if(sum2==i && sum2!=sum1){
    printf("amicable:%d\n",i);
    amsum+=i;
  }
}
printf("amsum:%ld\n",amsum);
printf("test:%d\n",primes_size);

return 0;
}
