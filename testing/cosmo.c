#include "gnuastro/cosmology.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%.10f\n",1e-8);
    printf("%f\n",gal_cosmology_comoving_volume(5,50,1.000000001,0.4,3000001));
    return 0;
}
