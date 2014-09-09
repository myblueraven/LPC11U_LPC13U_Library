/**************************************************************************/
/*!
    @file     projectconfig.h
    @author   K. Townsend (microBuilder.eu)

    @brief    Indicates which board should be used during the build process
    @ingroup  Board/HW Abstration Layer

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2012, 2013 K. Townsend
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
#ifndef _LIBCONFIG_H_
#define _LIBCONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================
    ABOUT THIS FILE
    -----------------------------------------------------------------------
    This file contains settings for entire project.
   ========================================================================*/

#include "sysdefs.h"
#include "errorslib.h"
#include "asserts.h"
#include "binary.h"
#include "localisation/localisation.h"

/*=========================================================================
    CODE BASE VERSION SETTINGS

    Please do not modify this version number.  To set a version number
    for your project or firmware, change the values in your 'boards/'
    config file.
    -----------------------------------------------------------------------*/
    #define CFG_LIB_CODEBASE_VERSION_MAJOR      (0)
    #define CFG_LIB_CODEBASE_VERSION_MINOR      (9)
    #define CFG_LIB_CODEBASE_VERSION_REVISION   (4)
/*=========================================================================*/

/*=========================================================================
    MCU SELECTION

    Include one of the following definitions depending on if you are
    using the LPC11U37 or LPC1347.  They're generally interchangeable, but
    the LPC11Uxx and LPC13xx CMSIS implementations have some differences
    in naming convention, and occasionally a feature is only available on
    the M3 (DWT for example).  Selecting the appropriate MCU allows
    the right code to be included when differences between the CMSIS
    implementations are present.

    -----------------------------------------------------------------------*/
    // #define CFG_LIB_MCU_LPC11U24FBD48_401
    // #define CFG_LIB_MCU_LPC11U37FBD48_401
    #define CFG_LIB_MCU_LPC1347FBD48
    // #define CFG_LIB_MCU_LPC1347FHN33

    /* Basic error checking */
    #if !defined CFG_LIB_MCU_LPC1347FBD48 && \
        !defined CFG_LIB_MCU_LPC11U37FBD48_401 && \
        !defined CFG_LIB_MCU_LPC11U24FBD48_401 && \
        !defined CFG_LIB_MCU_LPC1347FHN33
      #error "An MCU must be selected in projectconfig.h (Ex. CFG_LIB_MCU_LPC11U37FBD48_401, CFG_LIB_MCU_LPC1347FBD48, etc.)"
    #endif

    /* Set flag to indicate which CMSIS library to use */
    #if (defined CFG_LIB_MCU_LPC1347FBD48 || defined CFG_LIB_MCU_LPC1347FHN33)
      #define CFG_LIB_MCU_FAMILY_LPC13UXX
    #elif (defined CFG_LIB_MCU_LPC11U24FBD48_401 || defined CFG_LIB_MCU_LPC11U37FBD48_401)
      #define CFG_LIB_MCU_FAMILY_LPC11UXX
    #endif

    /* Include the correct MCU header file */
    #if defined CFG_LIB_MCU_FAMILY_LPC13UXX
      #include "LPC13Uxx.h"
    #endif
    #if defined CFG_LIB_MCU_FAMILY_LPC11UXX
      #include "LPC11Uxx.h"
    #endif
/*=========================================================================*/

/*=========================================================================
    EEPROM
    -----------------------------------------------------------------------
    EEPROM is used to persist certain user modifiable values to make
    sure that these changes remain in effect after a reset or hard
    power-down.  The addresses in EEPROM for these various system
    settings/values are defined below.  The first 256 bytes of EEPROM
    are reserved for this (0x0000..0x00FF).

    CFG_LIB_EEPROM_SIZE           The number of bytes available on the EEPROM
    CFG_LIB_EEPROM_RESERVED       The last byte of reserved EEPROM memory

          EEPROM Address (0x0000..0x00FF)
          ===============================
          0 1 2 3 4 5 6 7 8 9 A B C D E F
    000x  . . . . . . . . . . . . . . . .   Reserved
    001x  . . . . . . . . . . . . . . . .
    002x  . . . . . . . . . . . . . . . .
    003x  . . . . . . . . . . . . . . . .
    004x  . . . . . . . . . . . . . . . .
    005x  . . . . . . . . . . . . . . . .
    006x  . . . . . . . . . . . . . . . .
    007x  . . . . . . . . . . . . . . . .
    008x  . . . . . . . . . . . . . . . .
    009x  . . . . . . . . . . . . . . . .
    00Ax  . . . . . . . . . . . . . . . .
    00Bx  . . . . . . . . . . . . . . . .
    00Cx  . . . . . . . . . . . . . . . .
    00Dx  . . . . . . . . . . . . . . . .
    00Ex  . . . . . . . . . . . . . . . .
    00Fx  . . . . . . . . . . . . . . . .

    -----------------------------------------------------------------------*/
    #define CFG_LIB_EEPROM_SIZE                   (4032)
    #define CFG_LIB_EEPROM_RESERVED               (0x00FF)              // Protect first 256 bytes of memory
/*=========================================================================*/

/*=========================================================================
    ADC
    -----------------------------------------------------------------------

    CFG_LIB_ADC_MODE_LOWPOWER     If set to 1, this will configure the ADC
                              for low-power operation (LPC1347 only)
    CFG_LIB_ADC_MODE_10BIT        If set to 1, this will configure the ADC
                              for 10-bit mode (LPC1347 only)

    -----------------------------------------------------------------------*/
    #define CFG_LIB_ADC_MODE_LOWPOWER       (0)
    #define CFG_LIB_ADC_MODE_10BIT          (0)
/*=========================================================================*/


/*=========================================================================
    UART
    -----------------------------------------------------------------------

    CFG_LIB_UART_BAUDRATE         The default UART speed.  This value is used
                              when initialising UART, and should be a
                              standard value like 57600, 9600, etc.
                              NOTE: This value may be overridden if
                              another value is stored in EEPROM!
    CFG_LIB_UART_BUFSIZE          The length in bytes of the UART RX FIFO. This
                              will determine the maximum number of received
                              characters to store in memory.

    -----------------------------------------------------------------------*/
    #define CFG_LIB_UART_BAUDRATE           (115200)
    #define CFG_LIB_UART_BUFSIZE            (256)
/*=========================================================================*/


/*=========================================================================
    SPI
    -----------------------------------------------------------------------

    CFG_LIB_SSP_SCK0_LOCATION     The location of the SCK pin for SSP0
    CFG_LIB_SSP_MISO1_LOCATION    The location of the MISO1 pin for SSP1
    CFG_LIB_SSP_MOSI1_LOCATION    The location of the MOSI1 pin for SSP1
    CFG_LIB_SSP_SCK1_LOCATION     The location of the SCK pin for SSP1

    -----------------------------------------------------------------------*/
/*
    #define CFG_LIB_SSP_SCK0_0_6            (6)     // Used by USBConnect
    #define CFG_LIB_SSP_SCK0_0_10           (10)    // Used by SWD
    #define CFG_LIB_SSP_SCK0_1_29           (29)

    #define CFG_LIB_SSP_MISO1_0_22          (22)
    #define CFG_LIB_SSP_MISO1_1_21          (21)
    #define CFG_LIB_SSP_MOSI1_0_21          (21)
    #define CFG_LIB_SSP_MOSI1_1_22          (22)
    #define CFG_LIB_SSP_SCK1_1_15           (15)
    #define CFG_LIB_SSP_SCK1_1_20           (20)

    // Select the appropriate pin locations here
    #define CFG_LIB_SSP_SCK0_LOCATION       (CFG_LIB_SSP_SCK0_1_29)
    #define CFG_LIB_SSP_MISO1_LOCATION      (CFG_LIB_SSP_MISO1_1_21)
    #define CFG_LIB_SSP_MOSI1_LOCATION      (CFG_LIB_SSP_MOSI1_1_22)
    #define CFG_LIB_SSP_SCK1_LOCATION       (CFG_LIB_SSP_SCK1_1_20)

    // Set the phase and polarity for SSP0 and SSP1
    #define CFG_LIB_SSP_CPOL0               (0)
    #define CFG_LIB_SSP_CPHA0               (1)   // CC3000 = Mode 1
    #define CFG_LIB_SSP_CPOL1               (0)
    #define CFG_LIB_SSP_CPHA1               (0)
*/
/*=========================================================================*/


/*=========================================================================
    PRINTF REDIRECTION
    -----------------------------------------------------------------------

    CFG_LIB_PRINTF_MAXSTRINGSIZE  Maximum size of string buffer for printf
    CFG_LIB_PRINTF_UART           Will cause all printf statements to be
                              redirected to UART
    CFG_LIB_PRINTF_USBCDC         Will cause all printf statements to be
                              redirect to USB Serial
    CFG_LIB_PRINTF_CONVERT_NEWLINE_*
                                  Translates "\n" into "\r\n" before sending
                              to output on UART or USBCDC

    Note: If no printf redirection definitions are present, all printf
    output will be ignored.
    -----------------------------------------------------------------------*/
    #define CFG_LIB_PRINTF_MAXSTRINGSIZE    (255)

//     #define CFG_LIB_PRINTF_UART
    #define CFG_LIB_PRINTF_USBCDC
    // #define CFG_LIB_PRINTF_DEBUG

    #define CFG_LIB_PRINTF_CONVERT_NEWLINE_USBCDC
    #define CFG_LIB_PRINTF_CONVERT_NEWLINE_UART
/*=========================================================================*/

/*=========================================================================
    USB

    CFG_LIB_USB_STRING_MANUFACTURER Manufacturer name that will appear in the
                                device descriptor during USB enumeration
    CFG_LIB_USB_STRING_PRODUCT      Product name that will appear in the
                                device descriptor during USB enumeration
    CFG_LIB_USB_VENDORID            16-bit USB vendor ID
    USB_PRODUCT_ID              Define this to set a custom product ID
                                if you do not wish to use the 'auto'
                                product ID feature

    CFG_LIB_CDC                     Enable USB CDC support
    CFG_LIB_USB_HID_KEYBOARD        Enable USB HID keyboard emulation
    CFG_LIB_USB_HID_MOUSE           Enable USB HID mouse emulation for a five
                                button 'Windows' mouse with scroll wheels
    CFG_LIB_USB_HID_GENERIC         Enable USB HID Generic support for custom
                                in and out reports, with report size set
                                via CFG_LIB_USB_HID_GENERIC_REPORT_SIZE
    CFG_LIB_USB_MSC                 Enable USB Mass Storage support, pointing
                                to the SD card reader (requires mmc.c from
                                the FATFS drivers, but doesn't use FATFS)


    You can combine more than one USB class below and they will be
    automatically combined in a USB composite device within the limit of
    available USB endpoints.  The USB Product ID is calculated automatically
    based on the combination of classes defined below.

    NOTE: Windows requires the .inf file in '/core/usb' for CDC support
    -----------------------------------------------------------------------*/
	#define CFG_LIB_ENABLE_USB

    #ifdef CFG_LIB_ENABLE_USB
      #define CFG_LIB_USB_STRING_MANUFACTURER       "ravendyne.com"
      #define CFG_LIB_USB_STRING_PRODUCT            "Servo Master - Ichi"
      #define CFG_LIB_USB_VENDORID                  (0x1FC9)

      #define CFG_LIB_USB_CDC
//      #define CFG_LIB_USB_MSC
       #define CFG_LIB_USB_CUSTOM_CLASS

      #define CFG_LIB_USB_HID_KEYBOARD
//      #define CFG_LIB_USB_HID_MOUSE
//      #define CFG_LIB_USB_HID_GENERIC
//      #define CFG_LIB_USB_HID_GENERIC_REPORT_SIZE (64)

      #if (defined(CFG_LIB_USB_CDC)       || defined(CFG_LIB_USB_HID_KEYBOARD) || \
           defined(CFG_LIB_USB_HID_MOUSE) || defined(CFG_LIB_USB_HID_GENERIC)  || \
           defined(CFG_LIB_USB_MSC)       || defined(CFG_LIB_USB_CUSTOM_CLASS))
        #define CFG_LIB_USB
        #if defined(CFG_LIB_USB_HID_KEYBOARD) || defined(CFG_LIB_USB_HID_MOUSE) || defined(CFG_LIB_USB_HID_GENERIC)
          #define CFG_LIB_USB_HID
          #if defined(CFG_LIB_USB_HID_GENERIC) && (CFG_LIB_USB_HID_GENERIC_REPORT_SIZE > 64)
            #error "CFG_LIB_USB_HID_GENERIC_REPORT_SIZE exceeds the maximum value of 64 bytes (based on USB specs 2.0 for 'Full Speed Interrupt Endpoint Size')"
          #endif
        #endif
      #endif
    #endif
/*=========================================================================*/


/*=========================================================================
    CONFIG FILE VALIDATION

    Basic error checking to make sure that incompatible defines are not
    enabled at the same time, etc.

    -----------------------------------------------------------------------*/
    #if defined(CFG_LIB_PRINTF_USBCDC) && !defined(CFG_LIB_USB_CDC)
      #error "CFG_LIB_USB_CDC must be defined with CFG_LIB_PRINTF_USBCDC"
    #endif

    #if defined(CFG_LIB_USB_MSC) && !defined(CFG_LIB_SDCARD)
      #error "CFG_LIB_USB_MSC must be defined with CFG_LIB_SDCARD"
    #endif

    #if defined(CFG_LIB_PROTOCOL)
      #if defined(CFG_LIB_PROTOCOL_VIA_HID) && !defined(CFG_LIB_USB_HID_GENERIC)
        #error "CFG_LIB_PROTOCOL_VIA_HID requires CFG_LIB_USB_HID_GENERIC"
      #endif

      #if defined(CFG_LIB_PROTOCOL_VIA_BULK) && !defined(CFG_LIB_USB_CUSTOM_CLASS)
        #error "CFG_LIB_PROTOCOL_VIA_BULK requires CFG_LIB_USB_CUSTOM_CLASS to be defined"
      #endif
    #endif
/*=========================================================================*/

#ifdef __cplusplus
}
#endif

#endif
