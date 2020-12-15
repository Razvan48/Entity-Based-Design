#include <iostream>

#include "WindowManager/WindowManager.h"
#include "Entity/Entity.h"
#include "Transform2D Component/Transform2DComponent.h"
//#include "Components/Components.h"

//

int main()
{
	WindowManager* windowManager = new WindowManager(1024, 1024, "2D Game");

	Entity* entity = new Entity();
	entity->AddComponent(new Transform2DComponent(0.0, 0.0, 100.0, 100.0));

	while (!windowManager->ShouldWindowClose())
	{
		windowManager->PreFrameDraw();

		std::cout << entity->GetComponent<Transform2DComponent>()->xCenter << '\n';

		windowManager->PostFrameDraw();

		std::cout << "FPS :: " << 1.0 / windowManager->GetDeltaTime() << '\n';
	}

	delete windowManager;

	return 0;
}