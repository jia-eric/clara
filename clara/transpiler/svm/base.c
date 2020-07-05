#include <stdio.h>
        #include <math.h>

        #define N_SUPPORT_VECTORS 35
        #define N_FEATURES 13
        #define N_CLASSES 3
        #define N_INTERCEPTS (N_CLASSES*(N_CLASSES-1))/2
        #define POLY

        #ifndef LINEAR
        #define GAMMA 0.0003565442887237912
        #define COEF 0.0
        #endif

double support_vectors[N_SUPPORT_VECTORS][N_FEATURES] = {{13.24,2.59,2.87,21.0,118.0,2.8,2.69,0.39,1.82,4.32,1.04,2.93,735.0},
{13.5,1.81,2.61,20.0,96.0,2.53,2.61,0.28,1.66,3.52,1.12,3.82,845.0},
{13.05,2.05,3.22,25.0,124.0,2.63,2.68,0.47,1.92,3.58,1.13,3.2,830.0},
{13.3,1.72,2.14,17.0,94.0,2.4,2.19,0.27,1.35,3.95,1.02,2.77,1285.0},
{13.07,1.5,2.1,15.5,98.0,2.4,2.64,0.28,1.37,3.7,1.18,2.69,1020.0},
{13.24,3.98,2.29,17.5,103.0,2.64,2.63,0.32,1.66,4.36,0.82,3.0,680.0},
{13.05,1.77,2.1,17.0,107.0,3.0,3.0,0.28,2.03,5.04,0.88,3.35,885.0},
{12.33,1.1,2.28,16.0,101.0,2.05,1.09,0.63,0.41,3.27,1.25,1.67,680.0},
{12.64,1.36,2.02,16.8,100.0,2.02,1.41,0.53,0.62,5.75,0.98,1.59,450.0},
{13.67,1.25,1.92,18.0,94.0,2.1,1.79,0.32,0.73,3.8,1.23,2.46,630.0},
{12.37,1.21,2.56,18.1,98.0,2.42,2.65,0.37,2.08,4.6,1.19,2.3,678.0},
{13.34,0.94,2.36,17.0,110.0,2.53,1.3,0.55,0.42,3.17,1.02,1.93,750.0},
{12.29,1.61,2.21,20.4,103.0,1.1,1.02,0.37,1.46,3.05,0.906,1.82,870.0},
{13.49,1.66,2.24,24.0,87.0,1.88,1.84,0.27,1.03,3.74,0.98,2.78,472.0},
{12.99,1.67,2.6,30.0,139.0,3.3,2.89,0.21,1.96,3.35,1.31,3.5,985.0},
{12.72,1.81,2.2,18.8,86.0,2.2,2.53,0.26,1.77,3.9,1.16,3.14,714.0},
{13.05,3.86,2.32,22.5,85.0,1.65,1.59,0.61,1.62,4.8,0.84,2.01,515.0},
{12.47,1.52,2.2,19.0,162.0,2.5,2.27,0.32,3.28,2.6,1.16,2.63,937.0},
{11.81,2.12,2.74,21.5,134.0,1.6,0.99,0.14,1.56,2.5,0.95,2.26,625.0},
{12.37,1.07,2.1,18.5,88.0,3.52,3.75,0.24,1.95,4.5,1.04,2.77,660.0},
{12.08,2.08,1.7,17.5,97.0,2.23,2.17,0.26,1.4,3.3,1.27,2.96,710.0},
{11.76,2.68,2.92,20.0,103.0,1.75,2.03,0.6,1.05,3.8,1.23,2.5,607.0},
{12.77,3.43,1.98,16.0,80.0,1.63,1.25,0.43,0.83,3.4,0.7,2.12,372.0},
{12.04,4.3,2.38,22.0,80.0,2.1,1.75,0.42,1.35,2.6,0.79,2.57,580.0},
{12.86,1.35,2.32,18.0,122.0,1.51,1.25,0.21,0.94,4.1,0.76,1.29,630.0},
{12.88,2.99,2.4,20.0,104.0,1.3,1.22,0.24,0.83,5.4,0.74,1.42,530.0},
{12.51,1.24,2.25,17.5,85.0,2.0,0.58,0.6,1.25,5.45,0.75,1.51,650.0},
{12.93,2.81,2.7,21.0,96.0,1.54,0.5,0.53,0.75,4.6,0.77,2.31,600.0},
{13.52,3.17,2.72,23.5,97.0,1.55,0.52,0.5,0.55,4.35,0.89,2.06,520.0},
{13.62,4.95,2.35,20.0,92.0,2.0,0.8,0.47,1.02,4.4,0.91,2.05,550.0},
{12.25,3.88,2.2,18.5,112.0,1.38,0.78,0.29,1.14,8.21,0.65,2.0,855.0},
{13.16,3.57,2.15,21.0,102.0,1.5,0.55,0.43,1.3,4.0,0.6,1.68,830.0},
{13.88,5.04,2.23,20.0,80.0,0.98,0.34,0.4,0.68,4.9,0.58,1.33,415.0},
{13.11,1.9,2.75,25.5,116.0,2.2,1.28,0.26,1.56,7.1,0.61,1.33,425.0},
{12.2,3.03,2.32,19.0,96.0,1.25,0.49,0.4,0.73,5.5,0.66,1.83,510.0}};
        double coefs[N_CLASSES-1][N_SUPPORT_VECTORS] = {{1.0,1.0,1.0,0.0,0.06962596154612716,1.0,0.13620810940532235,-0.0,-0.0,-0.0,-0.6402606891250083,-0.3539188705613418,-0.0,-0.0,-0.8196701735744447,-1.0,-0.0,-0.2562281678986123,-0.0,-0.11588480754849796,-1.0,-0.0,-0.0,-0.019871362243537232,-0.8044411353709592,-0.0,-0.0,-0.0,-0.0,-0.22830906691228472,-0.23831042648786194,-0.6340567587062234,-0.0,-0.0,-0.0},
{0.8619422920452471,0.0,0.0,0.043175095432086745,0.0,1.0,0.0,0.16390687903908477,1.0,1.0,0.0,0.0,0.24628164146274673,1.0,0.0,0.0,1.0,0.0,0.7339742210253832,0.0,0.0,1.0,0.6854803570207062,0.0,-1.0,-0.6188085416791259,-1.0,-1.0,-1.0,-0.045450336012029545,-0.0,-0.0,-1.0,-0.1653842208567479,-1.0}};
        unsigned int ranges[N_CLASSES+1] ={0,7,24,35};
        double intercepts[N_INTERCEPTS] = {-5.6712175875313795,-2.8830650247178187,3.327984575597984};


        #ifndef RBF
        double * linear_kernel(double * sample, double * kernels){
            int i = 0, j=0;

            for(i=0; i<N_SUPPORT_VECTORS; i++){
                kernels[i] = 0;
                for(j=0; j<N_FEATURES; j++){
                    kernels[i] += support_vectors[i][j] * sample[j];
                }
            }

            return kernels;
        }
        #else
        double * rbf_kernel(double * sample, double * kernels){
            int i = 0, j=0;
            double aux = 0.0;
            for(i=0; i<N_SUPPORT_VECTORS; i++){
                kernels[i] = 0;
                for(j=0; j<N_FEATURES; j++){
                    aux = (support_vectors[i][j] - sample[j]);
                    kernels[i] += (aux * aux);
                }
                kernels[i] = exp(-1* GAMMA * kernels[i]);
            }

            return kernels;
        }
        #define KERNEL(...) rbf_kernel(__VA_ARGS__)
        #endif

        #ifdef POLY
        #define DEGREE 2
        double * polynomial_kernel(double * sample, double * kernels){
            linear_kernel(sample, kernels);

            for(int i=0; i<N_SUPPORT_VECTORS; i++){
                kernels[i] = (GAMMA * kernels[i] + COEF);
                kernels[i] = pow(kernels[i], DEGREE);
            }

            return kernels;

        }
        #define KERNEL(...) polynomial_kernel(__VA_ARGS__)
        #endif

        #ifdef SIGMOID
        double * sigmoid_kernel(double * sample, double * kernels){
            linear_kernel(sample, kernels);

            for(int i=0; i<N_SUPPORT_VECTORS; i++){
                kernels[i] = (GAMMA * kernels[i] + COEF);
                kernels[i] = tanh(kernels[i]);
            }

            return kernels;

        }
        #define KERNEL(...) sigmoid_kernel(__VA_ARGS__)
        #endif

        #ifdef LINEAR
        #define KERNEL(...) linear_kernel(__VA_ARGS__)
        #endif

        int predict(double * sample){
            double decision_rule = 0.0;
            unsigned int amounts[N_CLASSES] = {0}, d_rule = 0, class = 0, i=0, j=0, k=0;
            double kernels[N_SUPPORT_VECTORS] = {};

            KERNEL(sample, kernels);

            for(i=0; i < N_CLASSES; i++){
                amounts[i] = 0; //Just to ensure everything is cleared
            }

            for(i=0; i < N_CLASSES; i++){
                for(j=i+1; j < N_CLASSES; j++){

                    for(k=ranges[j]; k<ranges[j+1]; k++){
                        decision_rule += kernels[k] * coefs[i][k];
                    }

                    for(k=ranges[i]; k<ranges[i+1]; k++){
                        decision_rule += kernels[k] * coefs[j-1][k];
                    }

                    if(decision_rule + intercepts[d_rule] > 0){
                        amounts[i]++;
                    }
                    else{
                        amounts[j]++;
                    }

                    d_rule++;

                }
            }

            for(i=0; i<N_CLASSES; i++){
                class = (amounts[i] > amounts[class]) ? i : class;
            }


            return class;
        }

int main(){
    int class = 0;

    double sample[] = {12.0,0.92,2.0,19.0,86.0,2.42,2.26,0.3,1.43,2.5,1.38,3.12,278.0};

    class = predict(sample);

    printf("%d", class);
    return class;
}