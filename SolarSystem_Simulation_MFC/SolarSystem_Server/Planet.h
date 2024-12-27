#pragma once
class Planet
{

public:
	Planet():Name(""),speed(0),life(0),angle(0),position(0,0),spin(0),count(0){}
	Planet(const char* name, int speed, int life, double angle,int spin):
		Name(name),speed(speed),life(life),angle(angle),spin(spin){
		position.x = 0;
		position.y = 0;
		count = 1;
	}
	virtual char* GetMoonFlag() { return 0; }
	virtual void SetMoonFlag(int flag) {}

	void Reset();
	const char* Name;
	int speed;
	int life;
	int angle;
	int spin;
	int count;
	CPoint position;
	
	
};

