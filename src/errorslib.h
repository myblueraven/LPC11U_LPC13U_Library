/**************************************************************************/
/*!
    @defgroup Errors Error Handling

    @brief    System wide error codes and error-handling

    @details

    In order to improve the stability of the system the code base uses a
    global error type that any critical function returns upon completion.

    Functions that execute properly return ERROR_NONE, which equals '0' so
    that we can perform a simple check like 'if(error) { ... }'.
*/
/**************************************************************************/

/**************************************************************************/
/*!
    @file     errors.h
    @author   K. Townsend (microBuilder.eu)

    @ingroup  Errors

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, K. Townsend (microBuilder.eu)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef _ERRORS_LIB_H_
#define _ERRORS_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/*!
    Common error messages used across the system
*/
/**************************************************************************/
typedef unsigned int error_t;
  /*=======================================================================
    GENERIC ERRORS                                         0x0000 .. 0x00FF
    -----------------------------------------------------------------------
    These error codes can be used anywhere in the system
    -----------------------------------------------------------------------*/
#define ERROR_NONE                                  (0x0)  /**< Indicates no error occurred */
#define ERROR_OPERATIONTIMEDOUT                     (0x1)  /**< Operation timed out before completion */
#define ERROR_ADDRESSOUTOFRANGE                     (0x2)  /**< The supplied address is out of range */
#define ERROR_BUFFEROVERFLOW                        (0x3)  /**< The proposed action will cause a buffer overflow */
#define ERROR_INVALIDPARAMETER                      (0x4)  /**< An invalid parameter value was provided */
#define ERROR_DEVICENOTINITIALISED                  (0x5)  /**< Attempting to execute a function on an uninitialised peripheral */
#define ERROR_UNEXPECTEDVALUE                       (0x6)  /**< An unexpected value was found inside a function */
  /*=======================================================================*/


  /*=======================================================================
    I2C ERRORS                                             0x0100 .. 0x010F
    -----------------------------------------------------------------------
    Errors related to the I2C bus
    -----------------------------------------------------------------------*/
#define ERROR_I2C_DEVICENOTFOUND                    (0x101)  /**< Device didn't ACK after an I2C transfer */
#define ERROR_I2C_NOACK                             (0x102)  /**< No ACK signal received during an I2C transfer */
#define ERROR_I2C_TIMEOUT                           (0x103)  /**< Device timed out waiting for response (missing pullups?) */
  /*=======================================================================*/


  /*=======================================================================
    USB ERRORS                                             0x0200 .. 0x02FF
    -----------------------------------------------------------------------
    USB error codes
    TODO: Harmonise LPC codes with error IDs here!
    -----------------------------------------------------------------------*/

  /*=======================================================================*/

#ifdef __cplusplus
}
#endif

#endif
