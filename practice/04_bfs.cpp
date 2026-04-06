#include <cstdio>
#include <list>

using std::list;

int main()
{

    int g[6][6] = {
        {0, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {0, 1},
        {0, 0, 1},
        {0, 0, 1},
    };

    int c[6] = {0};

    list<int> q{0};

    while (not q.empty())
    {
        auto v = q.front();
        q.pop_front();

        for (auto j = 0; j < 6; ++j)
        {
            if (g[v][j] && c[j] == 0) {
                q.push_back(j);
                printf("%d: %d\n", v + 1, j + 1);
            }
        }

        c[v] = 1;
    }
}
