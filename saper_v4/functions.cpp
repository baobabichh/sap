#include"functions.h"

bool is_state_digit(int a)
{
	if (a >= 1 && a <= 8)
	{
		return 1;
	}
	return 0;
}
int random(int min, int max) //Pass in range
{
	//Changed from rand(). srand() seeds rand for you.
	int random = rand() % max + min;
	return random;
	
}
bool is_digit(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5'
			|| str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
			continue;
		}
		return 0;
	}
	return 1;
}