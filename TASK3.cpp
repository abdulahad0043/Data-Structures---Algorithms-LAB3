#include <iostream>

using namespace std;


template <typename Type>
class CustomList {
private:
    Type *arr;
    int maxSize;
    int currentSize;

public:
   
    CustomList(int size = 10) : maxSize(size), currentSize(0) {
        arr = new Type[maxSize];
    }

    
    ~CustomList() {
        delete[] arr;
    }

    // Add element at the last index
    void addElement(Type value) {
        if (currentSize == maxSize) {
            cout << "List is full!" << endl;
            return;
        }
        arr[currentSize++] = value;
    }

    // Function to check prime numbers
    bool isPrime(Type num) {
        if (num < 2) return false;
        for (Type i = 2; i * i <= num; i++)
            if (num % i == 0)
                return false;
        return true;
    }

    // Sum of all prime numbers in the list
    Type sum_ofPrime() {
        Type sum = 0;
        for (int i = 0; i < currentSize; i++)
            if (isPrime(arr[i]))
                sum += arr[i];
        return sum;
    }

    // Find second maximum even number
    Type secondMaxEven() {
        Type max1 = -1, max2 = -1;
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] % 2 == 0) {
                if (arr[i] > max1) {
                    max2 = max1;
                    max1 = arr[i];
                } else if (arr[i] > max2 && arr[i] != max1) {
                    max2 = arr[i];
                }
            }
        }
        return max2;
    }

    // Find second minimum odd number
    Type secondMinOdd() {
        Type min1 = 100000, min2 = 100000;
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] % 2 != 0) {
                if (arr[i] < min1) {
                    min2 = min1;
                    min1 = arr[i];
                } else if (arr[i] < min2 && arr[i] != min1) {
                    min2 = arr[i];
                }
            }
        }
        return min2;
    }

    // Function to print duplicate elements
    void printDuplicates() {
        cout << "Duplicate Elements: ";
        for (int i = 0; i < currentSize; i++) {
            for (int j = i + 1; j < currentSize; j++) {
                if (arr[i] == arr[j]) {
                    cout << arr[i] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }

    // Print the list
    void printList() {
        for (int i = 0; i < currentSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// **Main Function for Task 3 (Testing)**
int main() {
    CustomList<int> myCustomList(10);
    myCustomList.addElement(3);
    myCustomList.addElement(5);
    myCustomList.addElement(3);
    myCustomList.addElement(7);
    myCustomList.addElement(10);
    myCustomList.addElement(2);
    myCustomList.addElement(8);

    cout << "List contents: ";
    myCustomList.printList();

    cout << "Sum of Primes: " << myCustomList.sum_ofPrime() << endl;
    cout << "Second Maximum Even: " << myCustomList.secondMaxEven() << endl;
    cout << "Second Minimum Odd: " << myCustomList.secondMinOdd() << endl;
    
    myCustomList.printDuplicates();

    return 0;
}
