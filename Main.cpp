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

    struct colors_t colors;
    colors = loadBMP("./1.bmp");
    int width = colors.width;
    int height = colors.height;
    unsigned char * data = colors.data;

    // FILE *f = fopen("out.txt", "w");
    std::vector<std::vector<std::string>> mat(width, std::vector<std::string>(height));
    
    using element_t = std::unordered_map<int, std::string>;
    using line_t = std::vector<element_t>;
    using matrix_t = std::vector<line_t>;
    matrix_t res(width, line_t(height));

    element_t pair;
    int pos = 0;
    
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            pos = i * width * 4 + j * 4;
            std::ostringstream buff;
            buff << '[' << 
                (int)data[pos] << ',' << ' ' << 
                (int)data[pos+1] << ',' << ' ' << 
                (int)data[pos+2] << ']';
            // std::cout << buff.str();
            mat[i][j] = buff.str();
            // fprintf(f, buff.str().c_str());
        }
        // std::cout << std::endl;
        // fprintf(f, "\n");
    }

    int count = 1;
    for (int i = 0; i < width; i++) {
        std::string curr = mat[i][0];
        for (int j = 1; j < height; j++) {
            if (curr == mat[i][j]){
                count++;
            } else {
                std::cout << '(' << count << ',' << ' ' << curr << ')' << ' ';
                curr = mat[i][j];
                count = 1;
            }
        }
        std::cout << '(' << count << ',' << ' ' << curr << ')' << ' ';
        std::cout << std::endl;
    }
    
    // fclose(f);

    return 0;
}