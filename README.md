#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc == 1)
   {
        printf("No arguments have been specified. Please run the command with the following parameters");
        printf("");
   }   
    std::vector<string> files;
    std::vector<string> params;

    for (int i = 0; i < argc; i++) {
        if(argv[i].starts_with("-"))
            params.push_back(argv[i]);
        else if(argv[i].endss_with(".txt"))
            files.push_back(argv[i]);
    }
    char[] params=getParamsAsChar(params);
    for (int i = 0; i < files.size() ; i++) {
        for (int i = 0; i < params.size() ; i++) {
            if((params[i])=='a')
                
        }
    }

  //std::ifstream myfile; myfile.open("shopping_list.txt");
}

char[] getParamsAsChar(std::vector<string> params)
{
    
}
