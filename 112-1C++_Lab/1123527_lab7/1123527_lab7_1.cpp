#include <bits/stdc++.h>
using namespace std;

long randomNum = 0;
long randLFSR(){
	
    const int len_LFSR = 32;
    time_t seed = time(0) + randomNum;
	
    static int num[len_LFSR] = {0},
		position[len_LFSR] = {0},
		numLFSR[len_LFSR] = {0};
		
	int	j = -1,
		s0 = 0;

	
        
	for(int i = 0; i < len_LFSR; i++){
		num[i]= seed % 2;
		numLFSR[i]= seed % 2;
		if(num[i] == 1){
			j++;
			position[j] = i;
		}
		seed = seed / 2;
	}

    while(true){
		// 	
		for (int l = 0; l < len_LFSR; l++){
			numLFSR[l] = num[l];
		}
		// 
		int sum = 0,
			distance = 0;
		for(int l = 0; l <= j; l++){
			sum = sum + num[position[l]];
		}
		if(sum%2 == 1){
			s0 = 1;
		}else if (sum%2 == 0){
			s0 = 0;
		}
		
		for(int l = len_LFSR - 2; l >= 0; l--){
			num[l + 1] = num[l];
		} 
		num[0] = s0;
		//
		randomNum = 0;
		for(int m = 0; m < 32; m++){	
			randomNum += num[m]*pow(2,31-m);
		}
		break;
		
		//
	}
    return randomNum;
}// end randLFSR function

int rollDice()
{   
    int sum = ( abs(randLFSR()) %11 )+2; // compute sum of die values
    return sum; // end function rollDice
}//end function rollDice

enum Status { CONTINUE, WON, LOST };
int rollcount = 0;
Status crapsFunc(){

    int myPoint; // point if no win or loss on first roll
    Status gameStatus; // can contain CONTINUE, WON or LOST

    int sumOfDice = rollDice();
		rollcount++; // first roll of the dice
        // determine game status and point (if needed) based on first roll
    
    	switch (sumOfDice){
    	     // win with 7 on first roll
    	    case 5:
			case 7:
			case 10:
			case 11: // win with 11 on first roll
    	    case 9:
			case 4:
			case 8:
			    gameStatus = WON;
				break;
    	    case 2: // lose with 2 on first roll
    	    case 6: // lose with 3 on first roll
    	    case 12: // lose with 12 on first roll
			case 3:
			    gameStatus = LOST;
				break;
    	    default: // did not win or lose, so remember point
    	        gameStatus = CONTINUE; // game is not over
   		        myPoint = sumOfDice; // remember the point
        	    break; // optional at end of switch
		} // end switch
	
        // while game is not complete
    while ( gameStatus == CONTINUE ) // not WON or LOST  
    {
        sumOfDice = rollDice(); // roll dice again
        rollcount++;// determine game status
        if ( sumOfDice == myPoint){ // win by making point
            gameStatus = WON;
		}
		else
            if(sumOfDice == 10 )//lose by rolling 7 before point
            	gameStatus = LOST;
				
	}// end while
	
    if(gameStatus == WON){
	    return WON;
	}
	else
        return LOST;
}//end crapsFunction

int main(){
    int times = 0,
		wincount = 0,
		rounds = 0,
		maxrounds = 0;

	srand(time(0));

    cout <<"    Enter the number of times of Craps game to be played:";
    cin >> times;
	cout << endl;
	char conti = '0';
	double bestwinrate = 0,
		winrate = 0;

    do{
		wincount = 0;	
    	rounds++;
		clock_t t1,t2;
		t1=clock();
		
		for(int i = 0; i < times; i++){
			
        	if( crapsFunc() == WON){
        	    wincount ++;
        	}
    	}
		//useless
		cout << wincount << endl;
    	//
		float winrate = (float)wincount / times;
		//useless
		cout << winrate << endl;
		//
		if(abs(winrate - 0.63) < abs(bestwinrate - 0.63)){
			bestwinrate = winrate;
			maxrounds = rounds;
		}
		t2 = clock();
		double diff=(double)t2-(double)t1; 

		cout << "[R" << rounds << "] Win probability = " << winrate ;
		cout << "   The runtime of my program = " << diff/CLOCKS_PER_SEC << endl;
		cout << "	Continue to play? (Y or y for yes): ";
		cin >> conti;
	}while(conti == 'Y' ||conti == 'y');

	cout << "[OUT] The best win probability = " << bestwinrate << " obtained at R" << maxrounds <<endl;
	cout << "[OUT] Score = " << 100 - (abs(1.0 - (bestwinrate/0.63))*1000) << endl;
	return 0;
}