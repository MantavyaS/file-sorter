#include <iostream>
#include <filesystem>
#include <string>

int main(){
    std::string path = ".";

    std::filesystem::directory_iterator i(path);
    std::filesystem::directory_iterator finish;

    int count = 0;
    while(i != finish){
        std::filesystem::directory_entry current = *i;
        if(current.is_regular_file()){
            std::filesystem::path filePath = current.path();
            std::string fileName = filePath.filename().string();
            std::string ext = filePath.extension().string();

            if(ext != ""){
                std::string folderName = ext.substr(1);
                std::filesystem::path folderPath = std::filesystem::path(path)/ folderName;

                if(!std::filesystem::exists(folderPath)){
                    std::filesystem::create_directories(folderPath);
                }

                std::filesystem::path newFilePath = folderPath/filePath.filename();
                std::filesystem::rename(filePath, newFilePath);

                std::cout<<"Moved: "<<fileName<<" to folder "<<folderName<<std::endl;

                count++;
    
            }
        }

        i++;
    }
    std::cout<<"Process finished. "<<count<<" Files sorted by extension"<<std::endl;
}