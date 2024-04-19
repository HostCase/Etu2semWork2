
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
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
        next = new list;
        next->data = rand() % 100;
        next->next = nullptr;
        next->prev = curr;
        if (curr) {
            curr->next = next;
        }
        curr = next;
    }
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
    while (curr) {
        cout << "Data: " << curr->data <<endl;

        curr = curr->next;
    }
    cout << endl;
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

list* createListInputMainFunc(list* curr = nullptr) {
    int data;
    vector<int> numbers = readNumbersFromConsole();
    for (int number : numbers) {
        list* next = new list;
        next->data = number;
        next->prev = curr;
        if (curr) {
            curr->next = next;
        }
        curr = next;
    }
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
            showToList(start);
            break;
        }
        case 4: {
            if (listcreated == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            showToList(start);
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
