#include"Spawner.h"
#include<iostream>
using namespace std;
Zombie *new_zombie;
Spawner::Spawner(core::vector3df player,IrrlichtDevice *d,ISceneManager *s,IVideoDriver *v , ITriangleSelector *se):pos(player),count(0),inc(0){
    smgr=s;
    device=d;
    driver=v;
    selector = se;
    new_zombie = new Zombie(pos,device,smgr,driver,selector);

}
void Spawner::update(core::vector3df player)
{
    new_zombie->update(player);

 /*if(inc++ %100 == 0 && count < 50)
    {
        Zombie *new_zombie = new Zombie(pos,device,smgr,driver,selector);
        zombies.push_back(new_zombie);
        count++;
    }
    for(int i = 0 ; i < zombies.size(); i++)
    {
        zombies[i]->update(player);
    }*/
}

