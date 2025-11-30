#include "oscillator.h"
using namespace std;

int main() {
    double x, t, v, m, k, l dt;
    double tmax = 20.0;

    pedirDatos(x, t, v, m, k, l, dt);
    guardarDatos("results/oscillator.dat", x, t, v, m, k, l, dt, tmax);

    return 0;
}