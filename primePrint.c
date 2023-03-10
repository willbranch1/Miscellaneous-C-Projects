/*
Program prints all primes between 2 and x, and all twin primes within the set. It shows understanding of and ability to use and manipulate integers
within c.
*/
#include <stdio.h>
#include <stdbool.h>

int main()
{
  //bool variable to check if the input is valid
  bool flag = false;
  int x;
  while (!flag) {
    //ask user for input for a positive integer greater than 1 and read it
    printf("Input a positive integer greater than 1: ");
    scanf("%d", &x);
    //check to see if the input is valid
    if (x < 2 || x >10000) {
      printf("Incorrect input.\n");
    } else {
      flag = true;
    }
  }
  
  //create an array to store the prime numbers that are found
  int primeNumbers[x];
  
  //set the first index in the array to two, since that will always be a prime number in the array
  int newPrime = 2;
  primeNumbers[0] = newPrime;
  
  //create a count to know the amount of prime numbers found
  int count = 1;
  
  /*
  *Use a for loop to cycle through each number between 2 and x. Use a second
  for loop to see *if each number is prime by dividing it by each prime
  number before it. If the remainder *is zero for any division, then the
  number is not prime.
  */
  int i;
  for (i = 2; i < x; i++) {
    newPrime++;
    //check if new number is prime
    bool status = true;
    int j;
    for (j = 0; j <= count - 1 && status; j++) {
      if (newPrime % primeNumbers[j] == 0) {
        status = false;
      }
    }
    //add the new prime number to the array
    if (status) {
      primeNumbers[count] = newPrime;
      count++;
    }
  }
  
  //print out all of the prime numbers in the array, using count to know what index to stop at
  printf("Primes from 2 to %d:\n", x);
  for (i = 0; i < count; i++) {
    printf("%d ", primeNumbers[i]);
  }
  printf("\n");
  
  //determine how many twin primes there are
  int twinPrimes = 0;
  for (i = 0; i + 1 < count; i++) {
    if (primeNumbers[i] == primeNumbers[i + 1] - 2) {
      twinPrimes++;
    }
  }
  printf("Amongst these there are %d twin primes.\n", twinPrimes);
  
  //necessary return statement
  return 0;
}
