/* 単語を数える */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_TNG 500
#define TNG_SIZ 3

typedef struct{
    char    tango[TNG_SIZ+1];    /* 単語 */
    int        count;                /* カウント */
} TangoHyo ;

enum{ NO,YES } ;

int WordCnt( TangoHyo * tp, int num, const char * ptr )
{
    int pos ;
    int find;
    char buf[TNG_SIZ+1], *p ;
    while( *ptr != '\0' ){
        while( *ptr != '\0' && !isalpha(*ptr)){
            ptr++ ;
        }
        if( *ptr == '\0' ){
            break ;
        }
        p= buf ;
        for( pos= 0 ; pos < TNG_SIZ && isalpha(*ptr) ; pos++ ){
            *p++ = *ptr++ ;
        }
        *p= '\0';
        find= NO ;
        for( pos= 0 ; pos < num ; pos++ ){
            if( strcmp(tp[pos].tango,buf) == 0 ){
                tp[pos].count++ ;
                find= YES ;
                break ;
            }
        }
        if( !find ){
            strcpy(tp[num].tango,buf);
            tp[num].count= 1 ;
            num++ ;
        }
    }

    return num ;
}

int main(void)
{
    FILE *fp;
    char line[1024];
    TangoHyo tangohyo[ MAX_TNG ];
    int num=0;
    int cnt ;

    /* ファイルの読み込み */
    if((fp=fopen("NoMarkSample.txt","r"))==NULL)
    {
        printf("File not open...\n");
        exit(1);
    }

    /* 判断 */
    while( fgets( line, sizeof line, fp ) != 0){
        num= WordCnt( tangohyo, num, line ) ;
        if( MAX_TNG < num ){
            break ;
        }
    }
    fclose(fp);

    for( cnt= 0 ; cnt < num ; cnt++ ){
            printf("%s\t%d\n",tangohyo[cnt].tango, tangohyo[cnt].count);
    }

    return 0;
}
