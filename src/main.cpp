#include <iostream>

#include <engine/prelude.hpp>
#include <events/window_events.hpp>
#include <events/input_events.hpp>
#include <events/update_event.hpp>

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
                                                                 { std::cout << "Window Opened! " << e.Data->GetWindowHandle() << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::WindowDestroyedEvent>([](const engine::WindowDestroyedEvent &e)
                                                                    { std::cout << "Window Destroyed! " << e.Data->GetWindowHandle() << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::KeyPressedEvent>([](const engine::KeyPressedEvent &e)
                                                               { std::cout << "Key Pressed! " << engine::input::KeyToString(e.Data) << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::KeyReleasedEvent>([](const engine::KeyReleasedEvent &e)
                                                                { std::cout << "Key Released! " << engine::input::KeyToString(e.Data) << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::UpdateEvent>([&](const engine::UpdateEvent &e)
                                                           {
                                                               std::cout << "Keystate A: " << ((int)app->m_InputStates->GetState(engine::input::Key::kA) ? "Pressed" : "Unpressed") << '\n';
                                                               std::cout << "Update! " << e.DeltaTime << '\n'; });

    app->Run();
}