//
//  main.cpp
//  numberGuesser
//
//  Created by Alfredo Amezcua on 4/30/24.
//

#include <iostream>
#include <cmath>

void StartGame();
bool PlayAgain();
bool IsGameOver(int secretInt, int numberOfAttempts, int guess);
int PlayerGuess(int numberOfAttempts);

void ShowResult(int secretInt, int numberOfAttempts);
const int DISALLOW_CHAR = 256;
int main() {
  
    // store secret variable
    // set range of 1 to 100
    // store number of attempts allowed to guess secret number
    //store the players guess
    //number of guesses will be log base 2 of the upper range - eg.log2(100) ~ 6.64 -> 7
    // method to change the secret number
    
    /*
     
     do {
        Play game
     }while (interested in game)
     
     Play Game:
     
        1. choose secret number - store as known value
        2. choose number of guess allowed ->max(log2(100))
     3. Ask user to make a guess and output number of guesses left
     4. accept input of guess from player
     5. compare guess to secret number
        5a.if guess is not equal to stored secret number then
            5a1.decrement number of guess left
            5a2. check to see if the guess was over or under than the stored secret number
                5a2a. if it was over - print that guess was over
                5a2b. if guess was under - print that guess was under
     }while(the game is not ver)
     
     show the result and tell play if there guess was correct or not
     
     functions:
     
     Play game -> StartGame()
     Play again -> PlayAgain()
     accept guess from player - > PlayerGuess()
     
     game not over -> IsGameOver()
     
     # of guesses left == 0 || player's guess == stored secret number
     
     show result -> ShowResult()
     
     if(player is correct)
     {
      console out "You are correct the secret number is \(secret number)"
     }
     else
     {
    console out " your chooses were not the secret number of \(secret number)"
    }
     */
    
    do 
    {
        StartGame();
    } while (PlayAgain());
    
    return 0;
}
void StartGame()
{
    const int MAX = 100;
    int secretInt = 7;
    int numberOfAttempts = ceil (log2(MAX) );
    int guess = 0;
    
    
    std::cout<< " You must guess the secret number from a range of 0 and 100 " << std::endl;
    do
    {
        guess = PlayerGuess(numberOfAttempts);
        if(guess != secretInt)
        {
            numberOfAttempts--;
            if (guess > secretInt)
            {
                std::cout << " Your guess was over the secret number" << std::endl;
            }
            else
            {
                std::cout << " Your guess was under the secret number " << std::endl;
            }
        }
            
    }while(!IsGameOver(secretInt, numberOfAttempts, guess));
    
    ShowResult(secretInt, numberOfAttempts);
        

}
bool PlayAgain()
{
    
    char yesOrno;
    bool Fail;
    
    do {
        Fail = false;
        
        std::cout << " Like to play agin?" << std::endl;
        std::cin>> yesOrno;
        
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(DISALLOW_CHAR, '\n');
            std::cout << " Try guessing only numbers " << std::endl;
            Fail = true;
        }
        
    } while (Fail);
    return yesOrno == 'y';
}
bool IsGameOver(int secretInt, int numberOfAttempts, int guess)
{
    return secretInt == guess || numberOfAttempts == 0; }
int PlayerGuess(int numberOfAttempts)
{
    
    int guess;
    bool Fail;
    
    do {
        Fail = false;
        
        std::cout << "Try placing your guess (number of attempts left: " << numberOfAttempts << "): ";
        std::cin >> guess;
        
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(DISALLOW_CHAR, '\n');
            std::cout << " Try guessing only numbers " << std::endl;
            Fail = true;
        }
    } while (Fail);
    return guess;
}
void ShowResult(int secretInt, int numberOfAttempts)
{
    if(numberOfAttempts > 0)
    {
        std::cout << " Luck you your guess is right!" << std::endl;
    }
    else
    {
        std::cout << " You werent that lucky this game, secret number is : "<< secretInt << "): ";
    }
}
