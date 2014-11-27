//
//  ParticleSystem.cpp
//  drawingWithParticles
//
//  Created by t_hiroi on 2014/03/03.
//
//

#include "ParticleSystem.h"
#include "ofMain.h"
ParticleSystem::~ParticleSystem(){
	for( std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it ){
        delete *it;
    }
    particles.clear();
}



//------------------------------------------------------------
void ParticleSystem::update(){
	for( std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it ){
        (*it)->update();
    }


}
//------------------------------------------------------------
void ParticleSystem::draw(){
    for( std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it ){
        (*it)->draw();
    }
}
//------------------------------------------------------------
void ParticleSystem::drawWithLines(){
    std::vector<Particle*>::iterator it;
    for(it = particles.begin(); it != particles.end(); ++it){
        std::vector<Particle*>::iterator it2;
        for(it2 = particles.begin(); it2 != particles.end(); ++it2){
            float distance = (*it)->position.distance((*it2)->position);
            float per = (100/distance);
            ofSetColor(ofColor(255,255,255,per*0.4*100));
            ofVec3f conVec = (*it2)->position-(*it)->position;
            conVec.normalize();
            ofVec3f p1 = (*it)->position+conVec * ((*it)->radius+2.0f);
            ofVec3f p2 = (*it2)->position+conVec * ((*it2)->radius+2.0f);
            if(per>0.5f){
               ofLine(p1.x, p1.y, p2.x, p2.y);
            }
           
        }
    }
    ofSetColor(ofColor(100,255,255,0.8*255));
    ofFill();
    for( std::vector<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it ){
        (*it)->draw();
    }
}
void ParticleSystem::addParticle(Particle *particle){
	particles.push_back( particle );
    
}

void ParticleSystem::destroyParticle(Particle *particle){
	std::vector<Particle*>::iterator it = std::find( particles.begin(), particles.end(), particle );
    delete *it;
    particles.erase( it );
    
    
}
