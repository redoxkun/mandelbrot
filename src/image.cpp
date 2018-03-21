#include "image.h"
#include <cstring>
#include <fstream>

namespace image
{

    Image::Image(int width, int height, const unsigned char *data)
     : width(width), height(height)
    {
        dataSize = width * height * 3;
        this->data = new unsigned char[dataSize];
        std::memcpy(this->data, data, dataSize);
    }

    Image::~Image()
    {
        delete[] this->data;
    }

    void Image::save(const std::string &filename)
    {
        std::ofstream filestream(filename, std::ios::binary | std::ios::trunc);
        filestream << "P6 " << width << " " << height << " 255 ";
        filestream.write((char*)data, dataSize);
        filestream.close();
    }

}

