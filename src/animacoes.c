#include "../includes/animacoes.h"
#include "../includes/led_matrix.h"
#include "pico/stdlib.h"

void animacao_espiral(PIO pio, uint sm) {
    double frames[5][25] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.2, 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.4, 0.4, 0.0, 0.0, 0.4, 0.0, 0.4, 0.0, 0.0, 0.4, 0.4, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.0, 0.0, 0.0, 0.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
    };

    for (int repeat = 0; repeat < 3; repeat++) {
        for (int frame = 0; frame < 5; frame++) {
            for (int i = 0; i < NUM_PIXELS; i++) {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, frames[frame][i]));
            }
            sleep_ms(200);
        }
    }
}

void animacao_coracao(PIO pio, uint sm){
     int frames[9][25] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0},
    };

    for (int i = 1; i <= 9 ; i++) {
        for (int j = 0; j < 25; j++) {
            pio_sm_put_blocking(pio, sm, matrix_rgb( 0.0, frames[i - 1][j], 0.0));  // Envia intensidade para o LED vermelho
        }
        sleep_ms(500); // Pausa de 0.5 segundos
    }
}

void animacao_cruz(PIO pio, uint sm) {
    double frames[5][25] = {
        // Frame 1
        {0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0,
         1.0, 1.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0},
        // Frame 2
        {0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0,
         1.0, 1.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0},
        // Frame 3
        {0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0,
         1.0, 1.0, 0.0, 1.0, 1.0,
         0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0},
        // Frame 4
        {0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0,
         1.0, 1.0, 0.0, 1.0, 1.0,
         0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0},
        // Frame 5
        {0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0,
         1.0, 1.0, 1.0, 1.0, 1.0,
         0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0}
    };

    for (int frame = 0; frame < 5; frame++) {  
        for (int i = 0; i < 25; i++) {  
            if (frames[frame][i] > 0.0) {
                pio_sm_put_blocking(pio, sm, matrix_rgb(frames[frame][i], 0.0, 0.0));  // Azul
            } else {
                pio_sm_put_blocking(pio, sm, 0x000000);  // Desliga o LED
            }
        }
        sleep_ms(300);  // Atraso entre os frames
    }
    limpar_todos_leds(pio, sm);  
}

void animacao_balada(PIO pio, uint sm) {
    int camadas[5][25] = {
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}, 
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Padrão de fora para dentro
    for (int camada = 0; camada < 5; camada++) {
        for (int i = 0; i < 25; i++) {
            if (camadas[camada][i]) {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 1.0, 1.0)); // Liga LED na cor amarela
            } else {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, 0.0)); // Desliga LED
            }
        }
        sleep_ms(200); // Espera 200 ms
    }

    // Pausa com o LED central aceso e apagando
    pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 1.0, 1.0)); // Acende o LED central (amarelo)
    sleep_ms(300);
    pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, 0.0)); // Apaga o LED central
    sleep_ms(300);

    // Padrão de dentro para fora
    for (int camada = 4; camada >= 0; camada--) {
        for (int i = 0; i < 25; i++) {
            if (camadas[camada][i]) {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 1.0, 1.0)); // Liga LED na cor amarela
            } else {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, 0.0)); // Desliga LED
            }
        }
        sleep_ms(200); // Espera 200 ms
    }
}

void animacao_emoji(PIO pio, uint sm) {
     int frames[6][25] = {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};

    for (int i = 1; i <= 6 ; i++) {
        for (int j = 0; j < 25; j++) {
            pio_sm_put_blocking(pio, sm, matrix_rgb( 0.0, frames[i - 1][j], frames[i - 1][j]));  // Amarelo
        }
        sleep_ms(500); // Pausa de 0.5 segundos
    }
}

void animacao_seta(PIO pio, uint sm) {
    double frames[5][25] = {
        // A seta gira 360 graus
        {0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 1.0, 1.0, 1.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0},

        {0.0, 0.0, 0.0, 0.0, 0.0, 
         0.0, 0.0, 0.0, 1.0, 0.0,
         1.0, 1.0, 1.0, 1.0, 1.0, 
         0.0, 0.0, 0.0, 1.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0},

        {0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 1.0, 1.0, 1.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0},

        {0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 1.0, 0.0, 0.0, 0.0, 
         1.0, 1.0, 1.0, 1.0, 1.0,
         0.0, 1.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0},

        {0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 1.0, 1.0, 1.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0, 
         0.0, 0.0, 1.0, 0.0, 0.0,
         0.0, 0.0, 1.0, 0.0, 0.0},
    };

    for (int repeat = 0; repeat < 2; repeat++) {
        for (int frame = 0; frame < 5; frame++) {
            for (int i = 0; i < NUM_PIXELS; i++) {
                pio_sm_put_blocking(pio, sm, matrix_rgb(0.0, 0.0, frames[frame][i]));
            }
            sleep_ms(1000); //espera 1 segundo
        }
    }
}


void animacao_darth_vader(PIO pio, uint sm) {
    // Frame representando a máscara do Darth Vader
    double frame[25] = {
        0.0, 1.0, 1.0, 1.0, 0.0,  // Linha 1
        1.0, 0.0, 1.0, 0.0, 1.0,  // Linha 2
        1.0, 1.0, 1.0, 1.0, 1.0,  // Linha 3
        0.0, 1.0, 0.0, 1.0, 0.0,  // Linha 4
        0.0, 1.0, 1.0, 1.0, 0.0   // Linha 5
    };


    // Exibindo a imagem
    for (int repeat = 0; repeat < 3; repeat++) {
        for (int i = NUM_PIXELS - 1; i >= 0; i--) {
            pio_sm_put_blocking(pio, sm, matrix_rgb(frame[i], 0.0, 0.0 )); // Cor vermelha para o Darth Vader
        }
    }
}