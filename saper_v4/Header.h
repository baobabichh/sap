#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <ctime>
#include<string>;
using namespace sf;
using namespace std;

//define

#define	 SAPER_IMAGE	"sap.jpg"


enum State
{
	empty_open ,
	one ,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight ,
	mine ,
	empty_closed ,
	flag ,
};