
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

void createListRND(list* curr,int & length) {
    list* next = nullptr;
    cout << "Enter length:";
    cin >> length;
    auto start = std::chrono::high_resolution_clock::now();
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
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
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
    cout << "Enter numbers (separated by spaces): ";
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

void createListInputMainFunc(list* curr, int & length) {
    list* next = nullptr;
    vector<int> numbers = readNumbersFromConsole();
    auto start = std::chrono::high_resolution_clock::now();
    for (int number : numbers) {
        curr = new list;
        length += 1;
        curr->data = number;
        curr->next = next;
        if (next) {
            next->prev = curr;
        }
        next = curr;
    }
    curr->prev = 0;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}




int main() {
    list* start = nullptr;
    int choice = 0;
    int length = 0;
    bool listcreated = false;//для создания листов и при удалении сделать шоб было фолз
    bool listcreatedandreadyforwork = false;// тут сделать шоб при удалении был тоже фолз
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
            if (listcreated == true) {
                cout << "Error. List already created. Delete it with func for delete\n";
                break;
            }
            createListRND(start, length);
            listcreated = true;
            listcreatedandreadyforwork = true;
            break;
        }
        case 2: {
            if (listcreated == true) {
                cout << "Error. List already created. Delete it with func for delete\n";
                break;
            }
            createListInputMainFunc(start, length);
            listcreated = true;
            listcreatedandreadyforwork = true;
            break;
        }
        case 3: {
            if (listcreatedandreadyforwork == false) {
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
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!start) {
                cout << "List is empty" << endl;
                break;
            }
            addToList(start);
            break;
        }
        case 5: {
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!start) {
                cout << "List is empty" << endl;
                break;
            }
            char choosef;
            cout << "Choose what you want\nEnter a - By index\nEnter b - By value" << endl;
            cin >> choosef;
            system("cls");
            switch(choosef){
            case 1: {
                
                removebyindex(start);
                break;
            }
            case 2: {
                removebyvalue(start);
                break;
            }
            }
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
