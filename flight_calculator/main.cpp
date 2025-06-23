#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double earthRadius = 3958.8; // miles
const double averageSpeed = 500.0; // mph
const double pi = 3.14159265358979323846;
const double degreeToRadian = pi / 180.0;

class Location {
    public:
        string name;
        double latitude;
        double longitude;
};

double haversine(double lat1, double long1, double lat2, double long2, double radius){

    lat1 *= degreeToRadian;
    lat2 *= degreeToRadian;
    long1 *= degreeToRadian;
    long2 *= degreeToRadian;

    double latFormula = (lat2 - lat1) / 2;
    double longFormula = (long2 - long1) / 2;
    
    double distance = 2 * radius * asin(sqrt(pow(sin(latFormula), 2) + (cos(lat1) * cos(lat2) * pow(sin(longFormula), 2))));

    return distance;
}

double getFlightTime(double lat1, double long1, double lat2, double long2){

    double distance = haversine(lat1, long1, lat2, long2, earthRadius);
    return distance / averageSpeed; // returns flight time in hours
}

int main(){

    vector<Location> locations = {
        {"Grand Haven, MI, USA", 43.062244, -81.386658},
        {"Bloomington, IN, USA", 39.168804, -86.536659},
        {"Washington, GA, USA", 33.740253, -82.745875},
        {"Garland, TX, USA", 32.907223, -96.635277},
        {"Irvine, CA, USA", 33.669445, -117.823059},
        {"Aurora, CO, USA", 39.710835, -104.812500},
        {"Memphis, TN, USA", 35.117500, -89.971107},
        {"Columbus, OH, USA", 39.983334, -82.983330},
        {"Hackett, AR, USA", 35.188503, -94.412239},
        {"Yuma, AZ, USA", 32.698437, -114.650398}
    };

    int choice; // User's Choice
    string location1;
    string location2;
    double lat1;
    double long1;
    double lat2;
    double long2;
  

    cout << "Welcome to Flight Calculator." << endl;
    cout << "This application calculates the distance and flight time between your chosen departure and destination locations. Down below is a list of different locations. \nChoose your departure location: " << endl;

    for (int i = 0; i < locations.size(); i++) {
        cout << i + 1 << ". " << locations[i].name << " (" << locations[i].latitude << ", " << locations[i].longitude << ")" << endl;
    }

    cin >> choice;

    while(true){
        if(choice < 1 || choice > locations.size()) {
            cout << "Invalid Choice. Please enter a number between 1 and " << locations.size() << ": ";
            cin >> choice;
        } else {
            location1 = locations[choice - 1].name;
            lat1 = locations[choice - 1].latitude;
            long1 = locations[choice - 1].longitude;
            locations.erase(locations.begin() + (choice - 1));
            break;
        }
    }

    cout << "\nChoose your destination location: " << endl;

    for (int i = 0; i < locations.size(); i++) {
        cout << i + 1 << ". " << locations[i].name << " (" << locations[i].latitude << ", " << locations[i].longitude << ")" << endl;
    }
    
    cin >> choice;

    while(true){
        if(choice < 1 || choice > locations.size()) {
            cout << "Invalid Choice. Please enter a number between 1 and " << locations.size() << ": ";
            cin >> choice;
        } else {
            location2 = locations[choice - 1].name;
            lat2 = locations[choice - 1].latitude;
            long2 = locations[choice - 1].longitude;
            locations.erase(locations.begin() + (choice - 1));
            break;
        }
    }

    cout << "\nCalculating Distance and Flight Time...\n" << endl;

    cout << "The Distance from " << location1 << " to " << location2 << " is " << haversine(lat1,long1,lat2,long2,earthRadius) << " miles." << endl;
    cout << "The Flight Time is " << getFlightTime(lat1,long1,lat2,long2) << " hours.\n" << endl;

    return 0;
}

/* greet user with quick desc about app's function
and present user with list of options with GPA
coordinates in lat, long format

- prompt user to select departure location
- present same list with exclusion of selected location
- prompt user to select destination location
- compute distance of locations using haversine formula
- once you compute distance, compute average flight time between the two points

- asin() = arcsine function
- sin() = sine function
- radius of earth = 3958.8 miles
- average passenger jet flies at 460-574 mph

- at least 10 locations with coordinates
- should not crash when invalid input
- haversine put in its own function in format:
- double haversine(double lat1, double long 1, double lat2, double long2, double radius
- flightTime should be function as well)


*/