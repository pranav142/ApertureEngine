#pragma once


#ifdef AE_PLATFORM_WINDOWS

extern Aperture::Application* Aperture::CreateApplication();

int main(int argc, char** argv)
{	
	printf("Aperture Engine Has Started!\n");
	auto app = Aperture::CreateApplication();
	app->Run();
	delete app;
}

#endif
