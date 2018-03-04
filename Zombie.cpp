#include "Zombie.h"
#include<irrlicht.h>
#include<iostream>

using namespace irr;
using namespace gui;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace std;



Zombie::Zombie(core::vector3df pos,IrrlichtDevice *d,ISceneManager *s ,IVideoDriver* v, ITriangleSelector *se)
{
    device=d;
    smgr=s;
    driver=v;
    selector=se;
    IAnimatedMesh *mesh = smgr->getMesh("media/zombie.md2");
    zombie = smgr->addAnimatedMeshSceneNode(mesh);

    state = 0 ;
    if(zombie)
    {

        zombie->setMaterialFlag(EMF_LIGHTING,false);
        zombie->setMD2Animation(scene::EMAT_RUN);
        zombie->setScale(core::vector3df(2,2,2));
        zombie->setPosition(pos);
        zombie->setMaterialTexture(0,driver->getTexture("media/zombie.bmp"));


    }
}
void Zombie::update(core::vector3df target)
{
    core::vector3df player_pos = target;
    core::vector3df zombie_pos = zombie->getPosition();
    core::vector3df vec = player_pos - zombie_pos;
    core::vector3df rot = zombie->getRotation();
    rot.Y = atan(vec.Z/vec.X) * (180.0f / irr::core::PI);
    if((player_pos.X-zombie_pos.X) > 0)
    {
        rot.Y=90-rot.Y;
    }
    else if((player_pos.X-zombie_pos.X) < 0)
    {
        rot.Y=-90-rot.Y;
    }
    rot.Y-=90;
    zombie->setRotation(rot);

    if(zombie_pos.getDistanceFrom(player_pos) < 50)
    {
        if(state == 0)
        {
            state = 1;
            zombie->setMD2Animation(EMAT_ATTACK);
        }
        else if(state != 0)
        {
            state = 0;
            zombie->setMD2Animation(EMAT_RUN);

        }
    }
    if(state == 0)
    {
        scene::ISceneNodeAnimator *zombie_anim=
        smgr->createFlyStraightAnimator(zombie->getPosition(),zombie->getPosition(),3500 , true);
        zombie->addAnimator(zombie_anim);
        zombie_anim->drop();
    }
    else
    {
        scene::ISceneNodeAnimator *zombie_anim=smgr->createFlyStraightAnimator(zombie->getPosition(),zombie->getPosition(),3500,true);
        zombie->addAnimator(zombie_anim);
        zombie_anim->drop();
    }



}
