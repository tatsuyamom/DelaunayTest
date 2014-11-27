//
//  ParticleSystem.h
//  drawingWithParticles
//
//  Created by t_hiroi on 2014/03/03.
//
//

#ifndef __drawingWithParticles__ParticleSystem__
#define __drawingWithParticles__ParticleSystem__

#include <iostream>

#endif /* defined(__drawingWithParticles__ParticleSystem__) */
#include "Particle.h"
#include <vector>


class ParticleSystem
{
public:
	
	//ParticleSystem();
    //ParticleSystem( ofVec3f position, float radius, float mass, float drag );
	virtual ~ParticleSystem();
	
	void update();
	void draw();
	void drawWithLines();
    void addParticle( Particle *particle );
    void destroyParticle( Particle *particle );
    
    vector<Particle*> particles;

    
protected:
private:
};

