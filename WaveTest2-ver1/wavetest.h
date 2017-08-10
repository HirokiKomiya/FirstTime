#define NUM 100
#define FRAME 1024
#define SAMPLING 44100

//short gl_sound[FRAME];

int gl_Plot(int argc,char *argv[],short *sound);
int calc_spec(double *spec,short *sound, int size);
int calc_powerspec(double *powerspec, short *sound, int size);
int calc_sound_to_spec_houraku(double *houraku, short *sound, int size);