#include <Aperture.h>

class Sandbox : public Aperture::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Aperture::Application* Aperture::CreateApplication()
{
	return new Sandbox;
}
