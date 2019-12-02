#include<iostream>

#define endl "\n"
#define MAX 500
using namespace std;

int N, Answer;
int MAP[MAX][MAX];
int DP[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Bigger(int A, int B) { return A > B ? A : B; }

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

int Move(int x, int y)
{
    if (DP[x][y] != 0) return DP[x][y]; //특정 지점에 도착했을 때 그 곳에 값이 있다면 바로 Return을 해주면 된다. 최대값이 보장됨. 이 부분이 시간의 효율성을 매우 높여준다.
    DP[x][y] = 1; //정답의 최소값인 1부터 시작

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N)
        {
            if (MAP[x][y] < MAP[nx][ny]) //주변 칸이 해당칸보다 값이 클 경우
            {
                DP[x][y] = Bigger(DP[x][y], Move(nx, ny) + 1); //이 줄을 통해 이전 부분의 DP값이 계속 갱신이 됨. (저 지점에서의 DP값은 주변 모든 값을 돌고 왔을 때 가장 큰 값이 되어 있다.)
            }
        }
    }
    return DP[x][y];
}

void Solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Answer = Bigger(Answer, Move(i, j));
        }
    }
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
