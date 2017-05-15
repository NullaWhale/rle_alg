#include <cstdio>
#include "loadBMP.h"

#pragma pack(push, 1)
struct header_t
{
    unsigned char field[2];
    unsigned int size;
    unsigned short reserved1, reserved2;
    unsigned int data_offset;
};

struct info_header_t
{
    unsigned int header_size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression_method;
    unsigned int size;
    int h_resolution;
    int v_resolution;
    unsigned int number_of_colors;
    unsigned int number_of_important_colors;
};
#pragma pack(pop)

struct colors_t loadBMP(const char* filename)
{
    struct colors_t map;
    map.name = (char*)filename;

    FILE* file = fopen(filename, "rb");

    struct header_t header;
    fread(&header, sizeof(header), 1, file);

    struct info_header_t info_header;
    fread(&info_header, sizeof(info_header), 1, file);

    map.data = new unsigned char[info_header.size];
    fseek(file, header.data_offset, SEEK_SET);

    fread(map.data, 1, info_header.size, file);

    map.width = info_header.width;
    map.height = info_header.height;

    fclose(file);
    return map;
}