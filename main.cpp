#include <iostream>
#include <cstdlib>
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
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void checkForNumbers() {
    char a = cin.get();
    while ((a < '0' || a > '9') && a != '-' && a != '+') {
        cout << "Enter NUMBERS!: ";
        cin >> a;
    }
    cin.unget();
}

list* createListInputMainFunc(list* curr = nullptr) {
    checkForNumbers();
    int data;
    if ((cin.get() != '\n') && ((cin.unget()) >> data)) {
        list* next = new list;
        next->data = data;
        next->prev = curr;
        if (curr) curr->next = next;
        return createListInputMainFunc(next);
    }
	else {
		delete curr;
		return nullptr;
	}
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
            start=createListInputMainFunc();
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
