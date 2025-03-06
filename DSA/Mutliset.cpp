#include<iostream>
#include<set>
using namespace std;

int main() {
    // Multiset allows duplicate values
    multiset<int> s;

    // Insert values into the multiset
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    // Print the multiset elements
    cout << "Multiset elements in ascending order:" << endl;
    for (auto i : s) {
        cout << i << endl;
    }

    cout << "2nd way to print is given below " << endl;
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }

    cout << "Opposite printing of the set (descending order) is given below " << endl;
    for (auto i = s.rbegin(); i != s.rend(); i++) {
        cout << *i << endl;
    }

    // Create another multiset for testing lower_bound and upper_bound
    multiset<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(4);
    st.insert(4);
    st.insert(4);

    cout << "The output for the lower and upper bound:" << endl;

    // Lower and upper bounds in a multiset
    cout << *st.lower_bound(0) << endl; // Returns the first element >= 0, which is 1
    cout << *st.lower_bound(3) << endl; // Returns the first element >= 3, which is 4
    cout << *st.upper_bound(0) << endl; // Returns the first element > 0, which is 1
    cout << *st.upper_bound(1) << endl; // Returns the first element > 1, which is 2

    // Check for upper_bound when no element is greater than the given value
    if (st.upper_bound(5) != st.end()) {
        cout << *st.upper_bound(5) << endl;
    } else {
        cout << "No element greater than 5" << endl; // Since there is no element > 5, output a message
    }

    // Print the multiset before erasing elements
    cout << "The set before erasing the element from it:" << endl;
    for (auto i : st) {
        cout << i << endl;
    }

    // Erase all occurrences of '4' from the multiset
    st.erase(4);

    cout << "The output after the erasing is given below:" << endl;
    for (auto i : st) {
        cout << i << endl;
    }

    cout << "The size of the set is: " << st.size() << endl;

    // Multiset with duplicate values
    multiset<int> mst;
    mst.insert(1);
    mst.insert(2);
    mst.insert(4);
    mst.insert(4);
    mst.insert(4);

    // Erase only one occurrence of '4' from the multiset
    mst.erase(mst.find(4));

    cout << "The multiset after erasing one occurrence of '4' is given as:" << endl;
    for (auto i : mst) {
        cout << i << endl;
    }

    return 0;
}
