#ifndef MANDELBROT_CONFIG_H_
#define MANDELBROT_CONFIG_H_

#include <string>

namespace mandelbrot
{

    class Config
    {
public:
        int width;
        int height;

        int iterations;

        bool smooth;

        std::string filename;

        Config(int argc, char *argv[]);
    };

}

#endif

