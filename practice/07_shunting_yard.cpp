// https://en.wikipedia.org/wiki/Shunting_yard_algorithm
#include <cassert>
#include <cctype>
#include <cstdio>
#include <queue>
#include <stack>

bool precedence(auto o1, auto o2) {
    int p1 = 0, p2 = 0;

    if (o1 == '+' || o1 == '-') p1 = 0;
    else if (o1 == '*' || o1 == '/') p1 = 1;
    else p1 = 2;

    if (o2 == '+' || o2 == '-') p2 = 0;
    else if (o2 == '*' || o2 == '/') p2 = 1;
    else p2 = 2;

    return (p2 >= p1);
}

using Q = std::queue<char>;
using S = std::stack<char>;

int main(void) {

    Q q;
    S s;

    char tokens[] = "(3+2)*2-5/5";

    size_t i = 0;
    while (tokens[i] != '\0') {
        char token = tokens[i];
        if (isalnum(token)) {
            q.push(token);
        } else if (token == '(') {
            s.push(token);
        } else if (token == ')') {
            while (s.top() != '(') { assert(!s.empty());
                q.push(s.top());
                s.pop();
            } assert(s.top() == '(');
            s.pop();
        } else {
            while (!s.empty() && s.top() != '(' && precedence(token, s.top())) {
                q.push(s.top());
                s.pop();
            }
            s.push(token);
        }
        i++;
    }
    while (!s.empty()) { assert('(' != s.top());
        q.push(s.top());
        s.pop();
    }

    for (; !q.empty(); q.pop()) printf("%c ", q.front());
}
