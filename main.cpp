
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <chrono>
using namespace std;

struct list {
    int data;
    list* next;
    list* prev;
};

list* createListRND() {
    list* curr = nullptr;
    list* next = nullptr;
    cout << "Enter length:";
    int length;
    cin >> length;
    for (int i = 1; i <= length; ++i)
    {
        curr = new list;
        curr->data = rand() % 100;
        curr->next = next;
        if (next) {
            next->prev = curr;
        }
        next = curr;
    }
    curr->prev = 0;
    
    return curr;
}

void addToList(list* start) {
    list* curr = start;
    while (curr) {
        cin >> curr->data;
        curr = curr->next;
    }
}

void showToList(list* start) {
    list* curr = start;
    cout << "/////////////" << endl;
        
    while (curr) {
        //cout <<curr->data <<endl;
        cout << right << setw(7) << curr->data << endl;
        curr = curr->next;
    }
    cout << "/////////////" << endl;
}

vector<int> readNumbersFromConsole() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);
    vector<int> numbers;
    stringstream ss(input);
    int number;
    while (ss >> number) {
        numbers.push_back(number);
    }

    return numbers;
}

list* createListInputMainFunc() {
    list* curr = nullptr;
    list* next = nullptr;
    vector<int> numbers = readNumbersFromConsole();
    for (int number : numbers) {
        curr = new list;
        curr->data = number;
        curr->next = next;
        if (next) {
            next->prev = curr;
        }
        next = curr;
    }
    curr->prev = 0;
    return curr;
}

int main() {
    list* start = nullptr;
    int choice = 0;
    bool listcreated = false;
    do {
        cout << "Choose\n";
        cout << "1. Random list generation\n";
        cout << "2. Manual list generation\n";
        cout << "3. Show list\n";
        cout << "4. ?\n";
        cout << "10. Exit\n";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            start = createListRND();
            listcreated = true;
            break;
        }
        case 2: {
            cout << "Enter numbers (separated by spaces): ";
            start = createListInputMainFunc();
            listcreated = true;
            break;
        }
        case 3: {
            if (listcreated == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!start) {
                cout << "List is empty" << endl;
                break;
            }
            showToList(start);
            break;
        }
        case 4: {
            if (listcreated == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!start) {
                cout << "List is empty" << endl;
                break;
            }
            showToList(start);
            break;
        }
        case 10: {
            cout << "Exit";
            break;
        }
        default: {
            cout << "Invalid choice\n";
            break;
        }
        }
    } while (choice != 10);

    return 0;
}
