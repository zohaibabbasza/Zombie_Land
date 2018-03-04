#ifndef SPAWNER_H
#define SPAWNER_H
#include<irrlicht.h>
#include"Zombie.h"
#include<vector>
class Spawner{
    private:
        int inc;
        int count;
        vector<Zombie*> zombies;
        core::vector3df pos;
        IrrlichtDevice *device ;
        IVideoDriver *driver;
        ISceneManager *smgr ;
        ITriangleSelector *selector;
    public:
        Spawner(core::vector3df player,IrrlichtDevice *,ISceneManager *,IVideoDriver*,ITriangleSelector*);
        void update(core::vector3df player);

};
#endif // SPAWNER_H
