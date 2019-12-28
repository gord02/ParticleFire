 #ifndef PARTICLE_H_
#define PARTICLE_H_

namespace gordon{

struct Particle{
	double m_x;
	double m_y;                     // using double makes it smothier

private:
	double m_speed;
	double m_direction;
	void init();

public: 
	Particle();
	virtual ~Particle();
	void update(int interval ); //added
};

}
#endif