#include <stdbool.h> // booleans, i.e. true and false
#include <stdio.h>   // sprintf() function
#include <stdlib.h>  // srand() and random() functions
#include <time.h>

#include "functions.h" 
 
void blink_morse (int morse_rand_1[10])
{

    //It will flash for 0.5s or 1s to represent short or long code. 
    //There will be a 0.1s pause between each character of the codes, and a 1s pause between the two integers. 

    while(true){

        //It will flash for 0.5s or 1s to represent short or long code. 
        //There will be a 0.1s pause between each character of the codes, and a 1s pause between the two integers.

        int k = 0;

        for (int i=0;i<10;i++)
        {
            uint32_t now = HAL_GetTick();

            if (morse_rand_1[i] == 0){

                if((now > 2000+ k + 2000*i ) && (now < 2500 + k + 2000*i)){

                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, true);
                                     
                }else{

                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, false);
                    
                }
                k += 500;

            }else{

                if((now > 2000+ k + 2000*i) && (now < 4000 + k + 2000*i)){

                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, true);
                    
                }else{

                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, false);
                    
                }
                k += 2000;
            }
            
        }
    }
}

double rand_num(){

    int v1, v2;
    srand (time(NULL));
    v1 = rand() % 10;   //get first random number
    v2 = rand() % 10;   //get second random number

    double answer = v1 + v2*10; //convert two numbers into a two digit number

    return answer;
}

int* rand_to_morse (int num1, int num2)
{
    int morse_rand_1[5];
    int morse_rand_2[5];

    static int result[10];

    if (num1 >= 1 && num1 <= 5)   //morse code of rand number 1 in range 1-5
    {
      for(int j=0;j<5;j++)
      {
        morse_rand_1[j]=1;
      }

      for (int i = 0; i < num1; i++)
      {
          morse_rand_1[i] = 0;
      }
    }
    else if (num1 >= 6 && num1 <= 9)  //morse code of rand number 1 in range 6-9
    {
      for(int j=0;j<5;j++)
      {
        morse_rand_1[j]=0;
      }

      for (int i = 0; i < num1-5; i++)
      {
          morse_rand_1[i] = 1;
      }
    }
    else if (num1 == 0)    //morse code of rand number 1 when 0
    {
      for(int j=0;j<5;j++)
      {
        morse_rand_1[j]=1;
      }
    }

    if (num2 >= 1 && num2 <= 5)   //morse code of rand number 2 in range 1-5
    {   
      for(int j=0;j<5;j++)
      {
        morse_rand_2[j]=1;
      }

      for (int i = 0; i < num2; i++)
      {
        morse_rand_2[i] = 0;
      }
    }
    else if (num2 >= 6 && num2 <= 9)  //morse code of rand number 2 in range 6-9
    {
      for(int j=0;j<5;j++)
      {
        morse_rand_2[j]=0;
      }
        
      for (int i = 0; i < num2-5; i++)
      {
        morse_rand_2[i] = 1;
      }
    }
    else if (num2 == 0)    //morse code of rand number 2 when 0
    {
      for(int j=0;j<5;j++)
      {
        morse_rand_2[j]=1;
      }
    }

    for (int i=0;i<5;i++)
    {
      result[i] = morse_rand_1[i];
      result[i+5] = morse_rand_2[i];
    }

    return result;
}

double time_press()
{
    double t1 = 0;
    double t2 = 0;

    double tp =0;

        while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){

            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, false);
            
        }

        int i = 0;

        while(!(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))){

            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, true);

            if(i == 0){

                t1 = HAL_GetTick();

            }

            i++;
        }

        t2 = HAL_GetTick();

        tp = t2 - t1;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, false);


    return tp;

}
