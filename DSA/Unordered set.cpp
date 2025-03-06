#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // Unordered set does not allow duplicate values
    unordered_set<int> s;

    // Insert values into the unordered set
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3); // Duplicate value, will not be added again

    // Print the unordered set elements
    cout << "Unordered set elements:" << endl;
    for (auto i : s) {
        cout << i << endl;
    }

    // Unordered set does not support reverse iteration or ordered bounds
    cout << "Unordered set does not support ordered printing or bounds operations." << endl;

    // Check for an element in the unordered set
    cout << "Checking presence of element 2:" << endl;
    if (s.find(2) != s.end()) {//It return the end element if not found
        cout << "Element 2 is present" << endl;
    } else {
        cout << "Element 2 is not present" << endl;
    }

    // Erase an element from the unordered set
    s.erase(2);
    cout << "The set after erasing element 2:" << endl;
    for (auto i : s) {
        cout << i << endl;
    }

    cout << "The size of the set is: " << s.size() << endl;

    // Create another unordered set for demonstration
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(4);
    us.insert(4); // Duplicate value, will not be added again

    cout << "The unordered set after insertion:" << endl;
    for (auto i : us) {
        cout << i << endl;
    }
    cout<<"Other way to print this is given below "<<endl;
for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}
