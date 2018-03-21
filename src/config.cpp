#include "config.h"
#include <cstring>
#include <cstdlib>

#include <iostream>

namespace mandelbrot
{

    Config::Config(int argc, char *argv[])
    {
        bool isWidthRead = false;
        bool isHeightRead = false;
        bool isIterationsRead = false;
        bool isOutputRead = false;

        smooth = false;

        for (int i = 1; i < argc; ++i)
        {
            if (strcmp(argv[i], "-w") == 0)
            {
                ++i;
                if (i == argc)
                {
                    std::cerr << "Width value is missing."<< std::endl;
                    std::exit(EXIT_FAILURE);
                }

                width = std::atoi(argv[i]);
                if (width <= 0)
                {
                    std::cerr << "Width value is not valid: " << argv[i] << std::endl;
                    std::exit(EXIT_FAILURE);
                }

                isWidthRead = true;
            }
            else if (strcmp(argv[i], "-h") == 0)
            {
                ++i;
                if (i == argc)
                {
                    std::cerr << "Height value is missing."<< std::endl;
                    std::exit(EXIT_FAILURE);
                }

                height = std::atoi(argv[i]);
                if (height <= 0)
                {
                    std::cerr << "Height value is not valid: " << argv[i] << std::endl;
                    std::exit(EXIT_FAILURE);
                }

                isHeightRead = true;
            }
            else if (strcmp(argv[i], "-i") == 0)
            {
                ++i;
                if (i == argc)
                {
                    std::cerr << "Max. iterations value is missing."<< std::endl;
                    std::exit(EXIT_FAILURE);
                }

                iterations = std::atoi(argv[i]);
                if (iterations <= 0)
                {
                    std::cerr << "Max. iterations value is not valid: " << argv[i] << std::endl;
                    std::exit(EXIT_FAILURE);
                }

                isIterationsRead = true;
            }
            else if (strcmp(argv[i], "-s") == 0)
            {
                smooth = true;
            }
            else if (strcmp(argv[i], "-o") == 0)
            {
                ++i;
                if (i == argc)
                {
                    std::cerr << "Output filename value is missing."<< std::endl;
                    std::exit(EXIT_FAILURE);
                }

                filename = argv[i];
                isOutputRead = true;
            }
            else if (strcmp(argv[i], "--help") == 0)
            {
                std::cout << "Arguments:" << std::endl;
                std::cout << "  -w      Image width" << std::endl;
                std::cout << "  -h      Image height" << std::endl;
                std::cout << "  -i      Max. iterations" << std::endl;
                std::cout << "  -s      Use smooth coloring" << std::endl;
                std::cout << "  -o      Output filename (optional)" << std::endl;
                std::cout << "  --help  Shows this help and exits" << std::endl;
                std::exit(EXIT_SUCCESS);
            }
            else
            {
                std::cerr << "Unknown argument: " << argv[i] << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }

        if (!isWidthRead)
        {
            std::cerr << "Width argument is missing."<< std::endl;
            std::cerr << "Use '-w' to define a width value."<< std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (!isHeightRead)
        {
            std::cerr << "Height argument is missing."<< std::endl;
            std::cerr << "Use '-h' to define a height value."<< std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (!isIterationsRead)
        {
            std::cerr << "Max. iterations argument is missing."<< std::endl;
            std::cerr << "Use '-i' to define a max. iterations value."<< std::endl;
            std::exit(EXIT_FAILURE);
        }

        if (!isOutputRead)
        {
            filename = "output.ppm";
        }
    }

}

