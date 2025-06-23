/* 4 different symbols: 7, $, #, X

    777 = 100 dollars
    $$$ = 50 dollars
    ### = 25 dollars
    XXX = 10 dollars

- ask user if they want to play slot machine or exit the program
- start with 10 bucks, each pull is 1 dollar
- everytime user matches, payout added to user's total dollars
- if user hits 0, exit program


*/

#include <iostream>
#include <stdlib.h> // random module

using namespace std;

char symbol(int num){
    switch(num){
        case 0:
            return '7';
        case 1:
            return '$';
        case 2:
            return '#';
        case 3:
            return 'X';
        default:
            return ' ';
    }
}

int main(){
    srand(time(0)); // random number generation seed

    int playerTotal = 10;
    int playerChoice;

    cout << "Welcome to the Slot Machine, You currently have $" << playerTotal << "! Enter Your Choice: " << endl;

    while(playerTotal > 0){
        cin >> playerChoice;


        if(playerChoice == 2){
            cout << "Exiting Slot Machine..." << endl;
            return 0;
        } else if(playerChoice == 1){
            playerTotal -= 1;
            cout << "You currently have $" << playerTotal << ". Rolling..." << endl;
        
            int slot1 = rand() % 3;
            int slot2 = rand() % 3;
            int slot3 = rand() % 3;

            char s1 = symbol(slot1);
            char s2 = symbol(slot2);
            char s3 = symbol(slot3);

            if(slot1 == 0 && slot2 == 0 && slot3 == 0){
                playerTotal += 100; //777
                cout << "You got 777! You win $100! You now have $" << playerTotal << "!" << endl;
                cout << "Enter 1 to play again or 2 to exit: " << endl;
            } else if(slot1 == 1 && slot2 == 1 && slot3 == 1){
                playerTotal += 50; //$$$
                cout << "You got $$$! You win $50! You now have $" << playerTotal << "!" << endl;
                cout << "Enter 1 to play again or 2 to exit: " << endl;
            } else if(slot1 == 2 && slot2 == 2 && slot3 == 2){
                playerTotal += 25; //###
                cout << "You got ###! You win $25! You now have $" << playerTotal << "!" << endl;
                cout << "Enter 1 to play again or 2 to exit: " << endl;
            } else if(slot1 == 3 && slot2 == 3 && slot3 == 3){
                playerTotal += 10; //XXX
                cout << "You got XXX! You win $10! You now have $" << playerTotal << "!" << endl;
                cout << "Enter 1 to play again or 2 to exit: " << endl;
            } else {
                cout << "You got " << s1 << s2 << s3 << "! You now have $" << playerTotal << "!" << endl;
                cout << "Enter 1 to play again or 2 to exit: " << endl;
            }


        } else {
            cout << "Invalid Choice. Enter 1 to play or 2 to exit." << endl;
        }
    }
    return 0;
}