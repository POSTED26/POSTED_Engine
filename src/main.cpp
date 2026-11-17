
#include "../engine/Log.h"
#include "../engine/PostedEngine.h"

#include "../Math/Vec2.h"

int main()
{
	PostedEngine engine;

	Vec2 x = Vec2(1.0f, 2.0f);
	Vec2 y = Vec2(2.0f, 3.0f);

	Vec2 add = x + y;
	Vec2 sub = y - x;
	Vec2 mult = x * 2.0f;
	float len = y.Length();
	Vec2 nor = y.Normalize();

	Log::Info("Add: " + std::to_string(add.x) + ", " + std::to_string(add.y));
	Log::Info("Sub: " + std::to_string(sub.x) + ", " + std::to_string(sub.y));
	Log::Info("Mult: " + std::to_string(mult.x) + ", " + std::to_string(mult.y));
	Log::Info("Length: " + std::to_string(len));
	Log::Info("Normalize: " + std::to_string(nor.x) + ", " + std::to_string(nor.y));


	if (!engine.Initialize())
	{
		return -1;
	}

	engine.Run();
	engine.Shutdown();

	return 0;
}