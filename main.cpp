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
    delete next;
}

void addToList(list* start,int & length) {
    int newElIndex=-100;
    list* next = nullptr;
    cout << "Enter index of element(new will be added after this)" << endl;
    cout << "Or 0, new element will take place at 0 position " << endl;
    while (length >= newElIndex || newElIndex<0) {
        cout << "No more " << length << endl;
        cin >> newElIndex;
    }
    list* curr = start;
    if(newElIndex){
        for (int i = 1; i <= newElIndex; ++i) {
            curr = curr->next;
        }
        list* next = curr->next;
    }
    list* currnew = new list;
    newElIndex ? currnew->prev = curr : currnew->prev = nullptr;
    newElIndex ? curr->next = currnew : curr->prev = currnew;
    cout << "Enter value for new element" << endl;
    cin>>currnew->data;
    if (next) {
        currnew->next = next;
        (*next).prev = currnew;
    }
    else;
        currnew->next = nullptr;
    length += 1;
    delete curr, next;
}

void showToList(list* start) {
    list* curr = start;
    cout << "/////////////" << endl;
    int i = 1;
    while (curr) {
        cout<<i<<"." << right << setw(7) << curr->data << endl;
        curr = curr->next;
        i += 1;
    }
    cout << "/////////////" << endl;
    delete curr;
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
    delete next;
}

void removebyindex(list* start, int& length) {
    int index=-100;
    cout << "Enter index of element" << endl;
    while (length >= index || index < 0) {
        cout << "0<Index< " << length << endl;
        cin >> index;
    }

    list* curr = start;

    if (index == 0) {
        start = curr->next;
        if (curr->next != nullptr)
            curr->next->prev = nullptr;
        delete curr;
        length--;
        return;
    }

    for (int i = 0; curr != nullptr && i < index - 1; i++)
        curr = curr->next;

    if (curr == nullptr || curr->next == nullptr)
        return;

    list* next = curr->next->next;

    delete curr->next;

    curr->next = next;
    if (next != nullptr)
        next->prev = curr;

    length--;
}

int main() {
    list* start = nullptr;
    int choice = 0;
    int length = 0;
    bool listcreated = false;//��� �������� ������ � ��� �������� ������� ��� ���� ����
    bool listcreatedandreadyforwork = false;// ��� ������� ��� ��� �������� ��� ���� ����
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
            if (!length) {
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
            if (!length) {
                cout << "List is empty" << endl;
                break;
            }
            addToList(start, length);
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
                
                removebyindex(start, length);
                break;
            }
            case 2: {
                removebyindex(start, length);
                //removebyvalue(start, length);
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
