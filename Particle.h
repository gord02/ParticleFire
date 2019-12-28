 
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace gordon{

struct Particle{
	double m_x;
	double m_y;                     // using double makes it smothier

//double m_xspeed;
//double m_yspeed;

private:
double m_speed;
double m_direction;

private:
	void init();

public: 
	Particle();
	virtual ~Particle();
	void update(int interval ); //added
	};
}
#endif