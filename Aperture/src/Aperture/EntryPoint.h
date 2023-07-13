#pragma once


#ifdef AE_PLATFORM_WINDOWS

extern Aperture::Application* Aperture::CreateApplication();

int main(int argc, char** argv)
{	
	Aperture::Log::Init();
	AE_CORE_ERROR("Hello!");
	AE_WARN("Welcome To Aperture Engine");	

	auto app = Aperture::CreateApplication();
	app->Run();
	delete app;
}

#endif
