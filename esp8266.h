#ifndef ESP8266_H
#define	ESP8266_H

#ifdef	__cplusplus
extern "C" {
#endif
#define ESP8266_STATION 0x01
#define ESP8266_SOFTAP 0x02
#define ESP8266_AP_STATION 0x03
#define ESP8266_TCP 1
#define ESP8266_UDP 0
#define ESP8266_OK 1
#define ESP8266_READY 2
#define ESP8266_FAIL 3
#define ESP8266_NOCHANGE 4
#define ESP8266_LINKED 5
#define ESP8266_UNLINK 6


/*Prototypes fonctions*/
char esp8266_start();

#ifdef	__cplusplus
}
#endif

#endif	/* ESP8266_H */

