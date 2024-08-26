#ifndef _SOFTSPI_H
#define _SOFTSPI_H

# include <Arduino.h>
#include <SPI.h>

class SoftSPI : public SPIClass
{

public:
    SoftSPI(uint8_t mosi, uint8_t miso, uint8_t sck);
    void begin();
    void end();
    void setBitOrder(uint8_t);
    void setDataMode(uint8_t);
    void setClockDivider(uint32_t);
    uint8_t transfer(uint8_t);
    uint8_t transfer_in();
    void transfer_out(uint8_t);
    uint16_t transfer16(uint16_t data);
    void transfer(void *buf, size_t count);
    /* compatibility with Adafruit_nRF52_Arduino */
    void transfer(const void *tx_buf, void *rx_buf, size_t count);
    // Transaction Functions
    void beginTransaction(SPISettings settings);
    void endTransaction(void);
#if defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_ARCH_RENESAS) || \
    defined(ARDUINO_ARCH_SILABS)
    /* compatibility with Arduino RP2040 Core */
    void usingInterrupt(int interruptNumber);
    void notUsingInterrupt(int interruptNumber);
    void attachInterrupt();
    void detachInterrupt();
#endif /* RP2040 || RENESAS || SILABS */
private:
    uint8_t _miso;
    uint8_t _mosi;
    uint8_t _sck;
};

#endif
