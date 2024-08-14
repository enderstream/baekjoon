#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct comp
{
    int A;
    int I;
}comp_t;
typedef vector<comp> set_of_comp;

bool compare(const comp& X, const comp& Y);
int findMax(vector<comp> vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<comp> C(N);

    for (int i = 0; i < N; i++)
    {
        cin >> C[i].A;
        C[i].I = i;
    }

    sort(C.begin(), C.end(), compare);

    for (int i = 0; i < N; i++)
        C[i].I -= i;

    int max = findMax(C);

    cout << max;
}

int findMax(vector<comp> vec)
{
    int max = -9999999;
    for (int i = 0; i < vec.size(); i++)
        if (max < vec[i].I)
            max = vec[i].I;
    max++;
    return max;
}

bool compare(const comp& X, const comp& Y)
{
    //if (X.A == Y.A)
    //    if (X.I < Y.I)
    //        return true;
    //else if (X.A < Y.A) return true;
    //else return false;

    if (X.A != Y.A)
        return X.A < Y.A;

    return X.I < Y.I;
}