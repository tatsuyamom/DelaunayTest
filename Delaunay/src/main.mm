#include "ofMain.h"
#include "testApp.h"

int main(){
    ofAppiPhoneWindow *window = new ofAppiPhoneWindow();
    window->enableAntiAliasing(2);
    window->enableRetina();
    ofSetupOpenGL(window, 1024,768, OF_FULLSCREEN);
	//ofSetupOpenGL(1024,768,OF_FULLSCREEN);			// <-------- setup the GL context

	ofRunApp(new testApp());
}
