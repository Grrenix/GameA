#include <iostream>

#include <engine/prelude.hpp>
#include <engine/events/window_events.hpp>

int main(int argc, char *argv[])
{
    engine::WindowSpec windowSpec = engine::WindowSpec();
    windowSpec.Title = "Game A";
    windowSpec.Width = 1920;
    windowSpec.Height = 1080;
    windowSpec.Fullscreen = false;
    windowSpec.Borderless = false;

    engine::Application *app = engine::Application::New()->WithWindowSpec(&windowSpec);

    app->m_EventDispatcher->Subscribe<engine::WindowOpenedEvent>([](const engine::WindowOpenedEvent &e)
                                                                 { std::cout << "Window Opened! " << e.Data << '\n'; });

    app->Run();
}