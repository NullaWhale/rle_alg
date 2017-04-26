#ifndef __LOAD_TEXTURE__
#define __LOAD_TEXTURE__

struct colors_t {
	char* name;
    int width;
    int height;
    unsigned char * data;
};

struct colors_t loadBMP(const char* filename);

#endif // __LOAD_TEXTURE__
