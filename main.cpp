#include <clocale>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include "loadBMP.h"

int main() {
    setlocale(LC_ALL, "");

    struct map_t colors;
    colors = loadBMP("./1.bmp");
    int width = colors.width;
    int height = colors.height;
    unsigned char * data = colors.data;

    FILE *f = fopen("out.txt", "w");
    int pos = 0;
    std::vector<std::vector<std::string>> mat(width, std::vector<std::string>(height));
    std::unordered_map<int, std::string> u;
    
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            pos = i * width * 4 + j * 4;
            std::ostringstream buff;
            buff << '[' << 
                (int)data[pos] << ',' << ' ' << 
                (int)data[pos+1] << ',' << ' ' << 
                (int)data[pos+2] << ']' << ' ';
            std::cout << buff.str();
            fprintf(f, buff.str().c_str());
        }
        fprintf(f, "\n");
    }

    fclose(f);

    return 0;
}
