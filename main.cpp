#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <iomanip>
#include <chrono>
using namespace std;

struct list {
    int data;
    list* next;
    list* prev;
};

void createListRND(list*& curr, int& length) {
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

void addToList(list*&start, int& length) {
    int newElIndex = -100;
    list* next = nullptr;
    cout << "Enter index of element(new will be added after this)" << endl;
    cout << "Or 1, new element will take place at first position " << endl;
    while (newElIndex < 1 || newElIndex > length) {
        cout << "0<index<=" << length << endl;
        cin >> newElIndex;
    }
    newElIndex -= 1;
    auto startTime = chrono::high_resolution_clock::now();
    list* curr = start;
    if (newElIndex) {
        for (int i = 1; i <= newElIndex; ++i) {
            curr = curr->next;
        }
        next = curr->next;
    }
    else {
        next = start;
    }
    list* currnew = new list;
    newElIndex ? currnew->prev = curr : currnew->prev = nullptr;
    newElIndex ? curr->next = currnew : start = currnew;
    cout << "Enter value for new element" << endl;
    cin >> currnew->data;
    if (next) {
        currnew->next = next;
        next->prev = currnew;
    }
    else
        currnew->next = nullptr;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - startTime);
    cout << "Time taken adding new element: " << duration.count() << " microseconds" << endl;
    length += 1;
}

void showToList(list* start, int length) {
    list* curr = start;
    int i = 1;
    cout << "/////////////" << endl;
    while (curr) {
        cout<<"index "<< i<<"   " << right << setw(7) << curr->data << endl;
        curr = curr->next;
        i += 1;
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

void createListInputMainFunc(list*& curr, int & length) {
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

void swaplist(list*& start,int length) {
    cout << "Enter index of first element to swap" << endl;
    int index1 = 0;
    cin >> index1;
    cout << "Enter index of second element to swap" << endl;
    int index2 = 0;
    cin >> index2;
    if (index1 == index2 || index1 < 0 || index1 > length || index2 < 0 || index2 > length) return;
    list* node1 = nullptr, * node2 = nullptr, * prev1 = nullptr, * prev2 = nullptr;
    list* curr = start;
    int count = 0;
    index1 -= 1;
    index2 -= 1;
    auto start_time = std::chrono::high_resolution_clock::now();
    while (curr != nullptr) {
        if (count == index1) {
            node1 = curr;
            if (curr->prev != nullptr) prev1 = curr->prev;
        }
        else if (count == index2) {
            node2 = curr;
            if (curr->prev != nullptr) prev2 = curr->prev;
        }
        curr = curr->next;
        count++;
    }

    if (node1 != nullptr && node2 != nullptr) {
        if (prev1 != nullptr) prev1->next = node2;
        if (prev2 != nullptr) prev2->next = node1;

        curr = node1->next;
        node1->next = node2->next;
        node2->next = curr;

        if (node1->next != nullptr) node1->next->prev = node1;
        if (node2->next != nullptr) node2->next->prev = node2;

        curr = node1->prev;
        node1->prev = node2->prev;
        node2->prev = curr;

        if (index1 == 0) start = node2;
        if (index2 == 0) start = node1;
    }

    auto stop_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}


void removebyindex(list*&start, int& length) {
    int index=-100;
    cout << "Enter index of element" << endl;
    while (index < 0 || index > length) {
        cout << "0<Index< " << length << endl;
        cin >> index;
    }
    auto startTime = chrono::high_resolution_clock::now();
    list* curr = start;
    index -= 1;
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

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - startTime);
    cout << "Time taken removing element: " << duration.count() << " microseconds" << endl;
    length--;
}

void removeByValue(list*& start, int& length) {
    int value;
    cout << "Enter value of element to remove:" << endl;
    cin >> value;

    list* curr = start;
    auto startTime = chrono::high_resolution_clock::now();
    if (curr != nullptr && curr->data == value) {
        start = curr->next;
        if (curr->next != nullptr)
            curr->next->prev = nullptr;
        delete curr;
        length--;
        return;
    }

    while (curr != nullptr && curr->data != value) {
        curr = curr->next;
    }

    if (curr == nullptr) return;

    list* next = curr->next;
    if (curr->prev != nullptr)
        curr->prev->next = next;
    if (next != nullptr)
        next->prev = curr->prev;

    delete curr;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - startTime);
    cout << "Time taken removing element: " << duration.count() << " microseconds" << endl;
    length--;
}

void deleteList(list*& start,int& length) {
    list* curr = start;
    while (curr) {
        list* next = curr->next;
        delete curr;
        curr = next;
    }
    length = 0;
    start = nullptr;
}

void getvaluebyindex(list* start, int length) {
    int index = -100;
    cout << "Enter index of element" << endl;
    while (index < 0 || index >= length) {
        cout << "0 <= Index < " << length << endl;
        cin >> index;
    }
    index -= 1;
    auto startTime = chrono::high_resolution_clock::now();
    list* curr = start;
    for (int i = 0; curr != nullptr && i < index; i++)
        curr = curr->next;

    if (curr == nullptr)
        return;

    cout << "Element = " << curr->data << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - startTime);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}

void getByValue(list* start) {
    int value, countelem(0), countall(1);
    vector<int> indexElements;
    cout << "Enter value of element:" << endl;
    cin >> value;
    auto startTime = chrono::high_resolution_clock::now();
    list* curr = start;

    while (curr != nullptr) {
        if (curr->data == value) {
            countelem += 1;
            indexElements.push_back(countall);
        }
        curr = curr->next;
        countall += 1;
    }

    if (countelem == 0) {
        cout << "Element with this value not found." << endl;
        return;
    }
    for (int number : indexElements) {
        cout << "Element founded: " << number << endl;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - startTime);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}

void shakerSortArra(int* arr, int count) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < count - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        for (int i = count - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void shakerSort(list*& start) {
    if (start == nullptr || start->next == nullptr)
        return;

    int count = 0;
    list* curr = start;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    int* arr = new int[count];

    curr = start;
    for (int i = 0; i < count; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }
    auto startTime = chrono::high_resolution_clock::now();
    shakerSortArra(arr, count);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - startTime);
    cout << "Time taken sorting arr: " << duration.count() << " microseconds" << endl;


    startTime = std::chrono::high_resolution_clock::now();
    bool swapped;
    do {
        swapped = false;
        list* curr = start;
        while (curr->next != nullptr) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }

        if (!swapped)
            break;

        swapped = false;
        while (curr->prev != nullptr) {
            if (curr->data < curr->prev->data) {
                swap(curr->data, curr->prev->data);
                swapped = true;
            }
            curr = curr->prev;
        }
    } while (swapped);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - startTime);
    cout << "Time taken sorting list: " << duration.count() << " microseconds" << endl;
}

int main() {
    list* start = nullptr;
    int choice = 0;
    int length = 0;
    bool listcreated = false;
    bool listcreatedandreadyforwork = false;
    do {
        if (!listcreated) {
            cout << "You should create a new list\n";
        }
        if (!length& listcreated) {
            deleteList(start,length);
            listcreated = false;
            listcreatedandreadyforwork = false;
            cout << "List was deleted automaticly because it had 0 elements \n";
            cout << "You should create a new list\n";
        }
        cout << "\nChoose\n";
        cout << "1. Random list generation\n";
        cout << "2. Manual list generation\n";
        cout << "3. Show list\n";
        cout << "4. Add to list\n";
        cout << "5. Remove from list\n";
        cout << "6. Clear list\n";
        cout << "7. Swap el of list\n";
        cout << "8. Get value by index\n";
        cout << "9. Get value by value\n";
        cout << "10. Shaker sort(idz2)\n";
        cout << "11. Exit\n";
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
            showToList(start, length);
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
            int choosef;
            cout << "Choose what you want\nEnter 1 - By index\nEnter 2 - By value" << endl;
            cin >> choosef;
            system("cls");
            switch(choosef){
            case 1: {
                
                removebyindex(start, length);
                break;
            }
            case 2: {
                removeByValue(start, length);
                break;
            }
            }
            break;
        }
        case 6: {
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!length) {
                cout << "List is empty" << endl;
                break;
            }
            deleteList(start, length);
            start = nullptr;
            bool listcreated = false;
            bool listcreatedandreadyforwork = false;
            break;
        }
        case 7: {
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!length) {
                cout << "List is empty" << endl;
                break;
            }
            swaplist(start, length);
            break;
        }
        case 8: {
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!length) {
                cout << "List is empty" << endl;
                break;
            }
            getvaluebyindex(start, length);
            break;
        }
        case 9: {
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!length) {
                cout << "List is empty" << endl;
                break;
            }
            getByValue(start);
            break;
        }
        case 10: {
            if (listcreatedandreadyforwork == false) {
                cout << "Error. The list no exists\n";
                break;
            }
            if (!length) {
                cout << "List is empty" << endl;
                break;
            }
            shakerSort(start);
            break;
        }
              
        case 11: {
            cout << "Exit";
            break;
        }
        default: {
            cout << "Invalid choice\n";
            break;
        }
        }
    } while (choice != 11);

    return 0;
}
