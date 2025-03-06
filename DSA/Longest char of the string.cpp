#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the sentence: ";
    cin >> n;
    cin.ignore(); // To ignore the newline character after the size input

    char sentence[n];
    cout << "Enter the sentence: ";
    cin.getline(sentence, n);

    int maxLength = 0, currentLength = 0;

    for (int i = 0; i <= n; ++i) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }                   
            currentLength = 0;
        } else {
            currentLength++;
        }
    }

    cout << "The max length of a word is: " << maxLength << endl;

    return 0;
}
