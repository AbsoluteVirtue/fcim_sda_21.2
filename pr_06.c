// https://en.wikipedia.org/wiki/Shunting_yard_algorithm

bool precedence(auto o1, auto o2)
{
    // (o2 has greater precedence than o1 or (o1 and o2 have the same precedence and o1 is left-associative)
    int p1 = 0;
    int p2 = 0;

    if (o1 == '+' || o1 == '-')
        p1 = 0;
    else if (o1 == '*' || o1 == '/')
        p1 = 1;
    else
        p1 = 2;
    if (o2 == '+' || o2 == '-')
        p2 = 0;
    else if (o2 == '*' || o2 == '/')
        p2 = 1;
    else
        p2 = 2;

    return (p2 >= p1);
}

int main(void)
{

    std::queue<char> q;
    std::stack<char> s;

    char tokens[] = "(3+2)*2-5/5";

    size_t i = 0;
    // while there are tokens to be read:
    while (tokens[i] != '\0')
    {
        // read a token
        char token = tokens[i];
        // - a number:
        if (isalnum(token))
        {
            q.push(token);
        }
        else if (token == '(')
        {
            // push it onto the operator stack
            s.push(token);
        }
        else if (token == ')')
        {
            // the operator at the top of the operator stack is not a left parenthesis:
            while (s.top() != '(')
            {
                // {assert the operator stack is not empty}
                assert(!s.empty());
                {
                    // pop the operator from the operator stack into the output queue
                    q.push(s.top());
                    s.pop();
                    /* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
                }
            }
            // {assert there is a left parenthesis at the top of the operator stack}
            assert(s.top() == '(');
            // pop the left parenthesis from the operator stack and discard it
            s.pop();
        }
        else
        {
            // - an operator o1:
            while (!s.empty() && s.top() != '(' && precedence(token, s.top()))
            {
                // pop o2 from the operator stack into the output queue
                q.push(s.top());
                s.pop();
            }
            s.push(token);
        }
        i++;
    }
    /* After the while loop, pop the remaining items from the operator stack into the output queue. */
    // while there are tokens on the operator stack:
    while (!s.empty())
    {
        /* If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses. */
        // {assert the operator on top of the stack is not a (left) parenthesis}
        assert('(' != s.top());
        // pop the operator from the operator stack onto the output queue
        q.push(s.top());
        s.pop();
    }

    // std::stack<int> r; // stack for calulating the end result
    // printf("%d", r.top());
}
