#include <iostream>
#include <string>

using namespace std;


template <typename T>
class MySet {
private:
    T* elements;
    size_t count;
    size_t capacity;

    bool contains(const T& item) const {
        for (size_t i = 0; i < count; ++i) {
            if (elements[i] == item) {
                return true;
            }
        }
        return false;
    }

    void resize(size_t new_capacity) {
        if (new_capacity <= capacity) {
            return;
        }

        T* new_elements = new T[new_capacity];
        for (size_t i = 0; i < count; ++i) {
            new_elements[i] = elements[i];
        }

        delete[] elements;
        elements = new_elements;
        capacity = new_capacity;
    }

    void add_internal(const T& item) {

        if (count == capacity) {
            size_t new_cap;
            if (capacity == 0) {
                new_cap = 10;
            } else {
                new_cap = capacity * 2;
            }
            resize(new_cap);
        }
        elements[count] = item;
        count++;
    }

public:
    MySet() : elements(nullptr), count(0), capacity(0) {}

    ~MySet() {
        delete[] elements;
    }

    MySet(const MySet& other) : elements(nullptr), count(0), capacity(0) {
        if (other.capacity > 0) {
            elements = new T[other.capacity];
            capacity = other.capacity;
            count = other.count;

            for (size_t i = 0; i < count; ++i) {
                elements[i] = other.elements[i];
            }
        }
    }

    MySet& operator=(const MySet& other) {
        if (this == &other) {
            return *this;
        }

        delete[] elements;
        elements = nullptr;
        count = 0;
        capacity = 0;

        if (other.capacity > 0) {
            elements = new T[other.capacity];
            capacity = other.capacity;
            count = other.count;

            for (size_t i = 0; i < count; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    MySet operator+(const T& item) const {
        MySet result = *this;
        if (!result.contains(item)) {
            result.add_internal(item);
        }
        return result;
    }

    MySet operator+(const MySet& other) const {
        MySet result = *this;
        for (size_t i = 0; i < other.count; ++i) {
            if (!result.contains(other.elements[i])) {
                result.add_internal(other.elements[i]);
            }
        }
        return result;
    }

    bool operator==(const MySet& other) const {
        if (this->count != other.count) {
            return false;
        }
        for (size_t i = 0; i < this->count; ++i) {
            if (!other.contains(this->elements[i])) {
                return false;
            }
        }
        return true;
    }

    void input() {
        delete[] elements;
        elements = nullptr;
        count = 0;
        capacity = 0;

        int n;
        cout << "Enter how much elements in set: ";
        cin >> n;

        if (n <= 0) return;

        cout << "Enter elements of set: (" << n << " elements): ";
        T elem;
        for (int i = 0; i < n; ++i) {
            cin >> elem;

            if (!this->contains(elem)) {
                this->add_internal(elem);
            }
        }
    }

    void display() const {
        cout << "{ ";
        bool first = true;
        for (size_t i = 0; i < count; ++i) {
            if (!first) {
                cout << " ";
            }
            cout << elements[i];
            first = false;
        }
        cout << " }" << endl;
    }


    size_t get_size() const {
        return count;
    }
};


int main() {
    MySet<int> set1, set2, result;

    cout << "Enter the first set (int):" << endl;
    set1.input();

    cout << "Enter the second set (int):" << endl;
    set2.input();

    cout << "\n--- Operation Demonstration ---" << endl;

    cout << "First set: "; set1.display();
    cout << "Second set: "; set2.display();

    int newItem;

    cout << "Enter an element to add to the first set: ";
    cin >> newItem;


    result = set1 + newItem;

    cout << "First set + " << newItem << ": ";
    result.display();

    result = set1 + set2;

    cout << "Union of the first and second sets: ";
    result.display();

    if (set1 == set2) {

        cout << "Sets are equal." << endl;
    } else {

        cout << "Sets are not equal." << endl;
    }


    // --- String Example ---
    MySet<string> setStr1, setStr2, resultStr;

    cout << "\nEnter the first set (string):" << endl;
    setStr1.input();

    cout << "Enter the second set (string):" << endl;
    setStr2.input();

    cout << "\n--- Operation Demonstration for strings ---" << endl;

    cout << "First string set: "; setStr1.display();
    cout << "Second string set: "; setStr2.display();

    string newStrItem;

    cout << "Enter an element (string) to add to the first set: ";
    getline(cin, newStrItem);


    resultStr = setStr1 + newStrItem;

    cout << "First string set + \"" << newStrItem << "\": ";
    resultStr.display();

    resultStr = setStr1 + setStr2;

    cout << "Union of the first and second string sets: ";
    resultStr.display();

    if (setStr1 == setStr2) {

        cout << "String sets are equal." << endl;
    } else {

        cout << "String sets are not equal." << endl;
    }

    return 0;
}