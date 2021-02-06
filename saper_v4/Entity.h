#pragma once
#include"Header.h"

class Entity :public Sprite
{
public:
	Entity();
	~Entity();
	void create(int x, int y);
	void setTextureRect(IntRect r);
	void setTexture(Texture& t);
	//void set_texture_rect(IntRect& r);
	//void rotate(int ang);
	//int get_rotation();
	//int set_rotation(int ang);
	//FloatRect get_global_bounds();
	bool is_hovered(RenderWindow& window);
	//void draw(sf::RenderWindow& window);
	//void set_pos(Vector2f pos);
	//void set_pos(float x , float y);
	//Vector2f get_pos();
	//void set_color(Color& c);

private:
	Texture *tx;
};

