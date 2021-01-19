#include <iostream>
#include <math.h>

// z & c are complex numbers
// z(n+1) = z(n) + c
// z(0) = 0+0i
bool mandelbrot_check(float c_real, float c_imag, int iterate_max)
{
    float z_real = 0;
    float z_imag = 0;
    // (a+bi)^2 = (a+bi)(a+bi) = a^2+2abi+b^2(-1)
    for(int i = 0; i < iterate_max; i++)
    {
        z_real = pow(z_real, 2) + pow(z_imag, 2)*(-1) + c_real;
        z_imag = 2*z_real*z_imag + z_imag;
    }
    return sqrt( pow(z_real, 2) + pow(z_imag, 2) ) < 100 ? true : false;
}

int main(){
    float a;
    float b;

    bool check = mandelbrot_check(a, b, 1000);
    for(float i = -2; i <= 2; i = i + 0.02)
    {
        for(float j=-2; j<=2; j = j + 0.02)
        {
            if((mandelbrot_check(j, i, 1000) == 1))
                std::cout << "@";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
