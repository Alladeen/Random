#include <reg52.h>
#include <string.h>

//lcd pins
#define  LCDDATA P2
sbit RS   = P0^5;
sbit RW  = P0^6;
sbit EN  = P0^7;

void delay2() //delay function
{
unsigned int k,i;
for(k=0;k<2;k++)
for(i=0;i<=22000;i++);

}
void delay3() //delay function
{
unsigned int k,i;
for(k=0;k,15;k++)
for(i=0;i<=22000;i++);
}

void LCDCMD(unsigned char CMD)
{
                     LCDDATA=CMD;               //copy data to the data bus
                     RS=0;                                  //rs=0 for command 
                     RW=0;                                 //rw=0 for writing
                     EN=1;                                  //make enable high
	delay2();
                     EN=0;                                    // make enable low

}

void LCDData(unsigned char Data)
{
                      LCDDATA=Data; 	//copy data to the data bus
                      RS=1;                          //rs=1 for data
                      RW=0;                         //rw=0 for writing 
                      EN=1;                         //make enable high
	delay2();
                      EN=0;                         //make enable low

}

void LCDString1(unsigned char* str)  //display string on lcd
{
int i ;
	for(i=0;str[i]!=0;i++)
	{
		LCDData(str[i]);
	}
}

/*Finction to intialize LCD*/
void init_LCD()
{
/*Command to Select 2 line,5x7 matrix mode of LCd*/
LCDCMD(0x38);
/*Command to shift the cursor to next position when Data is sent in LCD*/
LCDCMD(0x06);
/*Command to ON Display,OFF the Cursor in LCD*/
LCDCMD(0x0C);
/*Return cursor home*/
LCDCMD(0x02);
}

void main( )
{
	init_LCD();                     //intialise the lcd
	 LCDCMD(0x80);           //select lcd 1st line starting position
                 LCDString1("PASSWORD BASED");// display string lcd
                                          //select second starting position line 

             
}