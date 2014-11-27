#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	triangulator.init(maxNumPoints);
    
    attrRadius = 175.f;
    attrFactor = 0.01f;
    attrPosition.x = attrPosition.y = 0;
    int numParticle = maxNumPoints;
    for(int i = 0; i < numParticle; i++){
        float x = ofRandom(ofGetWidth());
        float y = ofRandom(ofGetHeight());
        float radius = ofRandom(5, 15);
        float mass = radius;
        float drag = 0.95;
        Particle *particle = new Particle(ofVec3f(x,y),radius,mass,drag);
        mParticleSystem.addParticle(particle);
    }
    Defines::init();
    cout << Defines::getMode() << endl;
    Defines::_MODE = 5;
    cout << Defines::getMode() << endl;
}

//--------------------------------------------------------------
void testApp::update(){
    
    mParticleSystem.update();
        
    triangulator.reset();
    for(int i = 0; i < mParticleSystem.particles.size(); i++) {
        triangulator.addPoint(mParticleSystem.particles[i]->position.x, mParticleSystem.particles[i]->position.y);
    }
    triangulator.triangulate();
}

//--------------------------------------------------------------
void testApp::draw(){
	
    int numTris = triangulator.getNumTriangles();
    ITRIANGLE *tris = triangulator.getTriangles();
    XYZ *points = triangulator.getPoints();
   
    for(int i = 0; i < numTris; i++) {
        ofVec2f a = ofVec2f(points[tris[i].p1].x, points[tris[i].p1].y);
        ofVec2f b = ofVec2f(points[tris[i].p2].x, points[tris[i].p2].y);
        ofVec2f c = ofVec2f(points[tris[i].p3].x, points[tris[i].p3].y);
        
        ofLine(a, b);
        ofLine(b, c);
        ofLine(c, a);
    }
	triangulator.drawTriangles();
    ofSetColor(255, 255, 255,50);
    ofFill();
    mParticleSystem.draw();
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 50, 50);
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    attrPosition.x = touch.x;
    attrPosition.y = touch.y;
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}
