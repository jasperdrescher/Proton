#include "application.h"

int main()
{
	App application;

	if (!application.Initialize())
	{
		return -1;
	}
	
	if (!application.Print())
	{
		return -1;
	}

	while (application.GetWindowShouldClose())
	{
		application.Loop();
	}

	application.Shutdown();

	return 0;
}
