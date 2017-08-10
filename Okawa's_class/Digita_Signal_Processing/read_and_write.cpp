/***********************************/
//
//数字と改行が交互に挟まるデータから
//数字のデータを抜き取るプログラム
//
/***********************************/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char a[10];
	int data[20000];
    FILE *fp;
    char file_name[] = "signal.txt";
	int i = 0;
	
    /* ファイルオープン */
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "%s\n", "error: can't read file.");
        return EXIT_FAILURE;
    }
    while (fscanf(fp, "%s", a) != EOF){
        data[i] = atoi(a);
		printf("%d\n",data[i]);
 		i++;
    }
    fclose(fp);
    printf("\n%d",i);
	return 0;

}