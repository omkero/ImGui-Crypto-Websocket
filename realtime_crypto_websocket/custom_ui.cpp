#include "custom_ui.h"

CustomUI::CustomUI() {};

void CustomUI::LoginPanel(GLFWwindow* window ,int child_height, int child_width, bool center) {

    int resize_win_width;
    int resize_win_height;
    ImGuiStyle& style = ImGui::GetStyle();

    glfwGetWindowSize(window, &resize_win_width, &resize_win_height);

	static char text_inp_buf1[999999] = "";
	static char text_inp_buf2[999999] = ""; 

    int spacing = 4;

    style.FramePadding = ImVec2(10.0f, 10.0f);
    style.ItemSpacing = ImVec2(10.0f, 20.0f);

    if (center) {
        ImGui::SetNextWindowPos(ImVec2((resize_win_width / 2) - (child_width / 2), (resize_win_height / 2) - (child_height / 2)));
    }
    else {
        ImGui::SetNextWindowPos(ImVec2(0,0));
    }

    ImGui::BeginChild("Calculate", ImVec2(child_width, child_height), true, ImGuiWindowFlags_NoResize);


    ImGui::Text("Enter Username:");
    ImGui::PushItemWidth(child_width - 16);  // Set width for the input box
    if (ImGui::InputText("##Username", text_inp_buf1, sizeof(text_inp_buf1))) {
        // You can add additional logic here for when the username changes.
    }


    ImGui::Text("Enter Password:");
    ImGui::PushItemWidth(child_width - 16);  // Set width for the input box
    if (ImGui::InputText("##Password", text_inp_buf2, sizeof(text_inp_buf2), ImGuiInputTextFlags_Password)) {
        // You can add additional logic here for when the password changes.
    }

    ImGui::PopItemWidth();  // Reset width


    if (ImGui::Button("SignIn")) {
        // handle click here
    }

    ImGui::EndChild();
}

void CustomUI::MenuBar(GLFWwindow *window) {
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open"))
            { /* Handle open action */
            }
            if (ImGui::MenuItem("Save"))
            { /* Handle save action */
            }
            if (ImGui::MenuItem("Exit"))
            {
                glfwTerminate();
                glfwDestroyWindow(window);
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View"))
        {
            if (ImGui::MenuItem("Demo"))
            {

            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo"))
            { /* Handle undo action */
            }
            if (ImGui::MenuItem("Redo"))
            { /* Handle redo action */
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::MenuItem("About"))
            { /* Handle about action */
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}