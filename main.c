#include "MKL25Z4.h"
int puls = 12;
int led[7]={0,1,2,3,4,5,6};
int i,a,j=500000;
int t=7000000;
int main(void){
    SIM-> SCGC5|=SIM_SCGC5_PORTA_MASK;
    SIM-> SCGC5|=SIM_SCGC5_PORTD_MASK;
    for(i=0; i<7;i++){
     PORTD->PCR[led[i]]|=(1<<8);
     PTD->PDDR|=(1<<led[i]);
    }
     PORTA->PCR[12]|=PORT_PCR_MUX(1)|PORT_PCR_IRQC(0b1101);
     NVIC_EnableIRQ(PORTA_IRQn);
     NVIC_SetPriority(PORTA_IRQn, 0b1101);
     PORTA->PCR[12]|=(1<<8)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;

    while(1){
        for(i=0;i<7;i++){
            PTD->PSOR|=(1<<led[i]);
            for(i=7000000;i>0;i--);
            PTD->PCOR|=(1<<led[i]);
        }
       if((PTD->PDIR&(1<<led[3]))==1){
        for(i=0;i<7;i++){
            PTD->PCOR|=(1<<led[i]);
            a=1;
        }
       }else{
        for(i=0;i<7;i++){
            PTD->PSOR|=(1<<led[i]);
            for(i=7000000;i>0;i--);
            PTD->PCOR|=(1<<led[i]);
            a=0;
       }
        }
        
        }
    }
void PORTA_IRQhander(void){
    if(PORTA -> ISFR & (1<<12)){
       PORTA -> ISFR |= (1<<12);
       if(a==1){
        t=t-j;
       for(i=t;i>0;i--);
       }else if(a==0){
        t=7000000;
        i=t;
       }
    }

  }
