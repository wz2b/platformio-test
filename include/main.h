//
// Created by cepasp@rit.edu on 12/4/2020.
//

/*
Copyright (c) Silver Spring Networks, Inc.
All rights reserved.
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the ""Software""), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
Except as contained in this notice, the name of Silver Spring Networks, Inc.
shall not be used in advertising or otherwise to promote the sale, use or other
dealings in this Software without prior written authorization from Silver Spring
Networks, Inc.
*/


#ifndef SUNSPEC_MILLI_MAIN_H
#define SUNSPEC_MILLI_MAIN_H


#include "ssni_coap_server/coap_server.h"
#include "ssni_coap_server/coappdu.h"
#include "ssni_coap_server/coapmsg.h"
#include "ssni_coap_server/coapsensoruri.h"
#include "ssni_coap_server/coap_rbt_msg.h"
//#include "temp_sensor.h"
#include "ssni_coap_server/log.h"
#include "ssni_coap_server/arduino_time.h"



//////////////////////////////////////////////////////////////////////////
//
// CoAP Observe Max-Age, see Section 5.10.5 of rfc7252. Default of 90s.
//
//////////////////////////////////////////////////////////////////////////
#define COAP_MSG_MAX_AGE_IN_SECS		90


//////////////////////////////////////////////////////////////////////////
//
// Specify the Serial USB to use for logging and debugging
// Specify the Serial UART to use for HDLC Tx and Rx
//
//////////////////////////////////////////////////////////////////////////

// For Boards that use a Atmel SAMD chip but are not the ADAFRUIT_METRO_M0_EXPRESS board
#ifndef ADAFRUIT_METRO_M0_EXPRESS
// For Boards that use other Atmel SAMD chip family

#endif

// For the Adafruit Metro M0 Express (uses the SAMD chip family).
#if defined(ADAFRUIT_METRO_M0_EXPRESS)
#define SER_MON_PTR				    &Serial
	#define UART_PTR				    &Serial1
#endif


//////////////////////////////////////////////////////////////////////////
//
// Specify the baud rate for the Serial USB
//
//////////////////////////////////////////////////////////////////////////
#define SER_MON_BAUD_RATE     			115200


//////////////////////////////////////////////////////////////////////////
//
// Set the logging level (see log.h)
// Typically you will set this to LOG_INFO or LOG_DEBUG
//
//////////////////////////////////////////////////////////////////////////
#define LOG_LEVEL						LOG_DEBUG


//////////////////////////////////////////////////////////////////////////
//
// Set the UART time-out (the serial link between Arduino and MilliShield)
// Values is in milliseconds
//
//////////////////////////////////////////////////////////////////////////
#define UART_TIMEOUT_IN_MS				2000


//////////////////////////////////////////////////////////////////////////
//
// The largest HDLC payload size. Maximum payload length in the MilliShield is 255
//
//////////////////////////////////////////////////////////////////////////
#define MAX_HDLC_INFO_LEN				(255)

//////////////////////////////////////////////////////////////////////////
//
// Local time zone relative to UTC
// Examples: Pacific: -8, Eastern: -5, London: 0, Paris: +1, Sydney: +10
//
//////////////////////////////////////////////////////////////////////////
#define LOCAL_TIME_ZONE					(-8)


#endif //SUNSPEC_MILLI_MAIN_H
