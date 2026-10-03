# O RP2040 usa o PIO para a comunicacao serial de um fio entre as metades.
SERIAL_DRIVER = vendor

# O RP2040 exige o driver WS2812 vendor; bitbang nao e suportado nesta plataforma.
WS2812_DRIVER = vendor

# OLED SSD1306 por I2C em P20/GP28 e P21/GP29. RGB Matrix e declarado no keyboard.json.
OLED_ENABLE = yes
