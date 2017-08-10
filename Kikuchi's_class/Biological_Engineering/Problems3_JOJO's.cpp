#include<stdio.h>
#include<math.h>

#define PI 3.1425926535
#define max_i 5

//[i]の個数を決定
#define ch_i 3

int main(void)
{					 //0  1  2  3  E
	double a[max_i]	= {0, 0,  0, 2, 2};
	double al[max_i]= {0, 0, 90, 0, 0};
	double d[max_i]	= {2, 0,  0, 0, 0};
	double th[max_i]= {0, 0,  0, 0, 0};
	
	double matrix[max_i][4][4];
	double matrix_R[max_i][4][4] = {0};
	double matrix_tmp[4][4] = {	{1, 0, 0, 0},
								{0, 1, 0, 0},
								{0, 0, 1, 0},
								{0, 0, 0, 1}};
								
	double RPEi[3];
	double CP[3];	//外積(Cross Product)
	
	int i, j, k, l, m;
	
	printf("[ 1.1 ] homogeneous transform matrix \n\n");
	//matrix計算
	for(i=0;i<max_i;i++){
		matrix[i][0][0] = cos( th[i] / 180 * PI );
		matrix[i][0][1] = -sin( th[i] / 180 * PI );
		matrix[i][0][2] = 0;
		matrix[i][0][3] = a[i];
		
		matrix[i][1][0] = cos( al[i] / 180 * PI ) * sin( th[i] / 180 * PI );
		matrix[i][1][1] = cos( al[i] / 180 * PI ) * cos( th[i] / 180 * PI );
		matrix[i][1][2] = -sin( al[i] / 180 * PI );
		matrix[i][1][3] = d[i] * sin( al[i] / 180 * PI );
		
		matrix[i][2][0] = sin( al[i] / 180 * PI ) * sin( th[i] / 180 * PI );
		matrix[i][2][1] = sin( al[i] / 180 * PI ) * cos( th[i] / 180 * PI );
		matrix[i][2][2] = cos( al[i] / 180 * PI );
		matrix[i][2][3] = d[i] * cos( al[i] / 180 * PI );
		
		matrix[i][3][0] = 0;
		matrix[i][3][1] = 0;
		matrix[i][3][2] = 0;
		matrix[i][3][3] = 1;
		
		
		if(i==0){
			printf("RT%d = \n", i);
		}else{
			printf("%dT%d = \n", i-1, i);
		}
		for(j = 0; j < 4; j++){
			for (k = 0;k < 4; k++){
				printf("% 7.5f\t",matrix[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	printf("[ 1.2 ] homogeneous transform vector\n\n");
	for(i=0;i<max_i;i++){
		printf("RT%d = \n", i);
		for(m=0;m<4;m++){
			for(j=0;j<4;j++){
				for(k=0;k<4;k++){
					matrix_R[i][m][j] += matrix_tmp[m][k] * matrix[i][k][j];
				}
				printf("% 7.5f\t",matrix_R[i][m][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		//転写
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				matrix_tmp[j][k] = matrix_R[i][j][k];
			}
		}
	}
	
	for(i=0;i<max_i;i++){
		printf("\n");
		
		printf("RZ%d = \n",i);
		printf("% 7.5f\t\n",matrix_R[i][0][2]);
		printf("% 7.5f\t\n",matrix_R[i][1][2]);
		printf("% 7.5f\t\n",matrix_R[i][2][2]);
		printf("\n");
		
		printf("RP%d = \n",i);
		printf("% 7.5f\t\n",matrix_R[i][0][3]);
		printf("% 7.5f\t\n",matrix_R[i][1][3]);
		printf("% 7.5f\t\n",matrix_R[i][2][3]);
		printf("\n");
	}
	
	printf("[ 1.3 ] Cross Product\n\n");	//CP
	for(i=1;i<max_i;i++){
		//p
		RPEi[0] = matrix_R[4][0][3] - matrix_R[i][0][3];
		RPEi[1] = matrix_R[4][1][3] - matrix_R[i][1][3];
		RPEi[2] = matrix_R[4][2][3] - matrix_R[i][2][3];
		//外積
		CP[0] =  matrix_R[i][1][2] * RPEi[2] - matrix_R[i][2][2] * RPEi[1];
		CP[1] = -matrix_R[i][0][2] * RPEi[2] + matrix_R[i][2][2] * RPEi[0];
		CP[2] =  matrix_R[i][0][2] * RPEi[1] - matrix_R[i][1][2] * RPEi[0];
		
		printf("CP%d = \n", i);
		printf("% 7.5f\t\n",CP[0]);
		printf("% 7.5f\t\n",CP[1]);
		printf("% 7.5f\t\n",CP[2]);
		printf("\n");
	}
	
	printf("計算終了。\n");	//これが表示されればエラーは起きていない
	
	return 0;
	
}
