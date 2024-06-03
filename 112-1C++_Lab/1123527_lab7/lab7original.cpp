// Fig. 5.10: fig05_10.cpp
// Craps simulation.
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
using namespace std;

int rollDice(); // rolls dice, calculates and displays sum

int main(){
    
        // enumeration with constants that represent the game status
        enum Status { CONTINUE, WON, LOST }; // all caps in constants

        int myPoint; // point if no win or loss on first roll
        Status gameStatus; // can contain CONTINUE, WON or LOST

        //randomize random number generator using current time
        srand(time(0));

        int sumOfDice = rollDice(); // first roll of the dice
        // determine game status and point (if needed) based on first roll
    
        switch (sumOfDice){
            case 7: // win with 7 on first roll
            case 11: // win with 11 on first roll
                gameStatus = WON;
                break;
            case 2: // lose with 2 on first roll
            case 3: // lose with 3 on first roll
            case 12: // lose with 12 on first roll
                gameStatus = LOST;
                break;
           default: // did not win or lose, so remember point
               gameStatus = CONTINUE; // game is not over
               myPoint = sumOfDice; // remember the point
               cout << "Point is " << myPoint << endl;
               break; // optional at end of switch
        } // end switch

        // while game is not complete
        while ( gameStatus == CONTINUE ) // not WON or LOST  
        {
           sumOfDice = rollDice(); // roll dice again

           // determine game status
           if ( sumOfDice = myPoint) // win by making point
               gameStatus = WON;
           else
               if(sumOfDice == 7)//lose by rolling 7 before point
                   gameStatus = LOST;
        }// end while
    

}// end main

// roll dice, calculate sum and display results
int rollDice()
{
    // pick random die values
    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll
    
    int sum = die1 + die2; // compute sum of die values

    return sum; // end function rollDice
}//end function rollDice