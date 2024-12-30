    /***********************************************************************
     * Names:  Lilli Lewis and Elene Sturua                                *
     * Assignment name: Random Number Generator Project                    *
     *                                                                     *
     * Assignment for 3/6/22                                               *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     Course Textbook; project instructions; class slides             *
     *   Help obtained:                                                    *
     *     Professor Johnson                                               *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Lilli Lewis  Elene Sturua                              *
     ***********************************************************************/



//libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*check function: our function that takes the user input (from scanf in our *
 *loop function) and checks that the input is between 1 and 100.            */
void
check (int guess)
{
  if((guess > 100) || (guess < 1))
    printf("Your guess is out of bounds, please try again. \n");
}


/* loop function: our function that uses a do while loop to ask for user     *
 * input, take in user input using scanf, check that it's in range using our *
 * check function, then take the  guess through some complex conditional if  *
 * statements and print that the guess is either correct, below the number,  *
 * or above the number. The loop will either repeat 10 times or until the    *
 * user correctly guesses the number, whichever comes first. If the user     *
 * correctly guesses the number, the function will congradulate them. If not,*   * the function will inform the user that they are out of turns (after 10).  */
void
loop (int number)
{
  //declare variables
  int i=1;
  int guess;
  
  do
    {
      printf ("Input your guess as an integer between the range of 1-100:\n");
      scanf ("%d", &guess);
      check(guess);

      if (guess == number)
        {
          printf("You have correctly guessed the number in %d tries. \n", i);
          i=11; //to end the loop when the number is guessed correctly
        }
      else if ((guess < number) && (i < 11))
        printf("Your guess was below the number, please try again.\n");      
      else if ((guess > number) && (i < 11))
        printf("Your guess was above the  number, please try again.\n");
           
      i++;
      
      if (i == 11)
        printf("You are out of guesses. The correct number was %d. \n", number);
     }

   while ((guess != number) && i<11);
}


/* main function: instructs user about the purpose of the program, how it   *
 * works, and what input is acceptable. It then generates a random number   *
 * using the srand, rand, and time functions, then calls the loop function. */
int
main()
{
  printf ("The purpose of the following program is to generate a random number between 1-100 and the user has the maximum number of 10 tries to guess the secret randomly generated number. Please only input whole numbers between 1-100 as your input. \n");

  
  srand((unsigned) time(0));
  int max_number=100;
  int number=(rand() % max_number) + 1;

  loop(number);
  
    
  return 0;
}



/* Preconditions: User inputs an integer between 1 and 100 (inclusive) at    *
 * the prompt.                                                               *
 * Postconditions: Program will isntruct the user how to use the program,    * 
 * then, based on the user input, return a message indicating if the user    *
 * correctly guessed the number or not, and if not, if the number is too low *
 * or high. If the user is out of guesses, the proram will indicate that.    */
