#pragma once
#ifndef CUSTOM_UI
#define CUSTOM_UI

#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class CustomUI {
public:
	CustomUI();
	void LoginPanel(GLFWwindow* window, int child_height, int child_width, bool center = false);
	void MenuBar(GLFWwindow* window);
};

#endif // !CUSTOM_UI
