#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define tem "city011"
#define unk "city012"
#define frame 200
#define dimension 15

typedef struct{
	char name[20];//���O
	char word[20];//���t
	int frame_size;//�t���[���T�C�Y
	double MFCC[frame][dimension];//�f�[�^�ۑ�
}data;

data template_data;
data unknow_data;

//����ꂽ�\���̂̒��g��\������֐�
void confirmation(data confirmation_data)
{
	int i,j;
	printf("%s\n",confirmation_data.name);
	printf("%s\n",confirmation_data.word);
	printf("%d\n",confirmation_data.frame_size);
	for(i = 0;i < confirmation_data.frame_size; i++)
	{
		for(j=0; j < dimension; j++)
		{
			printf("%lf",confirmation_data.MFCC[i][j]);
		}
		printf("\n");
	}
}

//�t�@�C���̓ǂݍ��݂��s���֐�
data File_Read(char *file_name)
{
	FILE *file;
	data read_data;
	
	int i,j;
	//printf("%s\n",file_name);			//�J���t�@�C�����̊m�F
	file = fopen(file_name,"r");
	if(file == NULL)					//�t�@�C�����ǂݍ��߂Ȃ��ꍇ�Q�I��
	{
		printf("�t�@�C�����J���܂���\n");
		exit(1);
	}
	
	fscanf(file,"%s\n",read_data.name);
	fscanf(file,"%s\n",read_data.word);
	fscanf(file,"%d\n",&read_data.frame_size);
	
	for(i = 0;i < read_data.frame_size; i++)
	{
		for(j=0; j < dimension; j++)
		{
			fscanf(file,"%lf",&read_data.MFCC[i][j]);
		}
	}
	
	fclose(file);
	
	//confirmation(read_data);//�ǂݍ��񂾃f�[�^���m�F
	
	return read_data;
}

double road(double po_1,double po_2,double po_3)
{
	if(po_1 < po_2)
	{
		if(po_1 < po_3){return po_1;}
		else {return po_3;}
	}
	else
	{
		if(po_2 <po_3){return po_2;}
		else {return po_3;}
	}
}

//DP�}�b�`���O���s���֐�
double DP()
{
	int i,j,k;
	double d[frame][frame],g[frame][frame];
	double po_1,po_2,po_3;
	
	for(i = 0; i < template_data.frame_size; i++)
	{
		for(j = 0; j < unknow_data.frame_size; j++)
		{
			d[i][j] = 0;
			for(k = 0; k < dimension; k++)
			{
				d[i][j] += pow(template_data.MFCC[i][k] - unknow_data.MFCC[j][k],2);
			}
			d[i][j] = sqrt(d[i][j]);
			
			if(i == 0 && j == 0){g[i][j] = d[i][j];}
			else if(i == 0){g[i][j] = g[i][j- 1 ] + d[i][j];}
			else if(j == 0){g[i][j] = g[i - 1][j] + d[i][j];}
			else
			{
				po_1 = g[i][j - 1] + d[i][j];
				po_2 = g[i - 1][j - 1] + 2 * d[i][j];//sqrt(2)*d[i][j]
				po_3 = g[i-1][j] + d[i][j];
				
				g[i][j] = road(po_1,po_2,po_3);
			}
		}
	}
	return g[template_data.frame_size - 1][unknow_data.frame_size - 1] / (template_data.frame_size + unknow_data.frame_size);
}

int main(void)
{
	int i,j,count = 0;
	char file_name[20],word[20];
	double g;
	double min=0;
	for(i=0; i < 100; i++)
	{
		printf("%3d��",i+1);
		sprintf(file_name,"%s\\%s_%03d.txt",tem,tem,i+1);
		//printf("%s\n",file_name);//�J���t�@�C�������m�F
		template_data = File_Read(file_name);
		//confirmation(template_data);//�e���v���[�g�̃f�[�^�m�F
		for(j = 0; j < 100; j++)
		{
			sprintf(file_name,"%s\\%s_%03d.txt",unk,unk,j+1);
			//printf("%s\n",file_name);//�J���t�@�C�����̊m�F
			unknow_data = File_Read(file_name);
			//confirmation(unknow_data);//���m���͂̃f�[�^�m�F
			g=DP();
			
			if(j==0 || min > g)
			{
				min = g;
				strcpy(word,unknow_data.word);
			}
			
		}
		printf("%15s | %15s ",template_data.word,word);
		if(strcmp(template_data.word,word)==0)
		{
			printf("o\n");
			count++;
		}
		else{printf("x\n");}
	}
	
	printf("�e���v���[�g�F%s ���m���́F%s �F���� %3d\n",tem,unk,count);
	
	return 0;
}