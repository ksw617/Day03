#include <stdio.h>
#include <Windows.h>

#pragma region WIN_API
void SetPosition(int x, int y);
#pragma endregion

struct Obj
{
	int x;
	int y;
	const char* shape[3];
};


int main()
{
	Obj obj;
	obj.x = 10;
	obj.y = 10;
	obj.shape[0] = "   -----|-----";
	obj.shape[1] = "*>=====[_]L)";
	obj.shape[2] = "      -'-`-";

	while (true)
	{
		system("cls");	

		//W == UP
		if (GetAsyncKeyState(0x57))
		{
			obj.y--;
		}

		//A == LEFT
		if (GetAsyncKeyState(0x41))
		{
			obj.x--;
		}

		//S == DOWN
		if (GetAsyncKeyState(0x53))
		{
			obj.y++;
		}

		//D == RIGHT
		if (GetAsyncKeyState(0x44))
		{
			obj.x++;
		}


		
		for (int i = 0; i < 3; i++)
		{
			//obj.y == 10;
			//obj.y + i(0) == 10
			//obj.y + i(1) == 11
			//obj.y + i(2) == 12
			SetPosition(obj.x, obj.y + i);
			printf(obj.shape[i]);
		}
	

		Sleep(50);
	}

	return 0;
}

#pragma region WIN_API
void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion


