// Add your program here!

//Soumeng Chea

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	//Guess round
	int total_guess_round[5]; //Using a list fuction. The game will start as [0, 1, 2, 3, 4]
	int i = 0; //Declare variavle value in 'int'

	for (i = 0; i < 5; i++){ //First single game with the usage of a loop
		//Generating a random of sample of number from 1 - 10
		srand(time(NULL));
		
		//Random number generator. rand() modulus of 10 plus 1
		int random_generate_number = rand() % 10 + 1;

		printf("Pick a number. In a range of 1 - 10 only!\n");

		int player_guess; //The number that the user guess
	        int num_guess = 0; //The number of games that were guessed

		while(1){ //Loop Statement
			
			printf("Your guess: "); //Player prompt
			scanf("%d", &player_guess);
			num_guess++;

			if (player_guess > random_generate_number){

				printf("Incorrect. Guess Lower!\n");
			}
			else if (player_guess < random_generate_number){
				
				printf("Incorrect. Guess Higher!\n");
			}
			else if (player_guess == random_generate_number){

				printf("YASSSSSS!!!! YOU GOT THIS BOO!\n");
				break;
			} 
		}
		total_guess_round[i] = num_guess;
	}


	printf("You guessing abilities:\n");

	for (i = 0; i < 5; i++){
		printf("Game %d took you to guess %d times\n", i, total_guess_round[i]);
	}
	return 0;

}
