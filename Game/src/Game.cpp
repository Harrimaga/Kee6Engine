#include <Kee6.h>

class Game : public Kee6::Application
{
public:
	Game()
	{

	}

	~Game()
	{

	}
};

Kee6::Application* Kee6::CreateApplication()
{
	return new Game();
}