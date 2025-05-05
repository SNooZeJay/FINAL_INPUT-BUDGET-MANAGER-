#include <iostream>
#include <windows.h>  // For system("cls")
#include "header2.h"

using namespace std;

int main() {
    Budget myBudget;
    int choice;

    do {
        system("cls");  // Clear screen before showing menu

        while (true) {
            cout << "\n--- Budget Manager Menu ---\n";
            cout << "1. Add Expense\n";
            cout << "2. Edit Expense\n";
            cout << "3. Delete Expense\n";
            cout << "4. View Expenses\n";
            cout << "5. Set Saving Goal\n";
            cout << "6. Check Saving Status\n";
            cout << "7. Delete Saving Goal\n";
            cout << "8. Delete All Data\n";
            cout << "0. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                Sleep(1500);
                system("cls");
            } else {
                break;
            }
        }

        if (choice == 1) {
            string name;
            double amount;
            cout << "Enter expense name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter amount: ";
            cin >> amount;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                Sleep(1500);
                continue;
            }
            myBudget.addExpense(name, amount);
            Sleep(1500);
        }
        else if (choice == 2) {
            if (myBudget.getTotal() == 0) {
                cout << "No expenses to edit.\n";
                Sleep(1500);
                continue;
            }
            myBudget.displayExpenses();
            int index;
            cout << "Enter expense number to edit: ";
            cin >> index;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                Sleep(1500);
                continue;
            }
            string name;
            double amount;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new amount: ";
            cin >> amount;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                Sleep(1500);
                continue;
            }
            myBudget.editExpense(index - 1, name, amount);
            Sleep(1500);
        }
        else if (choice == 3) {
            if (myBudget.getTotal() == 0) {
                cout << "No expenses to delete.\n";
                Sleep(1500);
                continue;
            }
            myBudget.displayExpenses();
            int index;
            cout << "Enter expense number to delete: ";
            cin >> index;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                Sleep(1500);
                continue;
            }
            myBudget.deleteExpense(index - 1);
            Sleep(1500);
        }
        else if (choice == 4) {
            myBudget.displayExpenses();
            system("pause");
        }
        else if (choice == 5) {
            double goal;
            cout << "Enter saving goal: ";
            cin >> goal;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, please try again.\n";
                Sleep(1500);
                continue;
            }
            myBudget.setSavingGoal(goal);
            Sleep(1500);
        }
        else if (choice == 6) {
            myBudget.checkSavings();
            system("pause");
        }
        else if (choice == 7) {
            myBudget.deleteSavingGoal();
            Sleep(1500);
        }
        else if (choice == 8) {
            myBudget.deleteAllData();
            Sleep(1500);
        }
        else if (choice == 0) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid input, please try again.\n";
            Sleep(1500);
        }

    } while (choice != 0);

    return 0;
}
