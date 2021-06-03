#include <Havana.h>

class Sandbox : public Havana::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Havana::Application* Havana::CreateApplication()
{
	return new Sandbox();
}