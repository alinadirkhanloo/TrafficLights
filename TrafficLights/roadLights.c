#include <mega32.h>
#include <delay.h>
int a,b,c,d,n;
char sr[10];
void left(void);
void right(void);
void main(void){
DDRA=0xff;
PORTA=0x00;
DDRB=0xff;
PORTB=0x00;
DDRD=0xff;
PORTD=0x00;
DDRC=0x7f;
PORTC=0x00;

a=2;
b=5;
c=2;
d=5;
n=50;
PORTB.0=1;
PORTD.2=1;
sr[0]=0x00;sr[1]=0x01;sr[2]=0x02;sr[3]=0x03;sr[4]=0x04;sr[5]=0x05;sr[6]=0x06;sr[7]=0x07;sr[8]=0x08;sr[9]=0x09;
while (1)
{ 
        while(n){
        PORTA=sr[a];
        PORTC.0=1; delay_ms(5);PORTC.0=0;PORTA=0x00;
        PORTA=sr[b];
        PORTC.1=1; delay_ms(5);PORTC.1=0;PORTA=0x00;
        PORTA=sr[c];
        PORTC.2=1; delay_ms(5);PORTC.2=0;PORTA=0x00;
        PORTA=sr[d];
        PORTC.3=1; delay_ms(5);PORTC.3=0;PORTA=0x00;
        n--;  
        }
        n=50;
        left();
        right();

}
}
void left(){
    if(a==0&&b==0&&PINB.0==1){
    PORTB.1=1;PORTB.0=0;PORTB.2=0;
    delay_ms(3000);
    }
    b--;
    if(b<0){
        a--;
        if(a<0 && PINB.1==1){
            PORTB.2=1;PORTB.1=0;
            a=2;b=5;
        }else if(a<0){
            a=2;b=0;PORTB.2=0;PORTB.0=1;
        }else{b=9;}
    }
}
void right(){
    if(c==0&&d==0 && PIND.0==1){
        PORTD.1=1;PORTD.0=0;PORTD.2=0;
        delay_ms(3000);
    }
    d--;
    if(d<0){
        c--;
        if(c<0 && PIND.1==1)
        {c=2;d=5;PORTD.1=0;PORTD.2=1;
        }else if(c<0){c=2;d=5;PORTD.2=0;PORTD.0=1;
        }else{d=9;}
    }
}