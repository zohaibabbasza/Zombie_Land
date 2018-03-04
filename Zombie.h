#ifndef ZOMBIE_H
#define ZOMBIE_H
#include<irrlicht.h>

using namespace irr;
using namespace gui;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace std;

class Zombie {
    private:
        IAnimatedMeshSceneNode *zombie;
        int state;
        IrrlichtDevice *device ;
        IVideoDriver *driver;
        ISceneManager *smgr ;
        core::vector3df pos;
        ITriangleSelector *selector;

    public:
        Zombie(core::vector3df pps,IrrlichtDevice *,ISceneManager *,IVideoDriver*,ITriangleSelector*);
        void update(core::vector3df target);


};



#endif // ZOMBIE_H
