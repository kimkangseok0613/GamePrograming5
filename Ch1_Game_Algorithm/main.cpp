// ���ӿ��� ��ġ�� ǥ���ϴ� ��� (2D)
// map 2���� �迭.
// �̷� ã�� (maze), AI ���� - Ż�ⱸ���� �̵��ϴ� �ڵ带 �ۼ��غ�����.
//

using namespace std;
#include <iostream>
#include <vector>
#include <windows.h>

#define SIZE 10

// 0 �̵��Ҽ� �ִ� ����, 1 ��
// �Ա��� (x, y) =(1, 0)
// �ⱸ�� (x, y) = (9, 5)
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

// ���� (��, ��, ��, ��)
// �� : x �� ��ȭ? 0 y �� ��ȭ? -1
// �� : x �� ��ȭ? 0 y �� ��ȭ? +1
// �� : x �� ��ȭ? -2 y �� ��ȭ? 0
// �� : x �� ��ȭ? +2 y �� ��ȭ? 0
// 

const int dx[4] = { 0,0,-2,2 };
const int dy[4] = { -1,1,0,0 };

void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// maze[y][x] �� ���� 0�̸� ' ', 1�̸� '��' ǥ���ϴ� �ڵ带 ��������.

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
				cout << "��";
			}
		}
		cout << endl;
	}
#pragma region �̵��� ���� �̸� �����д�.
	vector<int> direction = { 1,1,1,3,3,0,3,3,1,1,3,3,3,3,3 };
	int sx = 2; // ���δ� 2���� 1ĭ
	int sy = 0;
	GoToXY(sx, sy);
	cout << "��";

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
		cout << "��";

		Sleep(500);
	}
#pragma endregion

	// 1. ������ ���� ���� ���Ͱ� ���ʴ�� ������ �ڵ带 �ۼ��غ�����. (���潺 ����)
	// 2. �������� ���Ͱ� ������ �������� �����̴� �ڵ带 �ۼ��غ�����.
}