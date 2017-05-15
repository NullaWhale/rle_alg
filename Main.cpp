#include <clocale>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include "loadBMP.h"

std::vector<std::string> compress(std::vector<std::string>);

int main() {
    setlocale(LC_ALL, "");

    struct colors_t colors;
    colors = loadBMP("./1.bmp");
    int width = colors.width;
    int height = colors.height;
    unsigned char * data = colors.data;

    FILE *in = fopen("in.txt", "w");
    FILE *out = fopen("out.txt", "w");
    std::vector<std::vector<std::string>> mat(width, std::vector<std::string>(height));

    int pos = 0;
    std::vector<std::string> res;
    
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            pos = i * width * 4 + j * 4;
            std::ostringstream buff;
            buff << '[' << 
                (int)data[pos] << ',' << ' ' << 
                (int)data[pos+1] << ',' << ' ' << 
                (int)data[pos+2] << ']';
            mat[i][j] = buff.str();
            fprintf(in, mat[i][j].c_str());
        }
        res = compress(mat[i]);
        for (int k = 0; k < res.size(); k++) {
        	fprintf(out, res[k].c_str());
        }
        fprintf(in, "\n");
    }
    
    fclose(in);
    fclose(out);

    return 0;
}

std::vector<std::string> compress(std::vector<std::string> line) {
	std::vector<std::string> resline;
	int count = 1;
	std::string curr = line[0];
    for (int j = 1; j < line.size(); j++) {
        if (curr == line[j]) {
            count++;
        } else {
        	std::ostringstream buff;
            buff << '(' << count << ',' << ' ' << curr << ')' << ' ';
            resline.push_back(buff.str());
            curr = line[j];
            count = 1;
        }
    }
    std::ostringstream buff;
    buff << '(' << count << ',' << ' ' << curr << ')' << ' ' << std::endl;
    resline.push_back(buff.str());
    return resline;
}