#include "Core/Engine.h"

int main()
{
	Proton::Engine engine;

	if (!engine.Initialize())
	{
		return -1;
	}
	
	if (!engine.Print())
	{
		return -1;
	}

	while (engine.GetWindowShouldClose())
	{
		engine.Loop();
	}

	engine.Shutdown();

	return 0;
}
