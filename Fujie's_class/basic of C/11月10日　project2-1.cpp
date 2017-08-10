//配列と構造体について


//int vec[] ={0,0,1} //配列の宣言の仕方
//int vec[3];
//vec[0]=0;vec[1]=0;vec[3]=1; //これは上の奴と同じ
//char sp[] = "abc" //文字列の宣言の仕方



//ここから複素数の例
struct complex{
	double re;
	double im;
}
//ここまで定義

struct complex a,b; //complexはただの名前
a.re=1.0;
a.im=2.3; //aの中にreとimが入ってる

b.re = a.re + 3.0;
b.im = a.im + 0.2;
//ここまで複素数の例


//以下基本となるプログラムの原型

struct person{
	int id;
	char name[40];
	long phone;
};
struct person student;

printf("%d %s %ld\n",&student.id,
					student.name,	//配列だから&いらない
					&student.phone);

