#include <stdio.h>
#include <math.h>
#define MAX_ITERATION 256

// Check if complex number is in the mandelbrot set.
// z & c are complex numbers
// z(n+1) = z(n) + c
// z(0) = 0+0i
bool mandelbrot_check(float c_real, float c_imag)
{
    float z_real = 0;
    float z_imag = 0;
    // (a+bi)^2 = (a+bi)(a+bi) = a^2+2abi+b^2(-1)
    for(int i = 0; i < MAX_ITERATION; i++)
    {
        z_real = pow(z_real, 2) - pow(z_imag, 2) + c_real;
        z_imag = 2*z_real*z_imag + c_imag;
    }
    float dist = sqrt( pow(z_real, 2) + pow(z_imag, 2));
    return (dist < 2) ? true : false;
}

int main(){

    // This prints a window containing the mandelbrot set. It
    // currently looks stupid, but you can make out some of 
    // the notable features. Check output.txt
    for(float i = 1.5; i >= -1.5; i -= 0.01)
    {
        for(float r = -1.5; r <= 1; r += 0.01)
        {
            if((mandelbrot_check(r, i) == true))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
