
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "esp_timer.h"

static void testForLoop() {
    printf("Start testing");
    int64_t start = esp_timer_get_time();
    for(int i = 0; i < 10000000; i++)
        asm volatile("");
    int64_t end = esp_timer_get_time();
    printf("test \"for loop\": %lld\n", (end - start) / 1000);
}

static void testWhileLoop() {
    int64_t start = esp_timer_get_time();
    uint32_t i = 0;
    while(i < 10000000) {
        i++;
        asm volatile("");
    }
    int64_t end = esp_timer_get_time();
    printf("test \"for loop\": %lld\n", (end - start) / 1000);
}

static void testGpio() {
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.pin_bit_mask = (uint64_t)1 << 2;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    gpio_config(&io_conf);

    while(1) {
        gpio_set_level(2, 1);
        gpio_set_level(2, 0);
        gpio_set_level(2, 1);
        gpio_set_level(2, 0);
        gpio_set_level(2, 1);
        gpio_set_level(2, 0);
        gpio_set_level(2, 1);
        gpio_set_level(2, 0);
    }
}

void app_main(void) {
    testForLoop();
    testWhileLoop();
    testGpio();
}
