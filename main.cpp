#include<irrlicht.h>
#include<cstdlib>
#include"Spawner.h"
#include<iostream>
using namespace irr;
using namespace gui;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace std;

int main()
{
    IrrlichtDevice *device =createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 16,
			false, false, false, 0);
    if(!device)
    {
        return EXIT_FAILURE;
    }
    device->setWindowCaption(L"ZombieLand");

    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();

    device->getFileSystem()->addFileArchive("media/q3dmz_carnage.pk3");
    scene::IAnimatedMesh* mapMesh = smgr->getMesh("media/q3dmz_carnage.bsp");
	scene::IMeshSceneNode* mapNode = 0;


	    if (mapMesh)
        {
            mapNode =  smgr->addOctreeSceneNode(mapMesh->getMesh(0), 0, 1);
        }


         ITriangleSelector *selector = 0;
          if (mapNode)
          {

            mapNode->setPosition(core::vector3df(-1300,-144,-1249));
           selector = smgr->createOctreeTriangleSelector(mapNode->getMesh(),mapNode,120);
            mapNode->setTriangleSelector(selector);
          }
        ICameraSceneNode *camera = smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, 0, 0, 0, true, 3.f);;
        camera->setPosition(core::vector3df(-100,-60,-600));
        camera->setTarget(core::vector3df(-70,30,-60));
        camera->setFarValue(1500);
        device->getCursorControl()->setVisible(false);
        //smgr->addCameraSceneNodeFPS();

        if(selector)
          {
              scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector , camera,
              core::vector3df(30,50,30),core::vector3df(0,-10,0),core::vector3df(0,30,0));
              selector->drop();
              camera->addAnimator(anim);
              anim->drop();
          }

         irr::scene::IAnimatedMeshMD2 *weapon_mesh= nullptr ;
        irr::scene::IAnimatedMeshSceneNode *weapon_node= nullptr;

        weapon_mesh = (irr::scene::IAnimatedMeshMD2*)smgr->getMesh("media/gun.md2");
        weapon_node = smgr->addAnimatedMeshSceneNode(
		weapon_mesh,
		camera,
		10,
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(-90, -90, 90)
		);
        weapon_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        weapon_node->setMaterialTexture(0,driver->getTexture("media/gun.jpg"));
        weapon_node->setLoopMode(true);
        weapon_node->setName("Zombie gun");


	weapon_node = smgr->addAnimatedMeshSceneNode(
		weapon_mesh,
		camera,
		10,
		irr::core::vector3df(0, 0, 0),
		irr::core::vector3df(-90, -90, 90)
		);
  Spawner spawner(core::vector3df(-80,-260,-650),device,smgr,driver,selector);

     while(device->run())
    {

        if (device->isWindowActive())
        {
            driver->beginScene(true, true, 0);
            smgr->drawAll();
        }


		driver->endScene();

        spawner.update(camera->getPosition());


    }
    device->drop();
    return EXIT_SUCCESS ;
}

