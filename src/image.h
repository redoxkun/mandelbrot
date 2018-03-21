#ifndef MANDELBROT_IMAGE_H_
#define MANDELBROT_IMAGE_H_

#include <string>

namespace image
{

    class Image
    {
        int width;
        int height;

        unsigned char *data;
        std::size_t dataSize;

public:
        Image(int width, int height, const unsigned char *data);
        ~Image();
        void save(const std::string &filename);

    };

}

#endif

