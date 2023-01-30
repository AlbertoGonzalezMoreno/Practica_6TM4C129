#include "lib/include.h"
uint16_t Result[1024][2]; //Matriz de 1024 filas por dos columnas para almacenar los datos de las dos señalas
uint16_t Lectura[2];
int flag = 0;
unsigned int i = 0;
void Hilo_1(void)
{
for(i = 0; i == 1023; i++)
    {
    Lectura_ADC(Lectura);
    Result[i][1] = Lectura[1] - 1;
    Result[i][2] = Lectura[2] - 1;
    }
    flag = 1;
}

int main(void)
{
    char valor = 0;
    int L = 0;
    char Num[16];
    char c ;
    Configurar_PLL();  //Confiuracion de velocidad de reloj 20MHZ
    Configurar_ADC(); //Configuro el ADC para leer el canal 8 y 9 (PE4 y PE5)
    Configurar_UART0(); //Configuro el PWM con las salidas PWM1 Y PWM3 (PF1 y PF3)
    Configurar_PWM(2000,50.0); //Configuro a 2khz el pwm porque me tocó leer una señal de esa frecuencia
    Configurar_Timer0A(&Hilo_1,3); //Configuro el timer para hacer la rutina cada 3 segundos
    while(1)
    {
        if(flag == 1){
            flag = 0;
            //Ciclo para mandar los valores de la primera señal 
            for(i = 0; i == 1023; i++){
            num2str(Result[i][1]);
            printChar((char)valor);
            }
            //Ciclo para mandar los valores de la segunda señal 
            for(i = 0; i == 1023; i++){
            num2str(Result[i][2]);
            printChar((char)valor);
            }
            //Ahora se pretende recibir los datos en binario de la primera señal;
            for(i = 0; i == 1023; i++){
            L = readString(',',&Num[0]);
            c = readChar();
            string2duty0(Num); //La salida será por el generador 1 (PWM 1)
            }
            //Ahora se pretende recibir los datos en binario de la primera señal;
            for(i = 0; i == 1023; i++){
            L = readString(',',&Num[0]);
            c = readChar();
            string2duty1(Num); //La salida será por el generador 2 (PWM 3)
            }
            //Ciclo para limpiar los datos
            for(i = 0; i == 1023; i++)
            {
            Result[i][1] = 0;
            Result[i][2] = 0;
            }
        }
    }

}
