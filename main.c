#include <xc.h>
#include "main.h"

pos_t state;

unsigned char key;

void init_config(void) {
    init_clcd();
    init_i2c();
    init_ds1307();
    init_adc();
    init_uart();
    init_matrix_keypad();
    //init_EEPROM();

}

void main(void) {
    init_config();

    while (1) {

        key = read_matrix_keypad(STATE_CHANGE);
        switch (state) {
            case dashboard:

                view_dashboard();
                break;

            case main_menu:
                view_menu();
                break;

            case viewlog:
                view_log();
                break;
                
            case downloadlog:
                download_log();
                break;
                
            case clearlog:
                clear_log();
                break;

            case setlog:
                set_log();
                break;

        }
    }

}