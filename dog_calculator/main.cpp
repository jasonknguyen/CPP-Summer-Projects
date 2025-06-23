#include <iostream>

using namespace std;

int main(){
    // 1st year = 15 human years

    // 2nd year = 9 human years (24 year old)

    //3rd - inf = 5 human years

    //doubles seem to be industry standard?

    int dogYears;
    int humanYears;

    cout << "Enter in your dog's age: " << endl;
    cin >> dogYears;

    if(dogYears == 1){
        humanYears = 15;
    } else if (dogYears == 2){
        humanYears = 24;
    } else if(dogYears >= 3){
        humanYears = 24 + (dogYears - 2) * 5;
    }

    cout << "Your dog's age in human years is: " << humanYears << endl;

    return 0;
}