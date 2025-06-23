#include <iostream>
#include <vector>

using namespace std;

class Employee{

    private:

    string name;
    string jobTitle;
    double hourlyWage;


    public:

    Employee(string name, string jobTitle, double hourlyWage){
        this->name = name;
        this->jobTitle = jobTitle;

        if(hourlyWage > 0){
            this->hourlyWage = hourlyWage;
        } else {
            cout << "Invalid/Unknown Hourly Wage" << endl;
            this->hourlyWage = 0;
        }

    }

    void setName(string name){
        this->name = name;
    }

    string getName(){
        return name;
    }

    void setJobTitle(string jobTitle){
        this->jobTitle = jobTitle;
    }

    string getJobTitle(){
        return jobTitle;
    }

    void setHourlyWage(double hourlyWage){
        if(hourlyWage < 0){
            cout << "Hourly Wage cannot be negative. Please re-enter." << endl;
        } else{
            this->hourlyWage = hourlyWage;
        }

    }

    double getHourlyWage(){
        return hourlyWage;
    }

    void print(){
        cout << "Employee Name: " << name << "\nJob: " << jobTitle << "\nHourly Wage: $" << hourlyWage << "\n" << endl;
    }

};

int main(){

    int choice;
    double totalWages;
    double hoursWorked;


    vector<Employee> employees = {Employee("Jason", "Line Member", 15),Employee("Sarah", "Line Member", 15), Employee("Dylan", "General Manager", 25),Employee("Niobe", "GMIT", 45),Employee("Tram", "General Manager", 26),Employee("Ethan", "Grill Cook", 18) };

    cout << "\nWelcome to the Employee Database! Down below are 3 options where you may view all of your employee data, calculate your total wages for the week, and exit the application. Enter the number of the option you would like to pick." << endl;



    while(true){

        cout << "\n1. Print List of Employees (Name, Job Title, & Hourly Wage)\n2. Calculate Total Weekly Wages\n3. Exit Application\n" << endl;
        cin >> choice; //keeps app running after every use until exit ^^^

        if(choice < 1 || choice > 3){
            cout << "Invalid Input. Please Choose Options 1-3" << endl;
            cin >> choice;
        } else if(choice == 1) { //print employees
            for(Employee employee : employees){
                employee.print();
            }
        } else if(choice == 2) { //calculate total wages
            totalWages = 0; //reset after every use
            for(Employee employee : employees){
                cout << "How many hours did " << employee.getName() << " work this week? " << endl;
                cin >> hoursWorked; // user input

                while(hoursWorked < 0){ //check for errors
                    cout << "Invalid Input. Hours must be 0 or more." << endl;
                    cin >> hoursWorked;
                }

                hoursWorked *= employee.getHourlyWage(); // multiply hourly wage and hours
                totalWages += hoursWorked; //add to total
            }
            cout << "\nTotal Wages for the Week: $" << totalWages << endl;

        } else if (choice == 3) { // exit
            cout << "Exiting Application.." << endl;
            break;
        }
    }

    return 0;
}

/*

begin by greeting user with quick description off app's function
present options:
    1. print list of employees (print each name, title, hourly wages)
    2. calculate total wages (iterate thru each employee, ask ser to input total number of hours for each employee, multiply wage x hours, add it to a total, display total)
    3. exit application (break application out of loop and exit program)

- false input should not crash program
- make employee class with name, title, wage
    - variables should be private with public accessors/mutators
- mutators should prevent user from entering faulty negative numbers
- pre-populated list of at least 5 employees


user selects opton by entering value





*/