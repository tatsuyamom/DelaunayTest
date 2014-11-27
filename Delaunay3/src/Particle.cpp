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
    speed.x = ofRandom(-1,1);
    speed.y = ofRandom(-1,1);
}



//------------------------------------------------------------
void Particle::update(){
	if(position.x < 0){
        position.x = 0;
        speed.x *= -1;
    }else if(position.x > ofGetWidth()){
        position.x = ofGetWidth();
        speed.x *= -1;
    }
    if(position.y < 0){
        position.y = 0;
        speed.y *= -1;
    }else if(position.y > ofGetHeight()){
        position.y = ofGetHeight();
        speed.y *= -1;
    }
    
    position += speed;
}
//------------------------------------------------------------
void Particle::draw(){
    ofCircle(position.x, position.y, radius);
}

