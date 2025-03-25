#include <iostream>

using namespace std;

// Task 2: Derived Class MyList
template <typename Type>
class MyList {
private:
    Type *arr;
    int maxSize;
    int currentSize;

public:
    // Constructor
    MyList(int size = 10) : maxSize(size), currentSize(0) {
        arr = new Type[maxSize];
    }

    // Destructor
    ~MyList() {
        delete[] arr;
    }

    // Add element at the first index
    void addElementAtFirstIndex(Type value) {
        if (currentSize == maxSize) {
            cout << "List is full!" << endl;
            return;
        }
        for (int i = currentSize; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = value;
        currentSize++;
    }

    // Add element at the last index
    void addElementAtLastIndex(Type value) {
        if (currentSize == maxSize) {
            cout << "List is full!" << endl;
            return;
        }
        arr[currentSize++] = value;
    }

    // Remove element from the last index
    Type removeElementFromEnd() {
        if (currentSize == 0) {
            cout << "List is empty!" << endl;
            return -1; // Assuming Type is an integer
        }
        return arr[--currentSize];
    }

    // Remove element from the first index
    void removeElementFromStart() {
        if (currentSize == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        for (int i = 0; i < currentSize - 1; i++)
            arr[i] = arr[i + 1];
        currentSize--;
    }

    // Check if list is empty
    bool empty() {
        return currentSize == 0;
    }

    // Check if list is full
    bool full() {
        return currentSize == maxSize;
    }

    // Get size of the list
    int size() {
        return currentSize;
    }

    // Search for an element
    bool search(Type value) {
        for (int i = 0; i < currentSize; i++)
            if (arr[i] == value)
                return true;
        return false;
    }

    // Print the list
    void printList() {
        for (int i = 0; i < currentSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// **Main Function for Task 2 (Testing)**
int main() {
    MyList<int> myList(5);
    myList.addElementAtFirstIndex(10);
    myList.addElementAtLastIndex(20);
    myList.addElementAtFirstIndex(30);
    
    cout << "List contents: ";
    myList.printList();
    
    cout << "List Size: " << myList.size() << endl;
    cout << "Is 10 present? " << (myList.search(10) ? "Yes" : "No") << endl;
    
    myList.removeElementFromEnd();
    cout << "List after removing last element: ";
    myList.printList();
    
    return 0;
}
