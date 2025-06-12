// 게임에서 위치를 표현하는 방법 (2D)
// map 2차원 배열.
// 미로 찾기 (maze), AI 존재 - 탈출구까지 이동하는 코드를 작성해보세요.
//

using namespace std;
#include <iostream>
#include <vector>
#include <windows.h>

#define SIZE 10

// 0 이동할수 있는 공간, 1 벽
// 입구를 (x, y) =(1, 0)
// 출구를 (x, y) = (9, 5)
//
int maze[SIZE][SIZE] =
{
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
	{ 1, 0, 0, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 1, 1, 1, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 1, 0 },
	{ 1, 0, 1, 1, 1, 0, 0, 0, 1, 1 }
};

// 방향 (상, 하, 좌, 우)
// 상 : x 의 변화? 0 y 의 변화? -1
// 하 : x 의 변화? 0 y 의 변화? +1
// 좌 : x 의 변화? -2 y 의 변화? 0
// 하 : x 의 변화? +2 y 의 변화? 0
// 

const int dx[4] = { 0,0,-2,2 };
const int dy[4] = { -1,1,0,0 };

void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// maze[y][x] 의 값이 0이면 ' ', 1이면 '■' 표현하는 코드를 만들어보세요.

int main()
{
	for (int y=0;y<SIZE;y++)
	{
		for (int x=0;x<SIZE;x++)
		{
			if (maze[y][x] == 0)
			{
				cout << "  ";
			}
			else if (maze[y][x] == 1)
			{
				cout << "■";
			}
		}
		cout << endl;
	}
#pragma region 이동할 길을 미리 만들어둔다.
	vector<int> direction = { 1,1,1,3,3,0,3,3,1,1,3,3,3,3,3 };
	int sx = 2; // 가로는 2개가 1칸
	int sy = 0;
	GoToXY(sx, sy);
	cout << "★";

	int pre_x = sx;
	int pre_y = sy;

	for (int i = 0;i < direction.size();i++)
	{
		GoToXY(pre_x, pre_y);
		cout << "  ";

		int dir = direction[i];
		sx += dx[dir];
		sy += dy[dir];
		pre_x = sx;
		pre_y = sy;
		GoToXY(sx,sy);
		cout << "★";

		Sleep(500);
	}
#pragma endregion

	// 1. 정해진 길을 따라 몬스터가 차례대로 나오는 코드를 작성해보세요. (디펜스 게임)
	// 2. 여러가지 몬스터가 각자의 방향으로 움직이는 코드를 작성해보세요.
}