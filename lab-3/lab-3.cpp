#include<iostream>
using namespace std;


// function declarations
void q0(string, int); // final state
void q1(string, int);
void q2(string, int);
void q3(string, int);


// function definations
void q0(string s, int i) { // final state
    if (i == s.size()) {
        cout << "The string is accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q1(s, i+1);
    } else if (s[i] == 'b') {
        q2(s, i+1);
    }
}


void q1(string s, int i) {
    if (i == s.size()) {
        cout << "The string is not accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q0(s, i+1);
    } else if (s[i] == 'b') {
        q3(s, i+1);
    }
}


void q2(string s, int i) {
    if (i == s.size()) {
        cout << "The string is not accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q3(s, i+1);
    } else if (s[i] == 'b') {
        q0(s, i+1);
    }
}


void q3(string s, int i) {
    if (i == s.size()) {
        cout << "The string is not accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q2(s, i+1);
    } else if (s[i] == 'b') {
        q1(s, i+1);
    }
}


int main() {
    string str;

    cout << "Enter the string: ";
    cin >> str;

    q0(str, 0);

    return 0;
}