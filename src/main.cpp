/*
 */
#include <Arduino.h>

// We're 
#define SEND_PWM_BY_TIMER
#include <IRremote.hpp>

// The first number, here 0000, denotes the type of the signal. 0000 denotes a raw IR signal with modulation.
// The second number, here 006C, denotes a frequency code. 006C corresponds to 1000000/(0x006c * 0.241246) = 38381 Hertz.
// The third and the forth number denote the number of pairs (= half the number of durations) in the start- and the repeat sequence respectively.
const char yamahaVolDown[] PROGMEM
= "0000 006C 0022 0002 015B 00AD " /* Pronto header + start bit */
        "0016 0016 0016 0041 0016 0016 0016 0041 0016 0041 0016 0041 0016 0041 0016 0016 " /* Lower address byte */
        "0016 0041 0016 0016 0016 0041 0016 0016 0016 0016 0016 0016 0016 0016 0016 0041 " /* Upper address byte (inverted at 8 bit mode) */
        "0016 0041 0016 0041 0016 0016 0016 0041 0016 0041 0016 0016 0016 0016 0016 0016 " /* command byte */
        "0016 0016 0016 0016 0016 0041 0016 0016 0016 0016 0016 0041 0016 0041 0016 0041 0016 05F7 " /* inverted command byte + stop bit */
        "015B 0057 0016 0E6C"; /* NEC repeat pattern*/
const char volDown[]
= "0000 006D 0000 0022 0156 00AC "
        "0015 0041 0015 0041 0015 0016 0015 0016 0015 0041 0015 0041 0015 0016 0015 0016 "
        "0015 0016 0015 0015 0015 0041 0015 0041 0015 0016 0015 0016 0015 0041 0015 0041 "
        "0015 0041 0015 0041 0015 0016 0015 0041 0015 0016 0015 0015 0015 0016 0015 0041 "
        "0015 0016 0015 0016 0015 0041 0015 0016 0015 0041 0015 0041 0015 0041 0015 0016 0015 0F7D";

IRsend irsend;

void setup() {
    Serial.begin(115200);
    while (!Serial); // Wait for serial

    IrSender.begin();
    //IrSender.begin(3, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
}

void loop() {
    delay(2000);

    // send Nec code acquired by IRreceiveDump.cpp
    Serial.println(F("Sending NEC from RAM: address 0xFF00, data 0x15"));
    irsend.sendPronto(volDown, 1);
}
