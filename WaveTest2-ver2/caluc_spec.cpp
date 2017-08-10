#include "wavetest.h"
#include <stdio.h>
#include <malloc.h>
#include "fftw3.h"
#include <math.h>
#include <conio.h>

#define RE(x) ((x)[0])
#define IM(x) ((x)[1])

int calc_spec(double *spec, short *sound, int size)
{
	int          i, j;
	int          x;
	char         FileName[256];
	double       Temp;
	fftw_complex *time_signal    = NULL;
	fftw_complex *spectrum       = NULL;
	fftw_plan    fft_plan        = NULL;
	
	time_signal    = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * size);
	spectrum       = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * size);
	if(!time_signal || !spectrum )
	{
		printf("fftw_malloc error\n");
		return 1;
	}
	fft_plan  = fftw_plan_dft_1d(size, time_signal, spectrum, FFTW_FORWARD, FFTW_ESTIMATE);
	if(!fft_plan)
	{
		printf("fftw_plan_dft_1d error\n");
		return 1;
	}
	for(i=0;i<size;i++)
	{
		RE(time_signal[i]) = (double)sound[i] / 0x7FFF;
		IM(time_signal[i]) = 0.0;
	}
	fftw_execute(fft_plan);
	for(j = 0; j < size / 2; j++){
		Temp = ((RE(spectrum[j]) * RE(spectrum[j]) + IM(spectrum[j]) * IM(spectrum[j])) / size);
		spec[j] = sqrt(Temp);
	}
	fftw_free(time_signal);
	fftw_free(spectrum);
	fftw_destroy_plan(fft_plan);
	return 0;
}

int calc_powerspec(double *powerspec, short *sound, int size)
{
	double *Temp;
	int i;
	Temp = (double*)malloc(size/2*sizeof(double));
	calc_spec(Temp, sound, size);
	for(i = 0; i < size/2; i++)
	{
		if(Temp[i] == 0)
		{
			powerspec[i] = 20 * log10(0.00000000000001);
		}
		else{
			powerspec[i] = 20 * log10(Temp[i]);
		}
	}
	return 0;
}

int calc_sound_to_spec_houraku(double *houraku, short *sound, int size)
{
	int i;
	double *power_spec;

	fftw_plan    fft_plan        = NULL;
	fftw_plan    ifft_plan       = NULL;
	fftw_complex *power_spectrum = NULL;
	fftw_complex *cepstrum       = NULL;
	fftw_complex *power          = NULL;

	power_spec = (double*)malloc(size/2*sizeof(double));
	if(calc_powerspec(power_spec, sound, size)) return 1;

	power_spectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (size / 2));
	cepstrum       = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (size / 2));
	power          = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (size / 2));

	if(!power_spectrum || !cepstrum || !power){
		printf("fftw_malloc error\n");
		return 1;
	}

	for(i=0;i<size/2;i++)
	{
		RE(power_spectrum[i]) = power_spec[i];
		IM(power_spectrum[i]) = 0.0;
	}
	fft_plan  = fftw_plan_dft_1d(size / 2, power_spectrum, cepstrum, FFTW_FORWARD, FFTW_ESTIMATE);
	if(!fft_plan){
		printf("fftw_plan_dft_1d error\n");
		return 1;
	}
	fftw_execute(fft_plan);
	for(i = 40; i < size / 2 - 40; i++){
		RE(cepstrum[i]) = 0.0;
		IM(cepstrum[i]) = 0.0;
	}
	ifft_plan  = fftw_plan_dft_1d(size / 2, cepstrum, power, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(ifft_plan);
	for(i=0;i<size/2;i++)
	{
		houraku[i]=RE(power[i])/(size/2);
	}
	free(power_spec);
	fftw_free(power_spectrum);
	fftw_free(cepstrum);
	fftw_free(power);
	fftw_destroy_plan(fft_plan);
	fftw_destroy_plan(ifft_plan);
}