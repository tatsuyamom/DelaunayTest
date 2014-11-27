//
//  Defines.h
//  Delaunay2
//
//  Created by t_hiroi on 2014/03/13.
//
//

#ifndef __Delaunay2__Defines__
#define __Delaunay2__Defines__

#include <iostream>

#endif /* defined(__Delaunay2__Defines__) */


class Defines
{
public:
    static void init();
    static void reset();
	static void setMode(int n);
    static int getMode();
        static int _MODE;
protected:
private:

    static bool _IS_PLAYING;

};
