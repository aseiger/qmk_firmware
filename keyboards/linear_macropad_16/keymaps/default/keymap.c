// Copyright 2022 Alex Seiger (@Alex Seiger)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "virtser.h"

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
/*   rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST); */
}
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS
    )
};

#ifdef VIRTSER_ENABLE
/* listen on serial for commands. Either a set of lower case letters mapped to colors, 
/  or upper case letters that change RGB mode. 
/  special command C takes 3 numbers as arguments, terminated with a newline or comma or excess digits.
Command C takes 3-5octets of RGB settings. Numbers can be terminated with a comma or period. 
3 octets = set all LED, 4th argument specfies specfic LED, 4+5 specify start and stop LEDs.
*/ 

uint8_t ser_rgbByte[18] ; //ascii string 
uint8_t ser_cmd_started =0 ; // are we in process
uint8_t ser_got_RGBbytes =0 ; // how many bytes we've recived. 
uint8_t rgb_r[6]; // R, g, b, P1, p2
uint8_t bs=0; // how many bytes into our rgbBytestring.

void virtser_recv(uint8_t serIn) { 
#ifdef RGBLIGHT_ENABLE 
    if ((serIn == 10 ) || (serIn ==  13) || ser_got_RGBbytes >=5) { //reached newline or max digits

        if (ser_cmd_started) {
            ser_cmd_started =0 ; // end loop at newline
            virtser_send('|');

            if (ser_got_RGBbytes==3) {
                rgblight_setrgb( rgb_r[0], rgb_r[1], rgb_r[2]);
            }

            if (ser_got_RGBbytes ==4) {
                if (( rgb_r[3] >=0)  && (rgb_r[3] <= RGBLED_NUM) ) { // is pos1 plausible
                    rgblight_setrgb_at ( rgb_r[0], rgb_r[1], rgb_r[2], rgb_r[3]);
                } else {
                        rgblight_setrgb( rgb_r[0], rgb_r[1], rgb_r[2]);
                }
            }

            if (ser_got_RGBbytes == 5) { // are start and end positions plausible? 
                if ( (rgb_r[4] >0)  && (rgb_r[4] <= RGBLED_NUM) && (rgb_r[4] > rgb_r[3]) && 
                 (rgb_r[3] >=0)  && (rgb_r[3] <= (RGBLED_NUM -1))  ) {
                    rgblight_setrgb_range(rgb_r[0], rgb_r[1], rgb_r[2], rgb_r[3], rgb_r[4]);
               } else {
                   rgblight_setrgb( rgb_r[0], rgb_r[1], rgb_r[2]);
               }
            }
        } else { // newline outside of command loop, or something that can be ignored. 
          //virtser_send('.');
        }
    } 

    if (1 == ser_cmd_started) { // collecting bytes. 
        if  (   // it is time to compute a byte
          ( ( (serIn == ',') || (serIn == '.') ) && (bs > 0) ) || // signal done with the byte. 
            (bs ==2 )){ //or we know this is last.
        
            if ( (serIn <= '9') && (serIn >='0') ) { //3rd asci digit 
                ser_rgbByte[bs] = serIn;
                bs++;
            //  virtser_send(serIn);
            }

            if (bs>3) {
                rgb_r[ser_got_RGBbytes]=255;
                ser_got_RGBbytes ++;
            }
            if (bs==3) {
              rgb_r[ser_got_RGBbytes] = (ser_rgbByte[0] -'0')*100 + (ser_rgbByte[1] -'0')*10 + (ser_rgbByte[2] -'0' );
              ser_got_RGBbytes ++;
            }
            if (bs ==2 ) {
               rgb_r[ser_got_RGBbytes] = (ser_rgbByte[0] -'0')*10 +  (ser_rgbByte[1] -'0' );
               ser_got_RGBbytes ++;
            }
            if (bs ==1) {
               rgb_r[ser_got_RGBbytes] = (ser_rgbByte[0] -'0');
               ser_got_RGBbytes ++;
            }  // {else wipe & start over}

          bs=0;
    //  virtser_send(ser_got_RGBbytes+'0');

        } else { // haven't got enough for our byte / no terminal marker
            if ( (serIn <= '9') && (serIn >='0') ) { //ascii only 
                ser_rgbByte[bs] = serIn;
                bs++;
            //    virtser_send(serIn);
            }
        }
    } else { //not in command loop - next is command w/o arguments, or start of one. 
        switch (serIn) {
            case 'C': // color switch
                ser_cmd_started=1;
                ser_got_RGBbytes = bs =0;
                virtser_send('/');
                break;
        
            case 'r': //red
                rgblight_setrgb(RGB_RED);
                break;
         
            case 'g': 
                rgblight_setrgb(RGB_GREEN);
                break;
   
            case 'b':  // color switch
                rgblight_setrgb(RGB_BLUE);
                break;

            case 'w':  // color switch
                rgblight_setrgb(RGB_WHITE);
                break;

            case 'o':  // color black/off
                rgblight_setrgb(0,0,0);
                break;
               
            case 'T':  // toggle
                rgblight_toggle();
                break;
            
            case 'P': // pulse led
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
                break; 
            case 'S':  // Static
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                break;
           
            case 'U':  // Rainbow
                rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
                break;
                   
            default: 
           //     virtser_send(serIn);
                break;

        }
    }
#endif // RGBLIGHT_ENABLE
}

#endif // VirtSerial
