#include "Application.h"
#include "ImGuiFileDialog.h"
#include "imgui.h"
#include <string>
#include "filesystem"
#include <iostream>
#include "lib/ImGuiFileDialog/dirent/dirent.h"


namespace MyApp {   

    void RenderUI() {
        ImGui::Begin("Settings");
        ImGui::Text("File Dialog Example");


        // open Dialog Simple
        if (ImGui::Button("Open File Dialog"))
            ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".*", ".");

        // display
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
        {
            // action if OK
            if (ImGuiFileDialog::Instance()->IsOk())
            {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                // action
            }

            // close
            ImGuiFileDialog::Instance()->Close();
        }



        ImGui::ShowDemoWindow();
        ImGui::End();
    }
}
