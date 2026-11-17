
#include "../engine/Log.h"
#include "../engine/PostedEngine.h"

//#include "../Math/Vec4.h"

int main()
{
	PostedEngine engine;

	if (!engine.Initialize())
	{
		return -1;
	}

	engine.Run();
	engine.Shutdown();

	return 0;
}