#include <iostream>

#include "testModel.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char **)
{
    // create test model
    shared_ptr<TestModel> model = std::make_shared<TestModel>();

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "App for testing ClickHouse", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImFontConfig config;
    config.SizePixels = 18.0;
    config.OversampleH = 8;
    config.OversampleV = 7;
    io.Fonts->AddFontDefault(&config);

    // Setup Dear ImGui style
    // ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();
    ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool log_autoscroll = true;
    bool show_model_set = false;
    uint64_t rowCount = 0;
    ImVec4 clear_color = ImVec4(0.26f, 0.26f, 0.26f, 1.00f); // background color

    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoResize;

    // main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Main window", nullptr, window_flags);
        ImGui::SetWindowPos(ImVec2(0, 0));
        ImGui::SetWindowSize(ImVec2(650, 700));
        // DataBase settings
        {
            ImGui::Text("DataBase settings");

            static char dbName[128] = "test";
            ImGui::InputText("DB Name", dbName, IM_ARRAYSIZE(dbName));

            static char dbUser[128] = "default";
            ImGui::InputText("User", dbUser, IM_ARRAYSIZE(dbUser));

            static char dbPassword[128] = "masterkey";
            ImGui::InputText("Password", dbPassword, IM_ARRAYSIZE(dbPassword));

            static char dbTable[128] = "params";
            ImGui::InputText("Table name", dbTable, IM_ARRAYSIZE(dbTable));

            ImGui::Text("Table type:");
            static int dbType = 0;
            ImGui::RadioButton("Wide", &dbType, 0);
            ImGui::RadioButton("Slim", &dbType, 1);

            if (ImGui::Button("Apply connect setting"))
            {
                model->SetDbName(dbName);
                model->SetDbUser(dbUser);
                model->SetDbPassword(dbPassword);
                model->SetDbTable(dbTable);
                model->SetDbType(dbType);
            }
        }

        ImGui::Separator();

        // Test model settings
        {
            ImGui::Text("Test model settings");

            ImGui::Text("Settings for generate data (A * sin(F*t))");
            static int ampl = 10;
            ImGui::InputInt("Set A", &ampl);

            static int freq = 100;
            ImGui::InputInt("Set F", &freq);

            ImGui::Text("Choose params count");
            static int paramCount = 50;
            ImGui::DragInt("##dragint1", &paramCount, 1.0F, 0, 10000);

            ImGui::Text("Choose data type");
            static int rndType = 0;
            ImGui::RadioButton("Sin", &rndType, 0);
            ImGui::RadioButton("Saw", &rndType, 1);

            if (ImGui::Button("Apply model setting"))
            {
                model->SetAmpl(ampl);
                model->SetFreq(freq);
                model->SetParamsCount(paramCount);
                model->SetRndType(rndType);
            }
        }

        // show settings
        if (ImGui::Button("Open current settings"))
            show_model_set = true;

        if (show_model_set)
        {
            ImGui::Begin("Settings");
            string settings = model->ToStr();
            ImGui::TextUnformatted(settings.c_str());
            if (ImGui::Button("Close"))
                show_model_set = false;
            ImGui::End();
        }

        ImGui::Separator();

        if (model->prepareForTesting)
        {
            ImGui::TextColored(ImVec4(0.06f, 0.68f, 0.22f, 1.0f), "Ready for test");

            if (ImGui::Button("Update rows count"))
                rowCount = model->GetDBRowsCount();
            ImGui::SameLine();
            ImGui::Text("%s", to_string(rowCount).c_str());

            if (model->ths.size() == 0)
            {
                if (ImGui::Button("Start testing"))
                {
                    model->stopTh = false;
                    model->ths.push_back(thread(&TestModel::StartTesting, model));
                }
            }

            if (ImGui::Button("Drop DB"))
                model->DropDb();

            if (!model->ths.empty())
            {
                ImGui::Text("Threads: %i", model->ths.size());
                if (model->ths.size() < 10)
                {
                    if (ImGui::Button("add thread"))
                    {
                        model->stopTh = false;
                        model->ths.push_back(thread(&TestModel::StartTesting, model));
                    }
                }
                if (ImGui::Button("Stop testing"))
                {
                    model->stopTh = true;
                    sleep(5);
                    model->ClearThs();
                    allLog.push_back("Testing was stopped");
                }
            }
        }
        else
        {
            ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Need to prepare DB");
            if (ImGui::Button("Prepare DB"))
                model->ConnectToDbAndCreateTable();
        }

        ImGui::End();

        {
            // Logger
            ImGui::Begin("Log");
            ImGui::SetWindowPos(ImVec2(650, 0), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowSize(ImVec2(300, 300));

            if (ImGui::BeginPopup("Options"))
            {
                ImGui::Checkbox("Auto-scroll", &log_autoscroll);
                if (ImGui::Button("Clear log"))
                    allLog.clear();
                ImGui::EndPopup();
            }

            if (ImGui::Button("Options"))
                ImGui::OpenPopup("Options");

            ImGui::Separator();

            ImGui::BeginChild("scrolling", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);
            for (const auto str : allLog)
            {
                ImGui::TextWrapped(str.c_str());
                if (log_autoscroll)
                    ImGui::SetScrollHereY(1.0f);
            }
            ImGui::EndChild();
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
