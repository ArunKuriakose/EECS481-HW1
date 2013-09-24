#pragma once
#include "simObject.h"

class Pongball : public simObject {
public:
  Pongball();
  virtual ~Pongball();
  void update(float time);
private:
	float speed;
	float angle;
	float timeGone;

	float LinearVelocityX(float angle);
	float LinearVelocityY(float angle);
};