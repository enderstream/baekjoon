#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> cood_plane(101, vector<int>(101, 0));
void dragon_curve();
bool is_square(int x, int y);
bool is_valid_cood(int x, int y);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;   // number of dracon curves
    int cnt = 0; // number of squares
    cin >> N;

    for (int i = 0; i < N; i++)
        dragon_curve();

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (is_square(i, j))
                cnt++;

    cout << cnt;

    return 0;
}

void dragon_curve()
{
    int x = 0;
    int y = 0;
    int d = 0;
    int g = 0;
    int s = 0; // size of dragon body
    cin >> x >> y >> d >> g;

    vector<pair<int, int>> dragon_body;
    dragon_body.push_back(make_pair(x, y));
    for (int i = 0; i <= g; i++)
        if (i == 0)
        {
            if (d == 0)
                dragon_body.push_back(make_pair(x + 1, y));
            else if (d == 1)
                dragon_body.push_back(make_pair(x, y - 1));
            else if (d == 2)
                dragon_body.push_back(make_pair(x - 1, y));
            else if (d == 3)
                dragon_body.push_back(make_pair(x, y + 1));
        }
        else
        {
            s = dragon_body.size(); // s must be more than 1

            for (int j = s - 2; j >= 0; j--)
            {
                int x_t = 0;
                int y_t = 0;
                // rotate 3pi/2 using the rotation matrix
                x_t = -dragon_body[j].second + dragon_body[s - 1].second + dragon_body[s - 1].first; // rotation matrix applied
                y_t = dragon_body[j].first - dragon_body[s - 1].first + dragon_body[s - 1].second;   // rotation matrix applied
                dragon_body.push_back(make_pair(x_t, y_t));
            }
        }


    for (int i = 0; i < dragon_body.size(); i++)
        if (is_valid_cood(dragon_body[i].first, dragon_body[i].second))
            cood_plane[dragon_body[i].first][dragon_body[i].second] = 1;
}

bool is_square(int x, int y)
{
    return (cood_plane[x][y] * cood_plane[x + 1][y] * cood_plane[x][y + 1] * cood_plane[x + 1][y + 1] == 1);
}

bool is_valid_cood(int x, int y)
{
    return (0 <= x && x <= 100 && 0 <= y && y <= 100);
}