#include "gui.h"

GUI::GUI() {
    mInitialized = false;
}

GUI::~GUI() {
    if (mInitialized) {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}

void GUI::init(GLFWwindow* pWindow) {
    if (pWindow) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(pWindow, true);
        ImGui_ImplOpenGL3_Init("#version 150");
        mInitialized = true;
    }
    else {
        throw "Window is null";
    }
}

void GUI::render() {
    if (mInitialized) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Just testing

        static std::vector<Element*> elements {
            new Line(
                {
                    new Text("Sample Text"),
                    new Checkbox("Test"),
                    new Checkbox("Test2")
                }

            ),
            new Button("Test Button"), 
            new RadioButton(
                {
                    "radiobutton0", 
                    "radiobutton1", 
                    "radiobutton2", 
                    "radiobutton3"
                }, 1)
        };

        ImGui::Begin("Hello, world!");

        for (unsigned int i = 0; i < elements.size(); i++) {
            elements[i]->process();
        }

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}