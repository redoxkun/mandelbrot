#include "config.h"
#include "mandelbrot.h"

int main(int argc, char *argv[])
{

    mandelbrot::Config config(argc, argv);

    mandelbrot::run(config);

    return 0;

}

