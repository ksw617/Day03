#include <stdio.h>
#include <Windows.h>

#pragma region WIN_API
void SetPosition(int x, int y);
#pragma endregion

#define Bullet_Count 10
#define Enemy_Count 3

typedef struct Obj1
{	
	int x;
	int y;
	const char* shape[3];
}Obj;

typedef struct Obj2 
{
	bool act;
	int hp;
	int x;
	int y;
	const char* shape;
}Bullet, Enemy;


int main()
{
	Obj obj;
	obj.x = 2;
	obj.y = 10;
	obj.shape[0] = "   -----|-----";
	obj.shape[1] = "*>=====[_]L)";
	obj.shape[2] = "      -'-`-";

	Bullet bullets[Bullet_Count];
	for (int i = 0; i < Bullet_Count; i++)
	{
		//i == 0, 1, 2
		//bullets[0],bullets[1],bullets[2]
		bullets[i].act = false;
		bullets[i].x = i;
		bullets[i].y = 0;
		bullets[i].shape = "●";
	}


	Enemy enemies[Enemy_Count];
	for (int i = 0; i < Enemy_Count; i++)
	{
		enemies[i].act = true;
		enemies[i].x = rand() % 29 + 10;
		enemies[i].y = rand() % 30;
		enemies[i].shape = "봇";
		enemies[i].hp = 3;
	}



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
			for (int i = 0; i < Bullet_Count; i++)
			{
				if (bullets[i].act == false)
				{
					bullets[i].x = obj.x + 6;
					bullets[i].y = obj.y + 1;

					bullets[i].act = true;
					break; // for루프 빠져 나감
				}
			}
		}


		
		for (int i = 0; i < 3; i++)
		{
			SetPosition(obj.x, obj.y + i);
			printf(obj.shape[i]);
		}


		for (int i = 0; i < Bullet_Count; i++)
		{
			if (bullets[i].act == true)
			{
				bullets[i].x++;

				if (bullets[i].x >= 40)
				{
					bullets[i].act = false;
					bullets[i].y = 0;
					bullets[i].x = i;
				}

				for (int j = 0; j < Enemy_Count; j++)
				{
					if (enemies[j].act)
					{
						if (enemies[j].x == bullets[i].x && enemies[j].y == bullets[i].y)
						{
							if (enemies[j].hp > 0)
							{
								enemies[j].hp--;
							}
							else
							{
								enemies[j].act = false;
								enemies[i].hp = 3;
							}


							bullets[i].act = false;
							
						}
					}
				}
			}


			SetPosition(bullets[i].x, bullets[i].y);
			printf(bullets[i].shape);
		}

		for (int i = 0; i < Enemy_Count; i++)
		{
			if (enemies[i].act == false)
			{
				enemies[i].act = true;
				enemies[i].x = rand() % 29 + 10;
				enemies[i].y = rand() % 30;
		
				break;
			}
		}

	
		for (int i = 0; i < Enemy_Count; i++)
		{
			if (enemies[i].act)
			{
				SetPosition(enemies[i].x, enemies[i].y);
				printf(enemies[i].shape);
			}
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


