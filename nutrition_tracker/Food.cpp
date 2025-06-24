#include "Food.h"
#include <iostream>

Food::Food(std::string name, int calories, int total_fat, int total_sugars, int protein, int sodium){
    this->name = name;
    this->calories = calories;
    this->total_fat = total_fat;
    this->total_sugars = total_sugars;
    this->protein = protein;
    this->sodium = sodium;

} // constructor

void Food::print() const{
    std::cout << name << std::endl;
    std::cout << "Calories: " << calories << " calories" << std::endl;
    std::cout << "Total Fat: " << total_fat << "g" << std::endl;
    std::cout << "Total Sugars: " << total_sugars << "g" << std::endl;
    std::cout << "Protein: " << protein << "g" << std::endl;
    std::cout << "Sodium: " << sodium << "mg\n" << std::endl;

    if(calories > 2000){
        std::cout << "You have exceeded the recommended intake of 2,000 Calories today." << std::endl;
    }

    if(total_fat >= 70){
        std::cout << "You have exceeded the recommended intake of less than 70 grams of Total Fat today." << std::endl;
    }

    if(total_sugars >= 30){
        std::cout << "You have exceeded the recommended intake of less than 30 grams of Total Sugars today." << std::endl;
    }

    if(protein > 50){
        std::cout << "You have exceeded the recommended intake of 50 grams of Protein today." << std::endl;
    }

    if(sodium >= 2300){
        std::cout << "You have exceeded the recommended intake of less than 2,300 milligrams of Sodium today." << std::endl;
    }


} //print nutrition 

Food Food::operator+(const Food& rhs) const{
    return Food("Total Nutritional Value: ", this->calories + rhs.calories, this->total_fat + rhs.total_fat, this->total_sugars + rhs.total_sugars, this->protein + rhs.protein, this->sodium + rhs.sodium);
}


//accessors and mutators

std::string Food::getName() const{
    return name;
}


int Food::getCalories() const{
    return calories;
}
void Food::setCalories(int calories){
    this->calories = calories;
}

int Food::getTotalFat() const{
    return total_fat;
}
void Food::setTotalFat(int total_fat){
    this->total_fat = total_fat;
}

int Food::getTotalSugars() const{
    return total_sugars;
}

void Food::setTotalSugars(int total_sugars){
    this->total_sugars = total_sugars;
}

int Food::getProtein() const{
    return protein;
}
void Food::setProtein(int protein){
    this->protein = protein;
}

int Food::getSodium() const{
    return sodium;
}
void Food::setSodium(int sodium){
    this->sodium = sodium;
}
