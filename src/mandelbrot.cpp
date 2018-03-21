#include "mandelbrot.h"
#include "image.h"
#include <cmath>

#include <iostream>

namespace mandelbrot
{

    void mandelbrot(int width, int height, int maxIterations, bool smooth, unsigned char *data)
    {
        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < height; ++j)
            {
                float x0 = (float)i / (float)width * 4.f - 2.5f;
                float y0 = (float)j / (float)height * 3.f - 1.5f;
                float x = 0.f;
                float y = 0.f;
                int iteration = 0;

                while (x * x + y * y < 2.f * 2.f && iteration < maxIterations)
                {
                    float xtemp = x * x - y * y + x0;
                    y = 2.f * x * y + y0;
                    x = xtemp;
                    ++iteration;
                }

                float fiteration = (float)iteration;
                if (smooth && (iteration < maxIterations))
                {
                    float log_zn = log(x * x + y * y) / 2.f;
                    float nu = log2(log_zn / log(2));
                    fiteration = fiteration + 1 - nu;
                }
                unsigned char color = (unsigned char)((1.f - fiteration / (float)maxIterations) * 255.f);

                data[j * width * 3 + i * 3] = color;
                data[j * width * 3 + i * 3 + 1] = color;
                data[j * width * 3 + i * 3 + 2] = color;

                std::cout << "\r" << (int)((float)(i * height + j) / (float)(width * height) * 100.f) << "%";
            }
        }

        std::cout << "\r100% done." << std::endl;
    }

    void run(Config &config)
    {
        int width = config.width;
        int height = config.height;
        int iterations = config.iterations;
        bool smooth = config.smooth;
        unsigned char *data = new unsigned char[width * height * 3];

        mandelbrot(width, height, iterations, smooth, data);

        image::Image testImage(width, height, data);
        testImage.save(config.filename);
    }

}

