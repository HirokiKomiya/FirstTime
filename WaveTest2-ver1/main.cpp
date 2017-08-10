#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<locale.h>
#include"wavetest.h"

short gl_sound[FRAME];
char mode = 0;
short bWave[SAMPLING * 10];
long N=0;

void CALLBACK waveProc(HWAVEIN hwi, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	LPWAVEHDR	lpwvhdr;
	int length;
	int i;
        if(mode != 1) return;
	if(uMsg == WIM_DATA)
	{
		lpwvhdr = (LPWAVEHDR) dwParam1;
		length = lpwvhdr->dwBufferLength;
		/* キャプチャバッファ更新 *//*
		for(i=0;i<length;i++){
			bWave[N+i] = lpwvhdr->lpData[i];
			lpwvhdr->lpData[i]=0;
		}*/
		memcpy(gl_sound,lpwvhdr->lpData,length);
		//N+=length;
		lpwvhdr->dwFlags=0;
		waveInPrepareHeader(hwi, lpwvhdr, sizeof(WAVEHDR));
		waveInAddBuffer(hwi, lpwvhdr, sizeof(WAVEHDR));
	}
}

int waveOutCH1(char *fileName,short *sound,int N){
	int i,RIFFsize,fmtsize,sampling,bytepersec,datasize;
  	short fmttag,chan,bitpersample,blockboundary,data;
	FILE *fpo;
  	fmtsize=16;
  	chan=1;
  	bitpersample=16;
  	blockboundary=chan*bitpersample/8;
  	datasize=(N+1)*(int)blockboundary;
  	RIFFsize=7*4+fmtsize+datasize;
  	fmttag=1;
  	sampling=SAMPLING;
  	bytepersec=sampling*bitpersample/8*chan;
  	fpo=fopen(fileName,"wb");
  	fprintf(fpo,"RIFF");
  	fwrite(&RIFFsize,sizeof(int),(size_t)1,fpo);
  	fprintf(fpo,"WAVEfmt ");
  	fwrite(&fmtsize,sizeof(int),(size_t)1,fpo);
  	fwrite(&fmttag,sizeof(short int),(size_t)1,fpo);
  	fwrite(&chan,sizeof(short int),(size_t)1,fpo);
  	fwrite(&sampling,sizeof(int),(size_t)1,fpo);
  	fwrite(&bytepersec,sizeof(int),(size_t)1,fpo);
  	fwrite(&blockboundary,sizeof(short int),(size_t)1,fpo);
  	fwrite(&bitpersample,sizeof(short int),(size_t)1,fpo);
  	fprintf(fpo,"data");
  	fwrite(&datasize,sizeof(int),(size_t)1,fpo);
	fwrite(sound,sizeof(short),(size_t)N,fpo);
  	fclose(fpo);
	return 1;
}

int main(int argc,char *argv[])
{
	HWAVEIN hWaveIn;
	short sound[NUM][FRAME];
	WAVEFORMATEX wfe;
	WAVEHDR whdr[NUM];
	MMRESULT rs;
	WAVEINCAPS wavecaps;
	char string[MAXPNAMELEN*2];
	int i;
	int dev;
	size_t wTemp;
	
	wfe.wFormatTag = WAVE_FORMAT_PCM;
	wfe.nChannels = 1;
	wfe.nSamplesPerSec = SAMPLING;
	wfe.nAvgBytesPerSec = SAMPLING;
	wfe.wBitsPerSample = 16;
	wfe.nBlockAlign = wfe.nChannels * wfe.wBitsPerSample / 8;

	for(i=0;i<NUM;i++){
		whdr[i].lpData = (LPSTR)sound[i];
		whdr[i].dwBufferLength = FRAME*sizeof(short);
		whdr[i].dwLoops = 1;
		whdr[i].dwBytesRecorded = 0;
		whdr[i].dwFlags = 0;
		whdr[i].dwUser = 0;
		whdr[i].lpNext = 0;
		whdr[i].reserved = 0;
	}
	for(i=0;i<waveInGetNumDevs();i++)
	{
		waveInGetDevCaps(i,&wavecaps,sizeof(wavecaps));
		setlocale( LC_ALL, "japanese" );
		wcstombs_s( &wTemp, string, MAXPNAMELEN*2, wavecaps.szPname, _TRUNCATE );
		printf("%d : %s\n",i,string);
	}
	printf("オープンするディバイスを指定:0～%d\n",waveInGetNumDevs()-1);
	scanf("%d",&dev);
	printf("open\n");
	waveInOpen(&hWaveIn , dev , &wfe ,(DWORD)waveProc , 0 , CALLBACK_FUNCTION );
	//waveInOpen(&hWaveIn , WAVE_MAPPER , &wfe ,0 , 0 , CALLBACK_NULL );
	for(i=0;i<NUM;i++){
		waveInPrepareHeader(hWaveIn , &whdr[i], sizeof(WAVEHDR));
		waveInAddBuffer(hWaveIn , &whdr[i], sizeof(WAVEHDR));
	}
        mode = 1;
	waveInStart(hWaveIn);
	gl_Plot(argc, argv,gl_sound);
	waveInStop(hWaveIn);
        mode = 0;
        Sleep(30);
	for(i=0;i<NUM;i++){
		whdr[i].lpData=NULL;
		waveInUnprepareHeader(hWaveIn, &whdr[i], sizeof(WAVEHDR));
	}
	waveInClose(hWaveIn);
	//waveOutCH1("test.wav",bWave,N);
	/*FILE *file;
	int i;
	file=fopen("test.txt","w");
	for(i=0;i<SAMPLING*2.2;i++)
		fprintf(file,"%d\n",bWave[i]);
	fclose(file);*/
	return 0;
}
