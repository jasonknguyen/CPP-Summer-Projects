#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));

    string questionText;

    cout << "Ask a question: " << endl;
    cin >> questionText;

    int r = rand() % 3;

    if(r == 0){
        cout << "Yes" << endl;
    } else if(r == 1){
        cout <<"No." << endl;
    } else {
        cout << "Maybe." << endl;
    }


    return 0;
}