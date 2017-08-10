/*******************************************/
/* Generating Path File                    */
/*                                         */
/*                    ZD.Wang Jan.21, 2008 */
/*******************************************/

#include<stdio.h>
#include<stdlib.h>

void main(){
 FILE *fp1, *fp2;
 int cnt=0;
 double v_right, v_left;
 
 if((fp1 = fopen("Data.txt", "r"))==NULL){
  fprintf(stderr, "Can not find Data.txt\n");
  exit(1);
 }
 if((fp2 = fopen("path_data.h","w"))==NULL){
  fprintf(stderr, "Can not find DataPath.txt\n");
  exit(1);
 }
 

 fprintf(fp2, "int velo_data[]={\n", (int)v_right, (int)v_left );
 while(fscanf(fp1, "%lf %lf", &v_right, &v_left) != EOF){
  fprintf(fp2, "\t%d,\t%d,\n", (int)v_right, (int)v_left );
  cnt++;
        }

 fprintf(fp2, "\t0,\t0};\n\n");
        
 fprintf(fp2, "#define MaxNum %d\n", cnt );
        
 fclose(fp1);
 fclose(fp2);
 
 printf("左右車輪の速度データから軌道ファイルを生成し、path_data.hに結果をセーブした\n");
}