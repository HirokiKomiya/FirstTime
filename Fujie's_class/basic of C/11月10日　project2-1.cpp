//�z��ƍ\���̂ɂ���


//int vec[] ={0,0,1} //�z��̐錾�̎d��
//int vec[3];
//vec[0]=0;vec[1]=0;vec[3]=1; //����͏�̓z�Ɠ���
//char sp[] = "abc" //������̐錾�̎d��



//�������畡�f���̗�
struct complex{
	double re;
	double im;
}
//�����܂Œ�`

struct complex a,b; //complex�͂����̖��O
a.re=1.0;
a.im=2.3; //a�̒���re��im�������Ă�

b.re = a.re + 3.0;
b.im = a.im + 0.2;
//�����܂ŕ��f���̗�


//�ȉ���{�ƂȂ�v���O�����̌��^

struct person{
	int id;
	char name[40];
	long phone;
};
struct person student;

printf("%d %s %ld\n",&student.id,
					student.name,	//�z�񂾂���&����Ȃ�
					&student.phone);

