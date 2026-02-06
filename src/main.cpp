#include <iostream>

#include <engine/prelude.hpp>

int main(int argc, char *argv[])
{
    engine::WindowSpec windowSpec = engine::WindowSpec();
    windowSpec.Title = "Game A";
    windowSpec.Width = 1920;
    windowSpec.Height = 1080;

    engine::Application *app = engine::Application::New()->WithWindowSpec(&windowSpec);

    app->Run();
}