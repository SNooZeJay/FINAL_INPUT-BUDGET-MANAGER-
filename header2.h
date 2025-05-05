#ifndef HEADER2_H
#define HEADER2_H

#include <string>
using namespace std;

const int MAX_EXPENSES = 10;

// Structure to store an expense
struct Expense {
    string name;
    double amount;
};

// Budget class definition
class Budget {
private:
    Expense expenses[MAX_EXPENSES];
    int expenseCount;
    double savingGoal;
public:
    Budget(); // Constructor: initializes data and loads from file
    void addExpense(string name, double amount); // Add a new expense
    void editExpense(int index, string name, double amount); // Edit an existing expense
    void deleteExpense(int index); // Delete an expense
    void displayExpenses(); // Show all expenses
    double getTotal(); // Calculate total expenses
    void setSavingGoal(double goal); // Set saving goal
    void checkSavings(); // Check if within or over saving goal
    void deleteSavingGoal(); // Remove saving goal
    void saveToFile(); // Save expenses and goal to file
    void loadFromFile(); // Load expenses and goal from file
    void deleteAllData(); // Delete all expenses and goal
};

#endif
