#include <iostream>
#include <fstream>
#include "../header2.h"

using namespace std;

// Constructor: initializes count and loads saved data
Budget::Budget() {
    expenseCount = 0;
    savingGoal = 0;
    loadFromFile();
}

// Add a new expense if under limit
void Budget::addExpense(string name, double amount) {
    if (expenseCount < MAX_EXPENSES) {
        expenses[expenseCount].name = name;
        expenses[expenseCount].amount = amount;
        expenseCount++;
        cout << "Expense added.\n";
        saveToFile();
    } else {
        cout << "Maximum expenses reached.\n";
    }
}

// Edit an expense at a specific index
void Budget::editExpense(int index, string name, double amount) {
    if (index >= 0 && index < expenseCount) {
        expenses[index].name = name;
        expenses[index].amount = amount;
        cout << "Expense updated.\n";
        saveToFile();
    } else {
        cout << "Invalid input, please try again.\n";
    }
}

// Delete an expense at a specific index
void Budget::deleteExpense(int index) {
    if (index >= 0 && index < expenseCount) {
        for (int i = index; i < expenseCount - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        expenseCount--;
        cout << "Expense deleted.\n";
        saveToFile();
    } else {
        cout << "Invalid input, please try again.\n";
    }
}

// Display all expenses
void Budget::displayExpenses() {
    cout << "\n----- Expenses -----\n";
    for (int i = 0; i < expenseCount; i++) {
        cout << i + 1 << ". " << expenses[i].name << ": " << expenses[i].amount << endl;
    }
    cout << "Total Expenses: " << getTotal() << endl;
}

// Calculate total expenses
double Budget::getTotal() {
    double total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Set a saving goal
void Budget::setSavingGoal(double goal) {
    savingGoal = goal;
    cout << "Saving goal set to " << savingGoal << endl;
    saveToFile();
}

// Check if spending is within or over goal
void Budget::checkSavings() {
    double remaining = savingGoal - getTotal();
    if (savingGoal == 0) {
        cout << "No saving goal set.\n";
    } else if (remaining > 0) {
        cout << "You are within your saving goal. You can still spend " << remaining << endl;
    } else if (remaining == 0) {
        cout << "You have exactly met your saving goal.\n";
    } else {
        cout << "You have exceeded your saving goal by " << -remaining << endl;
    }
}

// Delete saving goal
void Budget::deleteSavingGoal() {
    if (savingGoal == 0) {
        cout << "No saving goal to delete.\n";
    } else {
        savingGoal = 0;
        cout << "Saving goal deleted.\n";
        saveToFile();
    }
}

// Save expenses and saving goal to a text file
void Budget::saveToFile() {
    ofstream file("budget_data.txt");
    file << expenseCount << endl;
    for (int i = 0; i < expenseCount; i++) {
        file << expenses[i].name << " " << expenses[i].amount << endl;
    }
    file << savingGoal << endl;
    file.close();
}

// Load expenses and saving goal from a text file
void Budget::loadFromFile() {
    ifstream file("budget_data.txt");
    if (file.is_open()) {
        file >> expenseCount;
        for (int i = 0; i < expenseCount; i++) {
            file >> expenses[i].name >> expenses[i].amount;
        }
        file >> savingGoal;
        file.close();
    }
}

// Delete all expenses and saving goal
void Budget::deleteAllData() {
    expenseCount = 0;
    savingGoal = 0;
    saveToFile();
    cout << "All data deleted.\n";
}
