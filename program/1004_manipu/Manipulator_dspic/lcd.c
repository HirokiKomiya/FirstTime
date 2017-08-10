#include "lcd.h"


#define LCD_D4 LATBbits.LATB6
#define LCD_D5 LATBbits.LATB7
#define LCD_D6 LATBbits.LATB8
#define LCD_D7 LATBbits.LATB9
#define LCD_RS LATFbits.LATF6
#define LCD_E  LATDbits.LATD8

//usec単位ディレイ（遅延，待ち時間）関数(タイマは使用していないので正確ではない)
void delay_us(int usec)
{
	usec=(int)(CLOCK*usec)/40;
	while(usec){
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		usec--;
	}
}

//msec単位ディレイ（遅延，待ち時間）関数（タイマは使用していないので正確ではない）
void delay_ms(int msec)
{
	int i;
	for(i=0; i<msec; i++){
		delay_us(1000);
	}
}

//#define LCD_D4 P3.DR.BIT.B0
//#define LCD_D5 P3.DR.BIT.B1
//#define LCD_D6 P3.DR.BIT.B2
//#define LCD_D7 P3.DR.BIT.B3
//#define LCD_RS P3.DR.BIT.B4
//#define LCD_E  P3.DR.BIT.B5


void lcd_init(void)
{
	//int i;
	
	/* 対応ポートピンを出力に設定 */
	//P3.DDR |= 0x3F;
	
	/* ＬＣＤの初期設定 */
	/* ソフトウエアリセット */
	
	/* 15ms 待つ */
	//for (i=0;i<31250;i++); //25000/20*25 	
	delay_ms(15);
	
	/* LCD Function Set 1 */
	lcd_out8(0x23);

	/* Wait 10ms */
	//for (i=0;i<20313;i++); //16250/20*25
  	delay_ms(10);
	/* LCD Function Set 2 */
	lcd_out8(0x23);
  
	/* Wait 10ms */
	//for (i=0;i<20313;i++);
  	delay_ms(10);
	/* LCD Function Set 3 */
	lcd_out8(0x23);
	
	/* LCD Function Set */
	lcd_out8(0x22);
	
	/* 初期設定 */
	/* LCD Function Set */
	lcd_out4(0, 0x28);
	
	/* 表示 ON */
	lcd_out4(0, 0x0E);
	
	/* エントリーモード */
	lcd_out4(0, 0x06);
	
	/* 表示クリア */
	lcd_clr();
}

void lcd_outs(char *buff)
{
	int count=0;
	
	while(*buff != '\0') {
		lcd_out4(1, *buff);
		buff++;
		count++;
		if (count==16) {
			break;
		}
	}
}

void lcd_out8(unsigned char dat)
{
	//int i;
	
	LCD_RS = 0;
	LCD_E = 1;
	LCD_D4 = (dat & 0x01);
	dat = dat >> 1;
	LCD_D5 = (dat & 0x01);
	dat = dat >> 1;
	LCD_D6 = (dat & 0x01);
	dat = dat >> 1;
	LCD_D7 = (dat & 0x01);
	
	/* Wait 1us */
	//for (i=0; i<3; i++);
	delay_us(50);
	LCD_E = 0;

	/* Wait 50us */
	//for (i=0; i<112; i++);
	delay_us(50);
}

void lcd_out4(int rs, unsigned char dat)
{
	unsigned char bk=dat;
	//int i;
	
	LCD_RS = rs;
	LCD_E = 1;
	
	/* 上位４ビット送出 */
	bk = bk >> 4;
	LCD_D4 = (bk & 0x01);
	bk = bk >> 1;
	LCD_D5 = (bk & 0x01);
	bk = bk >> 1;
	LCD_D6 = (bk & 0x01);
	bk = bk >> 1;
	LCD_D7 = (bk & 0x01);
	
	/* Wait 1us */
	//for (i=0; i<3; i++); //2/20*25
	delay_us(50);
	LCD_E = 0;
	/* Wait 50us */
	//for (i=0; i<112; i++); //90/20*25
	delay_us(50);
	/* 下位４ビットを送出 */
	LCD_E = 1;
	
	LCD_D4 = (dat & 0x01);
	dat = dat >> 1;
	LCD_D5 = (dat & 0x01);
	dat = dat >> 1;
	LCD_D6 = (dat & 0x01);
	dat = dat >> 1;
	LCD_D7 = (dat & 0x01);
	
	/* Wait 1us */
	//for (i=0; i<3; i++);
	delay_us(50);
	LCD_E = 0;
	/* Wait 50us */
	//for (i=0; i<112; i++);
	delay_us(50);
	LCD_RS=0;
}

void lcd_clr(void)
{
  //int i;
  
	lcd_out4(0,0x01);
	//for(i=0; i<3353; i++); //delay 1650us 2682/20*25
	delay_us(1650);
}

void lcd_home(void)
{
  //int i;
  
  lcd_out4(0,0x02);
  // for(i=0; i<3353; i++); //delay 1650us
  delay_us(1650);
}

void lcd_locate(int line, int x)
{
	if ((line == 1 || line == 2) && (x > 0 && x < 17)) {
		line--;
		x--;
		lcd_out4(0,0x80+0x40*line+x);
	}
}

void lcd_outi(long i){
  long j;
  int k;
  char s[6];
  k=0;

  if(i==0)lcd_out4(1,'0');
  if(i>=0) j=i;
  else{
    j=-i;
    lcd_out4(1,'-');
  }
  while(0<j){
     s[k++]=j-((long)(j/10)*10);
     j=(long)j/10;
  }
  while(k!=0){
  k-=1;
  lcd_out4(1,'0'+s[k]);
  }
}

