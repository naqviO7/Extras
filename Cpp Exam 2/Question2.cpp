#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    char ch;
    for (int i=0; i<expr.length(); i++) {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
            return false;
        switch (expr[i]) {
            case ')':
                ch = s.top();
                s.pop();
                if (ch=='{' || ch=='[')
                    return false;
                break;
            case '}':
                ch = s.top();
                s.pop();
                if (ch=='(' || ch=='[')
                    return false;
                break;
            case ']':
                ch = s.top();
                s.pop();
                if (ch =='(' || ch == '{')
                    return false;
                break;
        }
    }
    return (s.empty());
}

int main() {
    string expr = "[{}(){()}]";
    if (isBalanced(expr))
        cout << "Braces are Balanced";
    else
        cout << "Braces are Not Balanced";
}