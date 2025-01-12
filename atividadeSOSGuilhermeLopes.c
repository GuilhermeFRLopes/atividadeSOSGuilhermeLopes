#include <stdio.h>
#include "pico/stdlib.h"

#define led_pin_green 11

void controleLed(int tempo){
    gpio_put(led_pin_green, true);      
    sleep_ms(tempo);
    gpio_put(led_pin_green, false);        
}

void acionarLetra(int tipo, bool gap){
    if (tipo == 0){
        controleLed(200);
    } 
    else if (tipo == 1){
        controleLed(800);
    }
    if (gap){
        sleep_ms(125);
    }
    else{
        sleep_ms(250);
    }
}

int main()
{
    stdio_init_all(); 

    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);

    while (true) {
        //(.)(.)(.)        
        acionarLetra(0,true);
        acionarLetra(0,true);
        acionarLetra(0,false);
        
        //(-)(-)(-) 
        acionarLetra(1,true);
        acionarLetra(1,true);
        acionarLetra(1,false);

        //(.)(.)(.) 
        acionarLetra(0,true);
        acionarLetra(0,true);
        acionarLetra(0,false);

        //ja esperou 250 ms dentro da funçao + 2750 pra completar os 3 segundos pra reiniciar
        sleep_ms(2750);

    }
}
