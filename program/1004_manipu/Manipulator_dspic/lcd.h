void lcd_init(void);
void lcd_outs(char *buff);
void lcd_clr(void);
void lcd_home(void);
void lcd_locate(int line, int x);
void lcd_out8(unsigned char dat);
void lcd_out4(int rs, unsigned char dat);
void lcd_outi( long data );

