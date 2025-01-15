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

struct Bullet
{
	bool act;
	int x;
	int y;
	const char* shape;
};


int main()
{
	Obj obj;
	obj.x = 10;
	obj.y = 10;
	obj.shape[0] = "   -----|-----";
	obj.shape[1] = "*>=====[_]L)";
	obj.shape[2] = "      -'-`-";

	Bullet bullet;
	bullet.act = false;
	bullet.x = 0;
	bullet.y = 0;
	bullet.shape = "¡Ü";

	while (true)
	{
		system("cls");	
		if (GetAsyncKeyState(0x57))
		{
			obj.y--;
		}
		if (GetAsyncKeyState(0x41))
		{
			obj.x--;
		}

		if (GetAsyncKeyState(0x53))
		{
			obj.y++;
		}
		if (GetAsyncKeyState(0x44))
		{
			obj.x++;
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			if (bullet.act == false)
			{
				bullet.x = obj.x + 6;
				bullet.y = obj.y + 1;

				bullet.act = true;
			}
		
		}


		
		for (int i = 0; i < 3; i++)
		{
			SetPosition(obj.x, obj.y + i);
			printf(obj.shape[i]);
		}

		//bullet.act == true
		if (bullet.act)
		{
			bullet.x++;

		}

		SetPosition(bullet.x, bullet.y);
		printf(bullet.shape);
	

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


