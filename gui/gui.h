#pragma once

#include <iostream>
#include <string>

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

namespace GUI {
    static GLFWwindow* window = nullptr;
    static bool open = true;

    static ImGuiStyle* style = 0;
    static ImVec4* colors = 0;

    void setup_theme();
    bool setup();
    void cleanup();
    void render_ui();
    void draw();
}