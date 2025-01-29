#pragma once
#ifndef IMGUI_STYLE_H
#define IMGUI_STYLE_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

void LoadUbuntuStyle() {
    // light style from Pacôme Danhiez (user itamago) https://github.com/ocornut/imgui/pull/511#issuecomment-175719267
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.FrameRounding = 5.0f;  // Slightly rounded corners
    style.WindowRounding = 3.0f; // Rounded windows

    // Base colors
    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f); // Dark background
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.18f, 0.18f, 0.18f, 0.94f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

    // Frame colors
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.88f, 0.45f, 0.13f, 0.68f); // Ubuntu orange hover
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);  // Ubuntu orange active

    // Title bar
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f); // Ubuntu orange active
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.14f, 0.14f, 0.14f, 0.75f);

    // Scrollbar
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.88f, 0.45f, 0.13f, 0.68f); // Orange hover
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);  // Orange active

    // Buttons
    style.Colors[ImGuiCol_Button] = ImVec4(0.88f, 0.45f, 0.13f, 0.40f); // Semi-transparent orange
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.88f, 0.45f, 0.13f, 0.80f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);

    // Headers
    style.Colors[ImGuiCol_Header] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.88f, 0.45f, 0.13f, 0.80f); // Ubuntu orange hover
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);  // Ubuntu orange active

    // Tabs
    style.Colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.88f, 0.45f, 0.13f, 0.80f); // Ubuntu orange hover
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);  // Ubuntu orange active
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);

    // Resize grip
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.88f, 0.45f, 0.13f, 0.25f); // Semi-transparent orange
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.88f, 0.45f, 0.13f, 0.67f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.88f, 0.45f, 0.13f, 0.95f);

    // Text selection
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.88f, 0.45f, 0.13f, 0.35f);

    // Other colors
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.88f, 0.45f, 0.13f, 0.40f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.88f, 0.45f, 0.13f, 1.00f);

    // Plot and histogram
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.50f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);

    // Setup ImGui style
   // ImGui::StyleColorsDark();
}

#endif // !IMGUI_STYLE_h
