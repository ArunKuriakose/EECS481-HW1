#pragma once

class simObject {
public: 
	simObject();
	virtual ~simObject();
	virtual void Draw(sf::RenderWindow &window);
	virtual void setPos(float x, float y);
	virtual void loadObjectImage(std::string filename);
	virtual void update(float time);
	virtual sf::Vector2f getPos() const;
	sf::Sprite& getSprite();
	virtual sf::Rect<float> getHitBox() const;
	virtual float getWidth() const;
	virtual float getHeight() const;

private:
	sf::Sprite sprite;
	sf::Image icon;
};