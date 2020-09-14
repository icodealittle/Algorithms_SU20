// Add your program here!

//Soumeng Chea

#include <stdio.h>

//Create a function for the base and n exponential
double power(double base, double n){

	double result = 1; //Declare a value for the result. For example, power(2, 2) = 4.

	int i = 1; //Declaring a variable

	for (i = 1; i <= n; i++){ //Loop to find the exponent value

		result *= base;
	}

	return result; //return the result of the exponent power. 
}

int main(){

int i = 1; //Declaring a variable
 
for (i = 1; i <= 10; i++){ //Loop to find the exponent

double pResult = power(2, i); //Declare the value for i that was assigned in the loop above.

printf("2^%i is %.0f\n", i, pResult); //Print statement

}

return 0;

}


