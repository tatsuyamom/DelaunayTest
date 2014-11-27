#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle
{
public:
	
	Particle();
    Particle( ofVec3f position, float radius, float mass, float drag );
	virtual ~Particle(){};
	
	void update();
	void draw();
	
	ofVec3f position, prevPosition;
    ofVec3f forces;
	float radius;
    float mass;
    float drag;
    
protected:
private:
};

#endif // PARTICLE_H
