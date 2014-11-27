#include "particle.h"
#include "ofMain.h"

//------------------------------------------------------------
Particle::Particle(ofVec3f position, float radius, float mass, float drag){
	this->position = position;
    this->radius = radius;
    this->mass = mass;
    this->drag = drag;
    prevPosition = position;
    forces = ofVec3f(0,0,0);
}



//------------------------------------------------------------
void Particle::update(){
	ofVec3f temp = position;
    ofVec3f vel = ( position - prevPosition ) * drag;
    position += vel + forces / mass;
    prevPosition = temp;
    forces = ofVec3f(0,0,0);
}
//------------------------------------------------------------
void Particle::draw(){
    ofCircle(position.x, position.y, radius);
}

