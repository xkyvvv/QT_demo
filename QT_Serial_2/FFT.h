#ifndef FFT_H
#define FFT_H

#pragma once

#define MAX_MATRIX_SIZE  4194304  // 2048 * 2048
#define PI                                           3.141592653
#define MAX_VECTOR_LENGTH 10000             //

typedef struct Complex
{
    double rl;
    double im;
}Complex;

class CFFT
{
public:
    CFFT(void);
    ~CFFT(void);

public:
    bool fft(Complex   const inVec[], int   const len, Complex   outVec[]);            // 基于蝶形算法的快速傅里叶变换
    bool ifft(Complex   const inVec[], int   const len, Complex   outVec[]);

    void printCpx(Complex const *vec, int len);

    bool is_power_of_two(int   num);
    int    get_computation_layers(int   num);         // calculate the layers of computation needed for FFT
};


#endif // FFT_H
