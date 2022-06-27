#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t SDA = 4;
static const uint8_t SCL = 15;

static const uint8_t SS   = 21;
static const uint8_t MOSI = 5;
static const uint8_t MISO = 18;
static const uint8_t SCK  = 19;

static const uint8_t D0  = 23;
static const uint8_t D1  = 22;
static const uint8_t D2  = 1;
static const uint8_t D3  = 3;
static const uint8_t D4  = 21;
static const uint8_t D5  = 19;
static const uint8_t D6  = 18;
static const uint8_t D7  = 5;
static const uint8_t D8  = 0;
static const uint8_t D9  = 2;
static const uint8_t D10 = 4;
static const uint8_t D11 = 15;
static const uint8_t D12 = 13;
static const uint8_t D13 = 12;
static const uint8_t D14 = 14;
static const uint8_t D15 = 27;

static const uint8_t A0 = 36;
static const uint8_t A1 = 39;
static const uint8_t A2 = 34;
static const uint8_t A3 = 35;
static const uint8_t A4 = 32;
static const uint8_t A5 = 33;
// static const uint8_t A6 = 34;
// static const uint8_t A7 = 35;
// static const uint8_t A10 = 4;
// static const uint8_t A11 = 0;
// static const uint8_t A12 = 2;
// static const uint8_t A13 = 15;
// static const uint8_t A14 = 13;
// static const uint8_t A15 = 12;
// static const uint8_t A16 = 14;
// static const uint8_t A17 = 27;
// static const uint8_t A18 = 25;
// static const uint8_t A19 = 26;

static const uint8_t T0 = 32;
static const uint8_t T1 = 33;
static const uint8_t T2 = 27;
static const uint8_t T3 = 14;
static const uint8_t T4 = 12;
static const uint8_t T5 = 13;
// static const uint8_t T6 = 14;
// static const uint8_t T7 = 27;
// static const uint8_t T8 = 33;
// static const uint8_t T9 = 32;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

static const uint8_t CAMSD = 33;
static const uint8_t CAMSC = 25;
static const uint8_t CAMD2 = 19;
static const uint8_t CAMD3 = 22;
static const uint8_t CAMD4 = 23;
static const uint8_t CAMD5 = 21;
static const uint8_t CAMD6 = 18;
static const uint8_t CAMD7 = 26;
static const uint8_t CAMD8 = 35;
static const uint8_t CAMD9 = 34;
static const uint8_t CAMPC = 5;
static const uint8_t CAMXC = 32;
static const uint8_t CAMH  = 39;
static const uint8_t CAMV  = 36;

static const uint8_t LEDR 		 = 3;
static const uint8_t LEDG 		 = 1;
static const uint8_t LEDB 		 = 4;
static const uint8_t BUILTIN_KEY = 0;
static const uint8_t GPKEY		 = 0;

static const uint8_t PWM0 = 23;
static const uint8_t PWM1 = 22;

static const uint8_t MICD = 12;
static const uint8_t MICC = 13;

static const uint8_t IMUSD = 4;
static const uint8_t IMUSC = 15;

#endif /* Pins_Arduino_h */
