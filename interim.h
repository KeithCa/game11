#pragma once
#include "Game.h"
#include "PhysicsController.h"
#include "PhysicsFactory.h"
#include <btBulletDynamicsCommon.h>

namespace BGE
{
	class interim :
		public Game
	{
	private:

	public:
		interim(void);
		~interim(void);
		bool Initialise();
		void Update(float timeDelta);
		void Cleanup();
		void CreateWall();
	};
}
