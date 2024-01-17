#include<iostream>
using namespace std;

// function declarations
void q0(string, int, int); // final state
void q1(string, int, int);
void q2(string, int, int);
void q3(string, int, int);

// function definitions
void q0(string s, int i, int diff) { // final state
    if (i == s.size()) {
        cout << "The string is ";
        if (diff == 0) {
            cout << "accepted!\n";
        } else {
            cout << "not accepted!\n";
        }
        return;
    }

    if (s[i] == 'a') {
        q1(s, i+1, diff + 1);
    } else if (s[i] == 'b') {
        q2(s, i+1, diff - 1);
    }
}

void q1(string s, int i, int diff) {
    if (i == s.size()) {
        cout << "The string is not accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q0(s, i+1, diff);
    } else if (s[i] == 'b') {
        q3(s, i+1, diff - 1);
    }
}

void q2(string s, int i, int diff) {
    if (i == s.size()) {
        cout << "The string is not accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q3(s, i+1, diff + 1);
    } else if (s[i] == 'b') {
        q0(s, i+1, diff);
    }
}

void q3(string s, int i, int diff) {
    if (i == s.size()) {
        cout << "The string is not accepted!\n";
        return;
    }

    if (s[i] == 'a') {
        q2(s, i+1, diff - 1);
    } else if (s[i] == 'b') {
        q1(s, i+1, diff);
    }
}

int main() {
    string str;

    cout << "Enter the string: ";
    cin >> str;

    q0(str, 0, 0);

    return 0;
}
