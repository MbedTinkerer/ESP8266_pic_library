#include "esp8266.h"
#include "uart.h"


char esp8266_start()
{
    memset(reception,'\0',sizeof(reception)); //clear reception
    i=0;
    putsUSART("AT\r\n");
    Delay1Second();
    Delay1Second();
    return strcmp(reception,AT);  //O si true else false
}

char esp8266_restart()
{
    memset(reception,'\0',sizeof(reception)); //clear reception
    i=0;
    putsUSART("AT+RST\r\n");
    Delay1Second();
    Delay1Second();
    return strcmp(reception,AT_RST);  //O si true else false
}

char esp8266_GMR()
{
    unsigned char version[16];
    memset(reception,'\0',sizeof(reception)); //clear reception
    i=0;
    putsUSART("AT+GMR\r\n");
    Delay1Second();
    Delay1Second();
    int i,j=0;
    if(strlen(reception)>18)
    {    
        for(i=9;i<24;i++)
        {
        version[j]=reception[i];
        j++;
        }
        //Ensuite utiliser la varibale version si vous avez besoin
        //de récupérer cette information 
        return 0;  //ok
    }
    else { return 1;} //error
}

char esp8266_mode(unsigned char mode)
{
    memset(reception,'\0',sizeof(reception)); //clear reception
    i=0;
    switch (mode)
    {
        case 1 : //Station
        putsUSART("AT+CWMODE=1\r\n");
        Delay1Second();
        Delay1Second();
        if(strcmp(reception,AT_CWMODE1)==0){return 0;} //ok
        else if(strcmp(reception,AT_CWMODE12)==0){return 0;} //ok
        else return 1; //error
        
        case 2 : //SoftAP
        putsUSART("AT+CWMODE=2\r\n");
        Delay1Second();
        Delay1Second();
        if(strcmp(reception,AT_CWMODE2)==0){return 0;} //ok
        else if(strcmp(reception,AT_CWMODE22)==0){return 0;} //ok
        else return 1; //error
        
        case 3 : //AR+SoftAP
        putsUSART("AT+CWMODE=3\r\n");
        Delay1Second();
        Delay1Second();
        if(strcmp(reception,AT_CWMODE3)==0){return 0;} //ok
        else if(strcmp(reception,AT_CWMODE32)==0){return 0;} //ok
        else return 1; //error
        
        default: 
            return 1; //error
    }
}

char esp8266_connect(unsigned char* ssid, unsigned char* pass)
{
    memset(reception,'\0',sizeof(reception)); //clear reception
    i=0;
    putsUSART("AT+CWJAP=\"");   //Connexion to router
    putsUSART(ssid);
    putsUSART("\",\"");
    putsUSART(pass);
    putsUSART("\"\r\n");
    Delay1Second();
    Delay1Second();
    Delay1Second();
    Delay1Second();
    return 0;  //pas de gestion d'erreur pour cette fonction donc attention
}

void Delay1Second()
{
    int i=0;
    for(i=0;i<100;i++)
    {
         __delay_ms(10);
    }
}