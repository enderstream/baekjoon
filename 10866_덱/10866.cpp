#include <iostream>
#include <vector>
#include <string>
#include <istream>

using namespace std;

typedef struct link_comp
{
    int value = 0;
    link_comp &before;
    link_comp &next;
    link_comp() : before(*this), next(*this) {}
} link_comp_t;

void solution();
void push_front(link_comp &deque, int X);
void push_back(link_comp &deque, int X);
int pop_front(link_comp &deque);
int pop_back(link_comp &deque);
int size(link_comp &deque);
int empty(link_comp &deque);
int front(link_comp &deque);
int back(link_comp &deque);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    solution();

    return 0;
}

void solution()
{
    int N = 0;
    cin >> N;

    link_comp deque_comp; // empty deque

    for (int i = 0; i < N; i++)
    {
        string instruction;
        getline(cin, instruction);
    }
}

void push_front(link_comp &deque, int X) {}
void push_back(link_comp &deque, int X) {}
int pop_front(link_comp &deque) {}
int pop_back(link_comp &deque) {}
int size(link_comp &deque) {}
int empty(link_comp &deque) {}
int front(link_comp &deque) {}
int back(link_comp &deque) {}