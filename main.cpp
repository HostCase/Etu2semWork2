#include <iostream>
#include <cstdlib>
using namespace std;
struct list
{
    int data;
    list* head;
    list* tail;
};

list* createListRND(int length) {

    list* curr = 0;
    list* next = 0;

    for (int i = 1; i <= length; ++i)
    {
        curr = new list;
        *(curr)->tail= rand() % 100;
        curr->tail = next;
        if (next) {
            next->head = curr;
        }
        next = curr;
    }

    curr->head = 0;

    return curr;
};

void addToList(list* start, int length) {
    list* curr = start;
    for (int i = 1; i <= length; ++i) {
        cin >> curr->data;
        curr = curr->tail;
    }
}

void showToList(list* start, int length) {
    list* curr = start;
    for (int i = 1; i <= length; ++i) {
        cout << curr->data << " ";
        curr = curr->tail;
    }
}



int main() {
    int choice;
    bool listcreated = false;
    cout << "Choose\n";
    cout << "Random list generation\n";
    cin >> choice;
    switch(choice){
    case1: {
        if (listcreated = true) {
            cout << "Error. The sheet already exists\n";
            break;
        }
        int amount;
        cin >> amount;
        list* start = createListRND(amount);
        listcreated = true;
        break;
        }
    case 2:{
        if (listcreated = true) {
            cout << "Error. The sheet already exists\n";
            break;
        }

        listcreated = true;
    }
    }

    addToListrdn(start, amount);
    showToList(start, amount);
    return 0;
}