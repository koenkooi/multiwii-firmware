#ifndef SERIAL_H_
#define SERIAL_H_

#if defined(MEGA)
  #define UART_NUMBER 4
#elif defined(PROMICRO)
  #define UART_NUMBER 2
#else
  #define UART_NUMBER 1
#endif
#if defined(GPS_SERIAL) || defined(RC_TINY)
  #define RX_BUFFER_SIZE 256 // 256 RX buffer is needed for GPS communication (64 or 128 was too short)
#else
  #define RX_BUFFER_SIZE 64
#endif
#define TX_BUFFER_SIZE 128

#if defined(RC_TINY)
	#define MSP_SET_RAW_RC_TINY      150   //in message          4 rc chan
	#define MSP_ARM                  151
	#define MSP_DISARM               152
	#define MSP_TRIM_UP              153
	#define MSP_TRIM_DOWN            154
	#define MSP_TRIM_LEFT            155
	#define MSP_TRIM_RIGHT           156
#endif

void    SerialOpen(uint8_t port, uint32_t baud);
uint8_t SerialRead(uint8_t port);
void    SerialWrite(uint8_t port,uint8_t c);
uint8_t SerialAvailable(uint8_t port);
void    SerialEnd(uint8_t port);
uint8_t SerialPeek(uint8_t port);
bool    SerialTXfree(uint8_t port);
uint8_t SerialUsedTXBuff(uint8_t port);
void    SerialSerialize(uint8_t port,uint8_t a);
void    UartSendData(uint8_t port);

#endif /* SERIAL_H_ */
