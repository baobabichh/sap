#include"Entity.h"

Entity::Entity()
{
	
}

Entity::~Entity()
{

}
//void Entity::create(int x, int y)
//{
//	tx->create(x, y);
//	setTexture(*tx);
//}
//void Entity::set_texture(Texture& t)
//{
//	tx = &t;
//}
void Entity::setTextureRect(IntRect r)
{
	Sprite::setTextureRect(r);
}
void Entity::setTexture(Texture & t)
{
	Sprite::setTexture(t);
}
//void Entity::rotate(int ang)
//{
//	rotate(ang);
//}
//int Entity::get_rotation()
//{
//	return getRotation();
//}
//int Entity::set_rotation(int ang)
//{
//	setRotation(ang);
//}
//FloatRect Entity::get_global_bounds()
//{
//	return getGlobalBounds();
//}
bool Entity::is_hovered(RenderWindow& window)
{
	if (getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//void Entity::draw(sf::RenderWindow& window)
//{
//	window.draw(*this);
//}
//void Entity::set_pos(Vector2f pos)
//{
//	setPosition(pos);
//}
//void Entity::set_pos(float x, float y)
//{
//	setPosition(x, y);
//}
//Vector2f Entity::get_pos()
//{
//	return getPosition();
//}
//void Entity::set_color(Color& c)
//{
//	setColor(c);
//}
