
///BY Massinissa TAZEKRITT

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "Lib_Gpio.h"
#include "stm32f4xx_rng.h"

int tab[6];

void main()
	{
	SystemInit();
	uint16_t x,y;
	uint32_t number,cnumber;
    int i=0,j=0,nb=6, puissance=2,flag=0, on=1;

    LibGPIO_Conf(GPIOD, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3, GPIO_Mode_IN, GPIO_PuPd_UP, GPIO_Speed_2MHz);
    LibGPIO_Conf(GPIOE, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 , GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_2MHz);
    LibGPIO_Conf(GPIOF, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 , GPIO_Mode_OUT, GPIO_OType_PP, GPIO_Speed_2MHz);

    GLCD_InitDisplay();
    GLCD_ClearScreen();
    GLCD_Move(0,0,0);

    //premiere itteration pour eviter le cas du zero
    RNG_Cmd(ENABLE);
    number=RNG_GetRandomNumber();
    RNG_Cmd(DISABLE);


    while (1)
		{
        x= ~GPIO_ReadInputData(GPIOD);
        y=x & 0x000b;

        if(y==0x0002 && i<6)  ///Button2 pour Afficher 6 nombres successivement et differents
            {
            on=1;
            ///obtenir le  nombre
            RNG_Cmd(ENABLE);
            number=RNG_GetRandomNumber();
            RNG_Cmd(DISABLE);
            cnumber= number % 0x32;
            if(cnumber == 0) cnumber+= RNG_GetRandomNumber()% 0x32;

            /// Remplir le tableau
            tab[i]=cnumber;

            ///rechercher si le nombre est semblant aux nombres déja tiré
            if(i != 0) //pour sauter le cas ou en vient de tirer le premier nombre
            {
                for(j=0; j< i; j++)
                {
                    if(tab[j]==tab[i]) // cas ou on a trouver un nombre que on a deja tiré
                    {
                     i--; flag =1;
                    }
                }
            }
            if( flag == 1)
            {
                flag=0; on=0; // on=0 pour ne pas afficher dans le cas ou on a trouver un nombre excistant deja
            }

            ///Affichage du nombre
            if (on == 1)
            {
                GLCD_Move(0,i,0);
                GLCD_ShowInt(cnumber);
                Lib_delay(4000000);
                GPIO_Write(GPIOE, puissance-1);
                puissance= puissance*2;
                ///delay
                Lib_delay(300000);
            }
            i++;
            }

        if(y==0x0001) ///Button 1 pour reinitialiser
            {
            ///Effacer l'affichage et enteiner les led
            GLCD_ClearScreen();
            GPIO_Write(GPIOE, 0);
            i=0;
            puissance=2;
            Lib_delay(300000);
            }
        }
    }



