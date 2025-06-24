#include <iostream>
#include <vector>
#include "Food.h"

using namespace std;



int main(){
    //pre-populated foods
    Food apple( "Apple", 95, 0, 19, 1, 0);
    Food banana( "Banana", 105, 0, 14, 1, 1);
    Food ramen("Instant Ramen", 380, 14, 2, 7, 1);
    Food burger("Cheeseburger", 303, 17, 7, 15, 680);
    Food salad("Salad", 15, 0, 1, 1, 1);
    Food pasta("Pasta", 131, 1, 1, 5, 1);
    Food pho("Pho", 350, 4, 1, 25, 1);
    Food proteinBar("Protein Bar", 200, 6, 5, 20, 1);
    Food pizza("Pizza", 285, 10, 3, 12, 1);
    Food soda("Soda", 150, 0, 39, 0, 30);
    Food finished("Total", 0, 0, 0, 0, 0); //total nutrition

    vector<Food> prePopulatedFoods = {apple, banana, ramen, burger, salad, pasta, pho, proteinBar, pizza, soda};

    cout << "Enter the following number of the food you ate today. Enter 11 to display your total nutritional intake for the day: \n" << endl;
    

    int choice;

    while(true){

        for(int i = 0; i < prePopulatedFoods.size(); i++){
            cout << i + 1 << ". " << prePopulatedFoods[i].getName() << endl;
        }
        cout << "--------------------------------" << endl;
        cout << "11. Finished Selecting Foods" << endl;

        cin >> choice;

        if(choice >= 1 && choice <= prePopulatedFoods.size()){
            finished = finished + prePopulatedFoods[choice - 1];
            prePopulatedFoods.erase(prePopulatedFoods.begin() + (choice -1));

        } else if (choice == 11){
            finished.print();
            break;
        } else {
            cout << "Invalid Input. Please Select the Numbers Listed." << endl;
        }
    }

    return 0;
}


/*
- should prompt user to choose a food item from list of options
- should continue looping unil user chooses to stop
- when user stops, total nutritional value of food should be combiend and displayed
- should have food item with name, calories, total fat, total sugars, protein, sodium DONE
- class variables must only be accessible via public accessors/mutators DONE
- override the addition operator to allow food items to be added together DONE
- should display at least 10 items for user
- when complete, display to user if they have exceeded any recommended intakes for an average adult DONE
    Energy: Approximately 2,000 cal.
    Total fat: less than 70g.
    Total sugars: less than 30g.
    Protein: Approximately 50g.
    Sodium: less than 2,300 mg.
- separate class into header files, must include guard DONE




*/