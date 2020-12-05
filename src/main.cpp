//
// Created by cpigg on 12/4/2020.
//

#include <Arduino.h>
#include <HardwareSerial.h>
#include "../include/main.h"


error_t
ObsCallback( struct mbuf *mbuf, uint8_t * data ) {
    return ERR_OK;
}

error_t
crarduino( struct coap_msg_ctx *req, struct coap_msg_ctx *rsp )
{
    return ERR_OK;
}




void setup() {

    HardwareSerial *port = (HardwareSerial *) &Serial;
    // Set-up serial port for logging output
    // Print debug messages to the Serial Monitor
    // The pointer to the serial object is defined in mshield.h
    // NOTE: it takes a few seconds before you can start printing
//    log_init( SER_MON_PTR, SER_MON_BAUD_RATE, LOG_LEVEL );

    // Init the clock and set the local time zone
    rtc_time_init(LOCAL_TIME_ZONE);

    // Log Banner: version number, time and date
    char ver[64];
    strcpy(ver, COAP_SERVER_VERSION_STRING);
    strcat(ver, COAP_SERVER_VERSION_NUMBER);
    println(ver);
    sprintf(ver, "Build Time: %s  Date: %s", __TIME__, __DATE__);
    println(ver);
    println("");

    // Init the temp sensor
//    arduino_temp_sensor_init();

    // Init the CoAP Server
    coap_s_init( port,
            COAP_MSG_MAX_AGE_IN_SECS,
            UART_TIMEOUT_IN_MS, MAX_HDLC_INFO_LEN,
            "CHRIS'S SENSOR",
            ObsCallback );

    int freeram = free_ram();
    dlog(LOG_DEBUG, "Free Ram: %d", freeram);

    // Send the reboot event to the mnic
    coap_put_ic_reboot_event();
    delay(50);
}


void loop() {

}