#pragma once

/* Nesta primeira versao, o cabo USB deve ser ligado ao lado esquerdo. */
#define MASTER_LEFT

/* Detecta a presenca do USB no RP2040 e melhora a inicializacao do split. */
#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

/* Compartilha o estado necessario entre as duas metades. */
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

/* Mantem o estado de ligar/desligar dos OLEDs sincronizado entre as metades. */
#define SPLIT_OLED_ENABLE

/*
 * O OLED nao possui trilhas de dados ate o controlador nesta revisao da PCB.
 * Os fios devem ligar P20/GP28 -> SDA e P21/GP29 -> SCL em cada metade.
 * GP28/GP29 pertencem ao controlador I2C0 do RP2040 e estao disponiveis
 * nos furos comuns do controlador.
 */
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP28
#define I2C1_SCL_PIN GP29

/* Desliga o display apos 60 segundos sem atividade para reduzir burn-in. */
#define OLED_TIMEOUT 60000

/* Tempo de debounce conservador para os switches Choc. */
#define DEBOUNCE 5

/* Inicia em vermelho com brilho baixo; o Vial pode ajustar cor, efeito e brilho. */
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
