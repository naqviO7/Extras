#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool ispalindrome(string aString);

int main() {
    string astring;
    cout << "Enter String: ";
    cin >> astring;

    if (ispalindrome(astring) == true) {
        cout << astring << " is Palindrome!\n";
    }
    else {
        cout << astring << " is Not Palindrome!\n";
    }
    system("pause");
}

bool ispalindrome(string aString) {
    deque<char> chardeque;
    int strLen = aString.length();
    for (int i = 0; i < strLen; i++) {
        //pushes each char in the string to the deque.
        chardeque.push_back(aString[i]);
    }

    bool stillEqual = true;

    while (chardeque.size() > 1 && stillEqual) {
        char first = chardeque.front();
        chardeque.pop_front();
        char last = chardeque.back();
        chardeque.pop_back();
        if (first != last) { //if the two opposite positions of the
                             //word is not the same, then it is not
                             //a palindrome.
            stillEqual = false;
        }
    }
    return stillEqual;
}