#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "./includes/keypad.h"
#include "./includes/buzzer.h"
#include "./includes/led_matrix.h"
#include "./includes/animacoes.h"
#include "./includes/marcha_imperial.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"
#include "pico/bootrom.h"

// Arquivo .pio
#include "pio_matrix.pio.h"

// Defines para utilização do UART

#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0
#define UART_RX_PIN 1

// Função principal
int main() {
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    uart_init(UART_ID, BAUD_RATE); // Funções para inicilizar UART
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART); 
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    stdio_init_all();  // Inicializa a comunicação serial (para debug)
    iniciar_keypad();     // Inicializa o teclado matricial
    pwm_init_buzzer(BUZZER);

    while (true)
    {
        printf("Digite um novo comando via UART:\n");

        char comando = getchar(); // Lê o comando do teclado via uart

        switch (comando)
        {
        case '1': animacao_espiral(pio, sm); limpar_todos_leds(pio, sm); break;  // Animação 1
        case '2': animacao_coracao(pio, sm); limpar_todos_leds(pio, sm); break;
        case '3': animacao_cruz(pio, sm); limpar_todos_leds(pio, sm); break; //Animação 3
        case '4': animacao_balada(pio, sm); limpar_todos_leds(pio, sm); break; //Animação 4
        case '5': animacao_emoji(pio,sm); limpar_todos_leds(pio, sm); break; //Animação 5
        case '6': animacao_seta(pio,sm); limpar_todos_leds(pio, sm); break; //Animação 6
        case '7': tocar_marcha_imperial(pio, sm); break;  //Animação 7
        case 'A': limpar_todos_leds(pio, sm); break;        // Desliga todos os LEDs
        case 'B': 
            acender_leds(pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(3000); //ligados por 3 segundos
            limpar_todos_leds(pio, sm); // apaga os leds
            break;  // Azul (100%)
        case 'C': 
            acender_leds(pio, sm, 0.8, 0.0, 0.0); // Vermelho (80%)
            sleep_ms(3000); //ligados por 3 segundos
            limpar_todos_leds(pio, sm); // apaga os leds
            break; 
        case 'D': 
            acender_leds(pio, sm, 0.0, 0.5, 0.0); //Verde (50%)
            sleep_ms(3000); //ligados por 3 segundos
            limpar_todos_leds(pio, sm); // apaga os leds
            break; 
        case '#': 
            acender_leds(pio, sm, 0.2, 0.2, 0.2);//Branco (20%)
            sleep_ms(3000); //ligados por 3 segundos
            limpar_todos_leds(pio, sm); // apaga os leds
            break; 
        case 'x': // reebot, sistema reiniciado e placa em modo bootloader
            printf("Reiniciando o sistema...\n");
            sleep_ms(300);        // atraso antes de reiniciar para garatir a impressao
            reset_usb_boot(0, 0); // entra em modo bootloader
            break;
        default:
            printf("Comando invalido:%c\n", comando);
            break;
        }
    }

    while (true) {
        char key = ler_keypad();  // Lê o teclado matricial
        if (key) {
            switch (key) {
                case '1': animacao_espiral(pio, sm); limpar_todos_leds(pio, sm); break;  // Animação 1
                case '2': animacao_coracao(pio, sm); limpar_todos_leds(pio, sm); break;
                case '3': animacao_cruz(pio, sm); limpar_todos_leds(pio, sm); break; //Animação 3
                case '4': animacao_balada(pio, sm); limpar_todos_leds(pio, sm); break; //Animação 4
                case '5': animacao_emoji(pio,sm); limpar_todos_leds(pio, sm); break; //Animação 5
                case '6': animacao_seta(pio,sm); limpar_todos_leds(pio, sm); break; //Animação 6
                case '7': tocar_marcha_imperial(pio, sm); break;  //Animação 7
                case 'A': limpar_todos_leds(pio, sm); break;        // Desliga todos os LEDs
                case 'B': 
                   acender_leds(pio, sm, 0.0, 0.0, 1.0);
                   sleep_ms(3000); //ligados por 3 segundos
                   limpar_todos_leds(pio, sm); // apaga os leds
                   break;  // Azul (100%)
                case 'C': 
                   acender_leds(pio, sm, 0.8, 0.0, 0.0); // Vermelho (80%)
                   sleep_ms(3000); //ligados por 3 segundos
                   limpar_todos_leds(pio, sm); // apaga os leds
                   break; 
                case 'D': 
                   acender_leds(pio, sm, 0.0, 0.5, 0.0); //Verde (50%)
                   sleep_ms(3000); //ligados por 3 segundos
                   limpar_todos_leds(pio, sm); // apaga os leds
                   break; 
                case '#': 
                   acender_leds(pio, sm, 0.2, 0.2, 0.2);//Branco (20%)
                   sleep_ms(3000); //ligados por 3 segundos
                   limpar_todos_leds(pio, sm); // apaga os leds
                   break; 
            }
            sleep_ms(200);  // Debounce
        }
    }
}