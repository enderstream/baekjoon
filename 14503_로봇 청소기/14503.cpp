#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> room;

int clean_up(room room, int r, int c, int d);
bool check_surround(room room, int r, int c);
bool check_forward(room room, int r, int c, int d);
bool check_backward(room room, int r, int c, int d);
int turn_ccw(int d);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // rows
    int M; // cols
    cin >> N >> M;

    int r; // row
    int c; // col
    int d; // direction
    cin >> r >> c >> d;

    int cnt = 0;

    room room(N + 2, vector<int>(M + 2, 1));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> room[i][j];

    r++;
    c++;
    cnt = clean_up(room, r, c, d);

    cout << cnt;

    return 0;
}

int clean_up(room room, int r, int c, int d)
{
    /*
    0 : dirty
    1 : wall
    2 : clean
    */

    int cnt = 0;
    while (true)
    {
        if (room[r][c] == 0) // is here dust?
        {
            room[r][c] = 2;
            cnt++;
        }

        if (check_surround(room, r, c)) // is there dust?
        {
            d = turn_ccw(d);
            if (check_forward(room, r, c, d)) // if there is dust then move
                if (d == 0)
                    r--;
                else if (d == 1)
                    c++;
                else if (d == 2)
                    r++;
                else
                    c--;

        }
        else
            if (check_backward(room, r, c, d)) // can you go back?
                if (d == 0)
                    r++;
                else if (d == 1)
                    c--;
                else if (d == 2)
                    r--;
                else
                    c++;
            else
                break;
    }
    return cnt;
}

bool check_surround(room room, int r, int c)
{
    bool tf_n = (room[r - 1][c] == 0);
    bool tf_e = (room[r][c + 1] == 0);
    bool tf_s = (room[r + 1][c] == 0);
    bool tf_w = (room[r][c - 1] == 0);

    return (tf_n || tf_e || tf_s || tf_w);
}

bool check_forward(room room, int r, int c, int d)
{
    bool tf = false;
    if (d == 0)
        tf = (room[r - 1][c] == 0);
    else if (d == 1)
        tf = (room[r][c + 1] == 0);
    else if (d == 2)
        tf = (room[r + 1][c] == 0);
    else if (d == 3)
        tf = (room[r][c - 1] == 0);

    return tf;
}

bool check_backward(room room, int r, int c, int d)
{
    bool tf = false;
    if (d == 0)
        tf = (room[r + 1][c] != 1);
    else if (d == 1)
        tf = (room[r][c - 1] != 1);
    else if (d == 2)
        tf = (room[r - 1][c] != 1);
    else if (d == 3)
        tf = (room[r][c + 1] != 1);

    return tf;
}

int turn_ccw(int d)
{
    /*
    0 : north
    1 : east
    2 : south
    3 : west
    */
    --d += 4;
    d %= 4;
    return d;
}