#include "PhysicsCamera.h"
#include "Box.h"
#include "Cylinder.h"
#include "Steerable3DController.h"
#include "Ground.h"
#include "Content.h"
#include <btBulletDynamicsCommon.h>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include <gtx/norm.hpp>
#include "VectorDrawer.h"
#include "Utils.h"

#include "PhysicsFactory.h"
#include "Game.h" 
#include "Model.h"
#include "dirent.h"
#include "Capsule.h" 

#include "interim.h"

using namespace BGE;

interim::interim(void)
{
}

interim::~interim(void)
{
}

bool interim::Initialise()
{
	physicsFactory->CreateGroundPhysics();
	physicsFactory->CreateCameraPhysics();


	int i = 0,
		j = 0;
	int k = 5,
		l = 2;

	shared_ptr<PhysicsController> box[5][5];


	for (j = 0; j < l; ++j) {
		for (i = 0; i < k; ++i) {
			box[i][j] = physicsFactory->CreateBox(5, 5, 5, glm::vec3(5 * i, 5 * j, 0), glm::quat());
		}
	}


	if (!Game::Initialise()) {
		return false;
	}

	camera->transform->position = glm::vec3(0, 10, 20);

	return true;
}

void BGE::interim::Update(float timeDelta)
{

	Game::Update(timeDelta);
}

void BGE::interim::Cleanup()
{
	Game::Cleanup();
}
