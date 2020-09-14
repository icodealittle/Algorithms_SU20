// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
int factorial(int n){

	int unknown_factorial = n - 1;

	while (unknown_factorial > 0){
		n = n - 1;
		unknown_factorial --;
	}
	
  return n;
}

// TODO: Implement recursive solution here
int factorial_rec(int n){
	
	if (n > 0){
		return n * factorial_rec(n - 1);
	}
	else {
		return 1;
	}
}

//Some test cases

void testCase1(){

	printf("factorial(12) = %d\n", factorial(12));
  	printf("factorial_rec(12) = %d\n", factorial_rec(12));
}

void testCase2(){

	printf("factorial(15) = %d\n", factorial(15));
  	printf("factorial_rec(15) = %d\n", factorial_rec(15));
}

int main(){

  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));

	testCase1();
	testCase2();

  return 0;
}
