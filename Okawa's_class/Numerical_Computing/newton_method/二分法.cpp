#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1.0e-5              //��������

double f(double x);
void nibun(void); 

int main()
{
        nibun();

        return 0;
}

void nibun(void)
{
        int count;
        double a,b,m;

        count=0;

        printf("�͈͂̍��̒l����͂��Ă�������.\n");
        scanf("%lf",&a);
        printf("�͈͂̉E�̒l����͂��Ă�������.\n");
        scanf("%lf",&b);

        do {
                count++;
                m=(a+b)/2.0;
                if(f(m)*f(a)<0) b=m;
                else a=m;

//�P�O�O�O��J��Ԃ��ĉ����������Ȃ�������v���O�������I��������
                if(count==1000) {
                        printf("�������܂���ł���.\n");
                        exit(1);
                }
        } while (!(fabs(a-b)<eps));             //�������������烋�[�v���I��

        printf("���̒l�� %f\n��������̂� %d �񂩂���܂���.",m,count);

}

double f(double x)
{
        return(x-1)*(x+1);
}