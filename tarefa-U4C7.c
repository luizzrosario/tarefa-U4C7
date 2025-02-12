// Incluindo bibliotecas necessárias
#include <stdio.h> 
#include "pico/stdlib.h"
#include "pico/time.h" 
#include "hardware/pwm.h" 

// Definição dos pinos e valores
#define SERVO_PIN 12      // Pino do Servo Motor (e LED RGB Azul) 
#define CLOCK_DIV 64.0    // Divisor de clock 
#define TPWM 20000.0      // Período de 20ms (50Hz)
#define WRAP_VALUE 39063  // Valor do contador do PWM

// Definição de variáveis
uint volatile slice_numero;

// Função para calcular o ciclo de trabalho
uint16_t calculate_duty_cycle(float T_ON){
    return (uint16_t)((T_ON / TPWM) * WRAP_VALUE);
}

// Função para movimentação do servo motor
void movimentacao(uint slice, float T_ON){
    uint16_t duty = calculate_duty_cycle(T_ON);
    pwm_set_gpio_level(SERVO_PIN, duty);       
}

// Função principal
int main(){
    stdio_init_all(); // Inicialização da comunicação serial
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Configuração do pino do servo motor
    slice_numero = pwm_gpio_to_slice_num(SERVO_PIN); // Define o slice do PWM
    pwm_set_clkdiv(slice_numero, CLOCK_DIV);    // Define o divisor de clock
    pwm_set_wrap(slice_numero, WRAP_VALUE);    // Define o valor de wrap
    pwm_set_enabled(slice_numero, true);       // Habilita o PWM


    // Primeira movimentação do servo motor (180 graus)
    printf("Movendo para 180 graus\n");
    movimentacao(slice_numero, 2400); 
    sleep_ms(5000);

    // Segunda movimentação do servo motor (90 graus)
    printf("Movendo para 90 graus\n");
    movimentacao(slice_numero, 1470);
    sleep_ms(5000);

    // Terceira movimentação do servo motor (0 graus)
    printf("Movendo para 0 graus\n");
    movimentacao(slice_numero, 500);
    sleep_ms(5000);

    // Loop principal
    while(1){
        printf("Inicio da Movimentação Suave\n");  
        for(float pulse = 500; pulse <= 2400; pulse += 5){  
            movimentacao(slice_numero, pulse);  
            sleep_ms(10);
        }

        printf("Retorno da Movimentação Suave\n");
        for(float pulse = 2400; pulse >= 500; pulse -= 5){
            movimentacao(slice_numero, pulse);
            sleep_ms(10);
        }
    }
}
