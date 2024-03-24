#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
	int continuity = 0;
	int curHealth = health;
	int last = attacks.back()[0]; //마지막 공격 시간
	for (int i = 1; i <= last; i++)
	{
		if (i == attacks.front()[0])
		{
			curHealth -= attacks.front()[1];
			continuity = 0;
			if (curHealth <= 0)
			{
				return -1;
			}
			attacks.erase(attacks.begin());
		}
		else
		{
			continuity++;
			curHealth += bandage[1];
			if (continuity == bandage[0])
			{
				continuity = 0;
				curHealth += bandage[2];
			}
			if (health < curHealth)
				curHealth = health;
		}
	}
	return curHealth;
}