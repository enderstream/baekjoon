#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> cood_plane(101, vector<int>(101, 0));
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1 + 1; x <= x2; x++)
            for (int y = y1 + 1; y <= y2; y++)
                if (cood_plane[x][y] == 1) // 최적화 : 이미 1이면 굳이 1로 또 바꿀 필요 없음
                    continue;
                else // 종이를 새로 붙인 곳은 1로 바꾸는 동시에 카운터 업 >> O(400)
                {
                    cnt++;
                    cood_plane[x][y] = 1;
                }
    }
    // 비효율적인 버전 >> 종이를 붙이는 족족 무지성 1로 다 채워두고 전체 평면 탐색 >> O(10000)
    /*
    for (int i = 0; i < 4; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1 + 1; x <= x2; x++)
            for (int y = y1 + 1; y <= y2; y++)
                cood_plane[x][y] = 1;
    }
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            if(cood_plane[i][j] == 1)
                cnt++;            
    */
    
    cout << cnt;

    return 0;
}
