/*#include <iostream>
using namespace std;

void function(int arr[4][4], int a[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int b = arr[i][j];
            bool found = false;
            // Check if the element repeats in the array
            for(int k = 0; k < 4; k++) {
                for(int l = 0; l < 4; l++) {
                    if(b == arr[k][l] && (i != k || j != l)) { // Check if the element repeats in the array
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            // Check if the element is already stored in a
            bool alreadyStored = false;
            for(int m = 0; m < 4; m++) {
                for(int n = 0; n < 4; n++) {
                    if(a[m][n] == b) {
                        alreadyStored = true;
                        break;
                    }
                }
                if(alreadyStored) break;
            }
            // If the element repeats in arr and is not already stored in a, store it
            if(found && !alreadyStored) {
                for(int m = 0; m < 4; m++) {
                    for(int n = 0; n < 4; n++) {
                        if(a[m][n] == 0) {
                      
                            a[m][n] = b;
                            break;
                        }
                    }
                }
            }
        }
    }
    // Reset the repeated elements in array a to 0
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int b1 = a[i][j];
            bool found = false;
            for(int k = i; k < 4; k++) {
                for(int l = 0; l < 4; l++) {
                    if(b1 == a[k][l] && (i != k || j != l)) {
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) {
                a[i][j] = 0; // Set repeated element to 0
            }
        }
    }
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 1},   
        {7, 8, 9, 90},   
        {2, 10, 4, 0},   
        {6, 6, 5, 4}    
    };

    cout << "Original array:\n";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    int a[4][4] = {0}; // Initialize a to all zeros
    function(arr, a);

    cout << "\nArray with repeated elements printed once:\n";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    
    return 0;
}

*/
/*
#include<iostream>
using namespace std;
class Array{
int * a;//dynamic array
int cap;//capacity (total space in the array)
int n; //size (number of elements inserted)
public:
// Implementation here
Array(){
    n=0;
    cap=0;
    a=NULL;
}
void reverseInRange(int start, int end) {
    while (start < end) {
        swap(a[start], a[end]);
        start++; // Increment start index
        end--;   // Decrement end index
    }
}

void insert(int element) {
    if (n >= cap) {
        if (cap == 0) {
            cap = 1;
        } else {
            cap *= 2;
        }
        int *newarr = new int[cap];
        for (int i = 0; i < n; i++) {
            newarr[i] = a[i];
        }
        delete[] a;
        a = newarr;
    }
    a[n++] = element;
}

Array(int tem[],int b,int c){
     if (b > c) {
            cout << "Error: Size cannot be greater than capacity\n";
            return;
        }
    a=new int[c];
    for(int i=0;i<n;i++){
        a[i]=tem[i];
    }
    cap=c;
    n=b;
}
void print(){
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}
};

int main()
{
int temp[]={12,4,6,11,5};
Array A; // make an empty array of capacity 0
Array B(temp,5,10);
/*
Make an array with size 5 and capacity 10. If no capacity is specified or capacity
is less than size, then set capacity equal to size, and allocate the array of
that capacity. */
/*
int n, input;
cin>>n;
for(int i=0;i<n;i++){
cin>>input;
A.insert(input);
/*
Insert puts the new integer at the next available index
in the array. If size exceeds capacity then, a new array
of double capacity is allocated, data is copied into it
and the older array is de-allocated. */
/*
}
A.print();
A.reverseInRange(0,4);
A.print();
/*
The order of all elements in the given range is reversed, keeping the remaining Elements
un-disturbed. For example, if the array contained 2,6,8,4,1,13,7,5, then after this call
it will become: 2,5,8,7,1,13,4,6 (notice the elements in bold have been reversed) */
/*
return 0;
}*/
/*
#include <iostream>
using namespace std;

template<typename T>
int findIndex(T a[], int size, const T& b) {
    for(int i = 0; i < size; i++) {
        if (a[i] == b)
            return i;
    }
    return -1;
}

template<typename T>
int findIndex(T* a[], int size, const T* b) {
    for(int i = 0; i < size; i++) {
        if (*a[i] == *b)
            return i;
    }
    return -1;
}

int main() {
    int a[] = {2, 3, 5, 8};
    char b[] = {'H', 'e', 'l', 'l', 'o'};
    const char* c[] = {"cd", "lion", "zoo"};

    cout << "Index = " << findIndex<int>(a, 4, 3) << endl;
    cout << "Index = " << findIndex<char>(b, 5, 'l') << endl;
    cout << "Index = " << findIndex<const char*>(c, 3, c[1]) << endl;

    return 0;
}
*/
#include <iostream>
using namespace std;

class Tool {
protected:
    int strength;

public:
    Tool(int str) : strength(str) {}
    virtual ~Tool() {}

    virtual bool fight(Tool&) = 0; // Pure virtual function
    virtual const char* getWhoAmI() const = 0; // Pure virtual function

    int getStrength() const {
        return strength;
    }
};

class Rock : public Tool {
public:
    Rock(int str) : Tool(str) {}

    bool fight(Tool& opponent) override {
        if (opponent.getStrength() > strength / 2)
            return false; // Opponent wins
        return true; // Rock wins
    }

    const char* getWhoAmI() const override {
        return "Rock";
    }
};

class Paper : public Tool {
public:
    Paper(int str) : Tool(str * 2) {}

    bool fight(Tool& opponent) override {
        if (opponent.getStrength() > strength / 2)
            return false; // Opponent wins
        return true; // Paper wins
    }

    const char* getWhoAmI() const override {
        return "Paper";
    }
};

class Scissors : public Tool {
public:
    Scissors(int str) : Tool(str * 5 / 2) {}

    bool fight(Tool& opponent) override {
        if (opponent.getStrength() > strength / 2)
            return false; // Opponent wins
        return true; // Scissors win
    }

    const char* getWhoAmI() const override {
        return "Scissors";
    }
};

int main() {
    Tool *tools[3];
    Scissors s1(5);
    Paper p1(7);
    Rock r1(15);
    tools[0] = &r1;
    tools[1] = &p1;
    tools[2] = &s1;

    int choice1 = 0, choice2 = 0;
    cout << "1: Rock (r)\n";
    cout << "2: Paper (p)\n";
    cout << "3: Scissors (s)\n";
    cout << "Enter the choices for the two contestants to fight and -1 to end:\n";
    cin >> choice1;

    while (choice1 != -1) {
        cin >> choice2;
        cout << tools[choice1 - 1]->getWhoAmI() << " vs " << tools[choice2 - 1]->getWhoAmI() << endl;

        if (tools[choice1 - 1]->fight(*tools[choice2 - 1])) {
            cout << tools[choice1 - 1]->getWhoAmI() << " won! " << endl;
        } else {
            cout << tools[choice1 - 1]->getWhoAmI() << " lost! " << endl;
        }

        cout << "Enter the choices for the two contestants to fight and -1 to end:\n";
        cin >> choice1;
    }

    return 0;
}

