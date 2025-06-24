# ECGR 2104 C++ Mini Projects – Summer @ UNCC

These are mini projects I completed as part of ECGR 2104 at UNC Charlotte during the summer term to improve my proficiency in C++. Each project is written to handle invalid input gracefully and is self-contained for terminal-based usage.

> ⚠️ Note: While `using namespace std;` is generally discouraged in production code, it was used here for readability in the context of the course.

---

## Project Descriptions

### Slot Machine
- Terminal-based slot machine game with 4 slots.
- User starts with $10; each spin costs $1.
- Users can choose to spin or exit the program.
- Payouts are awarded for specific matches (e.g., 777, $$$, etc.).

### Magic 8 Ball
- Simulates a Magic 8 Ball using randomness.
- User inputs a question and receives a random answer: Yes, No, or Maybe.
- Random seed is generated using time to ensure varied responses.

### Dog Age Calculator
- Converts a dog’s age to human years.
- Uses conditionals to apply different formulas based on the dog’s age.

### Flight Calculator
- Calculates the great-circle distance and estimated flight time between two geographic locations.
- Implements a `Location` class with name, latitude, and longitude.
- Uses the Haversine formula for distance calculation.

### Employee Database
- Terminal-based employee management system.
- Displays employee names, job titles, and hourly wages.
- Calculates total wages and allows the user to exit.
- Uses an `Employee` class with private attributes and a vector to store employees.

### Nutrition Tracker
- Allows users to select foods from a pre-populated vector and calculate total nutritional intake.
- `Food` class split across header and implementation files.
- Overloads the `+` operator to sum nutritional values easily.

---

