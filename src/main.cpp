#include <iostream>

#include <engine/prelude.hpp>
#include <engine/events/window_events.hpp>
#include <engine/events/input_events.hpp>
#include <engine/events/update_event.hpp>

int main(int argc, char *argv[])
{
    engine::WindowSpec windowSpec = engine::WindowSpec();
    windowSpec.Title = "Game A";
    windowSpec.Width = 1920;
    windowSpec.Height = 1080;
    windowSpec.Fullscreen = false;
    windowSpec.Borderless = false;

    engine::Application *app = engine::Application::New()->WithWindowSpec(&windowSpec);

    app->m_EventDispatcher->Subscribe<engine::WindowOpenedEvent>(
        [](const engine::WindowOpenedEvent &e)
        { std::cout << "Window Opened!" << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::WindowDestroyedEvent>(
        [](const engine::WindowDestroyedEvent &e)
        { std::cout << "Window Destroyed!" << '\n'; });

    app->m_EventDispatcher->Subscribe<engine::KeyPressedEvent>(
        [](const engine::KeyPressedEvent &e)
        { std::cout << "Key Pressed! " << engine::input::KeyToString(e.Data) << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::KeyReleasedEvent>(
        [](const engine::KeyReleasedEvent &e)
        { std::cout << "Key Released! " << engine::input::KeyToString(e.Data) << '\n'; });

    app->m_EventDispatcher->Subscribe<engine::MouseMovedEvent>(
        [](const engine::MouseMovedEvent &e)
        { std::cout << "Mouse Moved! (" << e.PosX << ", " << e.PosY << ")" << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::MouseScrollEvent>(
        [](const engine::MouseScrollEvent &e)
        { std::cout << "Mouse Scrolled! (" << e.DirX << ", " << e.DirY << ")" << '\n'; });

    app->m_EventDispatcher->Subscribe<engine::MouseButtonClickEvent>(
        [](const engine::MouseButtonClickEvent &e)
        { std::cout << "Mouse button clicked! (" << engine::input::MouseButtonToString(e.Button) << ")" << '\n'; });
    app->m_EventDispatcher->Subscribe<engine::MouseButtonReleaseEvent>(
        [](const engine::MouseButtonReleaseEvent &e)
        { std::cout << "Mouse button released! (" << engine::input::MouseButtonToString(e.Button) << ")" << '\n'; });

    app->m_EventDispatcher->Subscribe<engine::UpdateEvent>(
        [&](const engine::UpdateEvent &e)
        {
            engine::input::KeyState buttonStateA = app->m_InputStates->GetState(engine::input::Key::kA);
            if (buttonStateA == engine::input::KeyState::Pressed)
            {
                std::cout << "A is pressed" << '\n';
            }
            // std::cout << "Update! " << e.DeltaTime << '\n';
        });

    app->Run();
}