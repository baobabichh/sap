#pragma once
#include"Header.h"
#include"Entity.h"
#include"functions.h"

class Entity;

class Cell
{
public:
	Cell();
	~Cell();
	void update();
	void set_real_id(int state);
	void set_show_id(int state);
	void open();
	int get_real_id();
	int get_show_id();
	void set_pos(float x, float y);
	Vector2f get_pos();
	void set_pos(Vector2f& pos);
	bool is_hovered(RenderWindow& window);
	void draw(RenderWindow & window);
	void set_texture(Texture & t);
	bool get_is_open();
	void close();
private:
	Entity real_entity , show_entity;
	int real_id, show_id ;
	bool is_open;
};

