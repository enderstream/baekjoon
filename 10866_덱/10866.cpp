#include <iostream>
#include <vector>
#include <string>
#include <istream>

using namespace std;

class link_comp
{
    public:
        int value;
        // link_comp before;
        // link_comp next;
        // link_comp() : value(0), before(nullptr), next(nullptr) {}
};

class deque{
    private:
        link_comp head;
    public:
        deque() // constructor
        {
            head.before = head;
            head.next= head;
        }
        void push_front(int X) // member method
        {
            link_comp new_comp;
            new_comp.value = X;
            new_comp.before = head;
            new_comp.next = head.next;
            head.next.before = new_comp;
            head.next = new_comp;
        }
        void display()
        {

        }
}
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

void push_front(link_comp &deque, int X) {
    link_comp new_comp;
    new_comp.value = X;
    new_comp.next = deque;
}

void push_back(link_comp &deque, int X) {}
int pop_front(link_comp &deque) {}
int pop_back(link_comp &deque) {}
int size(link_comp &deque) {}
int empty(link_comp &deque) {}
int front(link_comp &deque) {}
int back(link_comp &deque) {}