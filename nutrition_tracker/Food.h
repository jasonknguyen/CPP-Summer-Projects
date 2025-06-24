#ifndef FOOD_H
#define FOOD_H

#include <iostream>


class Food{

    private:

    std::string name;
    int calories;
    int total_fat;
    int total_sugars;
    int protein;
    int sodium;

    public:

    Food(std::string name, int calories, int total_fat, int total_sugars, int protein, int sodium); // constructor
    void print() const; //print nutrition 
    Food operator+(const Food& rhs) const;


    //accessors and mutators

    std::string getName() const;

    int getCalories() const;
    void setCalories(int calories);

    int getTotalFat() const;
    void setTotalFat(int total_fat);

    int getTotalSugars() const;
    void setTotalSugars(int total_sugars);

    int getProtein() const;
    void setProtein(int protein);

    int getSodium() const;
    void setSodium(int sodium);


};

#endif