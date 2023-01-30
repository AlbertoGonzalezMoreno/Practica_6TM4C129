#include "lib/include.h"
uint16_t Result[2];
uint16_t duty[2];
void Hilo_1(void)
{
    GPION->DATA = (1<<1) | (0<<0);
    GPIOF_AHB->DATA = (0<<4) | (0<<0);
            SysTick_1ms(50000);
                    SysTick_1ms(50000);
                            SysTick_1ms(50000);
                                    SysTick_1ms(50000);
                                            SysTick_1ms(50000);
                     GPIOF_AHB->DATA = (0<<4) | (0<<0);
                 GPION->DATA = (0<<1) | (0<<0);
}

int main(void)
{

    Configurar_PLL();  //Confiuracion de velocidad de reloj 20MHZ
    Configurar_GPIO();
    Configura_Reg_ADC0();
    Configurar_UART0();
    Configura_Reg_PWM1(50);//Configuro a 1khz el pwm
    Configurar_Timer0A(&Hilo_1,4);
    while(1)
    {
        
    }

}
