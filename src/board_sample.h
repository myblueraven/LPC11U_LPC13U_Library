/**************************************************************************/
/*!
    @file     board_lpcxpresso1347.h
    @author   K. Townsend (microBuilder.eu)

    @brief    Board file for the LPC1347 LPCXpresso board from NXP
    @ingroup  Boards

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2012 K. Townsend
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
#ifndef __BOARD_LPCXPRESSO1347_H__
#define __BOARD_LPCXPRESSO1347_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sysdefs.h"

//#include "firmware_version.h"

/*=========================================================================
    PIN USAGE
    -----------------------------------------------------------------------
    This table tries to give an indication of which GPIO pins and
    peripherals are used by the available drivers and SW examples.  Only
    dedicated GPIO pins available on the LPC1347 Reference Board are shown
    below.  Any unused peripheral blocks like I2C, SSP, ADC, etc., can
    also be used as GPIO if they are available.

                PORT 0
                =========================================================
                0 1 2 3 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23

    ST3775      . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    HX8340B     . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    HX8347G     . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    CHIBI       . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    SSD1306 I2C . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    FAT32/MMC   . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  X  .  .
    PN532 I2C   . . . . . . . .  .  .  .  .  .  .  X  X  .  .  .  .  .  .
    PCF2129A    . . . . . . . .  .  .  .  .  .  .  X  X  .  .  .  .  .  .

                PORT 1
                ===========================================================================
                0 1 2 3 4 5 7 8 10 11 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 31
                + + + + + + + +  +  +              +  +                                   -

    ST3775      . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  X  X  X  X  X  .  .
    HX8340B     . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  X  X  X  X  X  .
    HX8347G     . . . . . . . .  .  .  X  X  X  X  .  .  X  X  X  X  X  X  X  X  X  X  .  .
    CHIBI       . . . . . . . .  .  .  X  X  X  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    SSD1306 I2C . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    FAT32/MMC   . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  X  X  .  .  .  .  .  .
    PN532 I2C   . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
    PCF2129A    . . . . . . . .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .

                TIMERS                   SSP   ADC               UART
                ======================   ===   ===============   ====
                16B0  16B1  32B0  32B1   0 1   0 1 2 3 4 5 6 7   0

    HX8340B     .      .    .     .      . .   . . . . . . . .   .
    HX8347G     .      .    .     .      . .   . . . . . . . .   .
    CHIBI       .      .    .     .      X .   . . . . . . . .   .
    SSD1306 I2C .      .    .     .      . .   . . . . . . . .   .
    FAT32/MMC   .      .    .     .      . X   . . . . . . . .   .

    [+]   Only available on QFP64 package
    [-]   Only available on QFP48 package

  =========================================================================*/


/*=========================================================================
    GPIO INTERRUPTS
    -----------------------------------------------------------------------
    This table shows where GPIO interrupts are mapped in this project
    (Note that the LPC11U and LPC13U use different names for the
    IRQ Handlers in the standard headers)

    Interrupt                                     Location
    ------------------------------------------    -------------------------
    PIN_INT0_IRQHandler - FLEX_INT0_IRQHandler    chb_drvr.c
    PIN_INT1_IRQHandler - FLEX_INT1_IRQHandler    pcf2129.c
    PIN_INT2_IRQHandler - FLEX_INT2_IRQHandler    spi.c (cc3000)
    PIN_INT3_IRQHandler - FLEX_INT3_IRQHandler
    PIN_INT4_IRQHandler - FLEX_INT4_IRQHandler
    PIN_INT5_IRQHandler - FLEX_INT5_IRQHandler
    PIN_INT6_IRQHandler - FLEX_INT6_IRQHandler
    PIN_INT7_IRQHandler - FLEX_INT7_IRQHandler
    GINT0_IRQHandler
    GINT0_IRQHandler
    -----------------------------------------------------------------------*/
/*=========================================================================*/


/*=========================================================================
    SUPPORTED PERIPHERALS
    -----------------------------------------------------------------------
    Because all ISRs are referenced in the startup code, GCC typically
    won't optimise out the ISR functions during compilation even if the
    ISRs will never be entered, resulting in larger binaries than required
    (for example if no I2C sensors are used, be sure to disable I2C support
    since the I2C ISR is quite large).

    Use the defines below to include or exclude support for specific
    peripherals.

    NOTE: GPIO ISRs are handled separately in GPIO INTERRUPTS below
    -----------------------------------------------------------------------*/
//    #define CFG_LIB_ENABLE_I2C
    #define CFG_LIB_ENABLE_UART
    #define CFG_LIB_ENABLE_USB
//    #define CFG_LIB_ENABLE_TIMER32
/*=========================================================================*/


/*=========================================================================
    ENABLE Multi channel PWM

    -----------------------------------------------------------------------*/
    #define CFG_LIB_MCPWM

/*=========================================================================*/


/*=========================================================================
    EEPROM
    -----------------------------------------------------------------------
    EEPROM is used to persist certain user modifiable values to make
    sure that these changes remain in effect after a reset or hard
    power-down.  The addresses in EEPROM for these various system
    settings/values are defined below.  The first 256 bytes of EEPROM
    are reserved for system (0x0000..0x00FF).

    CFG_LIB_EEPROM_SIZE           The number of bytes available on the EEPROM
    CFG_LIB_EEPROM_RESERVED       The last byte of reserved EEPROM memory

          EEPROM Address (0x0000..0x00FF)
          ===============================
          0 1 2 3 4 5 6 7 8 9 A B C D E F
    000x  . . . . . . . . . . . . . . . .   Reserved
    001x  x x . . x x x x x x x x . . . .   Chibi
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
    #define CFG_LIB_EEPROM_CHIBI_NODEADDR         (uint16_t)(0x0010)    // 2
    #define CFG_LIB_EEPROM_CHIBI_IEEEADDR         (uint16_t)(0x0014)    // 8
/*=========================================================================*/


/*=========================================================================
    ON-BOARD LED
    -----------------------------------------------------------------------

    CFG_LIB_LED_PORT              The port for the on board LED
    CFG_LIB_LED_PIN               The pin for the on board LED
    CFG_LIB_LED_ON                The pin state to turn the LED on (0 = low, 1 = high)
    CFG_LIB_LED_OFF               The pin state to turn the LED off (0 = low, 1 = high)

    -----------------------------------------------------------------------*/
    #define CFG_LIB_LED_PORT                  (0)
    #define CFG_LIB_LED_PIN                   (7)
    #define CFG_LIB_LED_ON                    (1)
    #define CFG_LIB_LED_OFF                   (0)
/*=========================================================================*/


/*=========================================================================
    COMMAND LINE INTERFACE
    -----------------------------------------------------------------------

    CFG_LIB_INTERFACE             If this field is defined the UART or USBCDC
                              based command-line interface will be included
    CFG_LIB_INTERFACE_MAXMSGSIZE  The maximum number of bytes to accept for an
                              incoming command
    CFG_LIB_INTERFACE_PROMPT      The command prompt to display at the start
                              of every new data entry line
    CFG_LIB_INTERFACE_SILENTMODE  If this is set to 1 only text generated in
                              response to commands will be send to the
                              output buffer.  The command prompt will not
                              be displayed and incoming text will not be
                              echoed back to the output buffer (allowing
                              you to see the text you have input).  This
                              is normally only desirable in a situation
                              where another MCU is communicating with
                              the LPC1343.
    CFG_LIB_INTERFACE_DROPCR      If this is set to 1 all incoming \r
                              characters will be dropped
    CFG_LIB_INTERFACE_ENABLEIRQ   If this is set to 1 the IRQ pin will be
                              set high when a command starts executing
                              and will go low when the command has
                              finished executing or the LCD is not busy.
                              This allows another device to know when a
                              new command can safely be sent.
    CFG_LIB_INTERFACE_IRQPORT     The gpio port for the IRQ/busy pin
    CFG_LIB_INTERFACE_IRQPIN      The gpio pin number for the IRQ/busy pin
    CFG_LIB_INTERFACE_SHORTERRORS If this is enabled only short 1 character
                              error messages will be returned (followed
                              by CFG_LIB_PRINTF_NEWLINE), rather than more
                              verbose error messages.  The specific
                              characters used are defined below.
    CFG_LIB_INTERFACE_CONFIRMREADY  If this is set to 1 a text confirmation
                              will be sent when the command prompt is
                              ready for a new command.  This is in
                              addition to CFG_LIB_INTERFACE_ENABLEIRQ if
                              this is also enabled.  The character used
                              is defined below.
    CFG_LIB_INTERFACE_LONGSYSINFO If this is set to 1 extra information will
                              be included in the Sys Info ('V') command
                              on the CLI. This can be useful when trying
                              to debug problems on remote HW, or with
                              unknown firmware.  It will also use about
                              0.5KB flash, though, so only enable it is
                              necessary.

    NOTE:                     The command-line interface will use either
                              USB-CDC or UART depending on whether
                              CFG_LIB_PRINTF_UART or CFG_LIB_PRINTF_USBCDC are
                              selected.
    -----------------------------------------------------------------------*/
    #define CFG_LIB_INTERFACE
    #define CFG_LIB_INTERFACE_MAXMSGSIZE    (256)
    #define CFG_LIB_INTERFACE_PROMPT        "LPC1347 >> "
    #define CFG_LIB_INTERFACE_SILENTMODE    (0)
    #define CFG_LIB_INTERFACE_DROPCR        (0)
    #define CFG_LIB_INTERFACE_ENABLEIRQ     (0)
    #define CFG_LIB_INTERFACE_IRQPORT       (0)
    #define CFG_LIB_INTERFACE_IRQPIN        (7)
    #define CFG_LIB_INTERFACE_SHORTERRORS   (0)
    #define CFG_LIB_INTERFACE_CONFIRMREADY  (0)
    #define CFG_LIB_INTERFACE_LONGSYSINFO   (1)
/*=========================================================================*/


/*=========================================================================
    SIMPLE BINARY PROTOCOL
    -----------------------------------------------------------------------

    CFG_LIB_PROTOCOL             If this field is defined the binary command
                              parser will be included
    -----------------------------------------------------------------------*/
    #define CFG_LIB_PROTOCOL

//    #define CFG_LIB_PROTOCOL_VIA_HID
     #define CFG_LIB_PROTOCOL_VIA_BULK

    #if defined(CFG_LIB_PROTOCOL) && !defined(CFG_LIB_PROTOCOL_VIA_HID) && !defined(CFG_LIB_PROTOCOL_VIA_BULK)
        #error CFG_LIB_PROTOCOL must be enabled with either CFG_LIB_PROTOCOL_VIA_HID or CFG_LIB_PROTOCOL_VIA_BULK
    #endif
/*=========================================================================*/

/*=========================================================================
    COMMAND LINE INTERFACE
    -----------------------------------------------------------------------

    CFG_LIB_CMDUART               If this field is defined the UART or USBCDC
                              based command-line interface will be included
    CFG_LIB_INTERFACE_MAXMSGSIZE  The maximum number of bytes to accept for an
                              incoming command
    CFG_LIB_INTERFACE_PROMPT      The command prompt to display at the start
                              of every new data entry line
    CFG_LIB_INTERFACE_SILENTMODE  If this is set to 1 only text generated in
                              response to commands will be send to the
                              output buffer.  The command prompt will not
                              be displayed and incoming text will not be
                              echoed back to the output buffer (allowing
                              you to see the text you have input).  This
                              is normally only desirable in a situation
                              where another MCU is communicating with
                              the LPC1343.
    CFG_LIB_INTERFACE_DROPCR      If this is set to 1 all incoming \r
                              characters will be dropped
    CFG_LIB_INTERFACE_ENABLEIRQ   If this is set to 1 the IRQ pin will be
                              set high when a command starts executing
                              and will go low when the command has
                              finished executing or the LCD is not busy.
                              This allows another device to know when a
                              new command can safely be sent.
    CFG_LIB_INTERFACE_IRQPORT     The gpio port for the IRQ/busy pin
    CFG_LIB_INTERFACE_IRQPIN      The gpio pin number for the IRQ/busy pin
    CFG_LIB_INTERFACE_SHORTERRORS If this is enabled only short 1 character
                              error messages will be returned (followed
                              by CFG_LIB_PRINTF_NEWLINE), rather than more
                              verbose error messages.  The specific
                              characters used are defined below.
    CFG_LIB_INTERFACE_CONFIRMREADY  If this is set to 1 a text confirmation
                              will be sent when the command prompt is
                              ready for a new command.  This is in
                              addition to CFG_LIB_INTERFACE_ENABLEIRQ if
                              this is also enabled.  The character used
                              is defined below.
    CFG_LIB_INTERFACE_LONGSYSINFO If this is set to 1 extra information will
                              be included in the Sys Info ('V') command
                              on the CLI. This can be useful when trying
                              to debug problems on remote HW, or with
                              unknown firmware.  It will also use about
                              0.5KB flash, though, so only enable it is
                              necessary.

    NOTE:                     The command-line interface will use either
                              USB-CDC or UART depending on whether
                              CFG_LIB_PRINTF_UART or CFG_LIB_PRINTF_USBCDC are
                              selected.
    -----------------------------------------------------------------------*/
    #define CFG_LIB_CMDUART
    #define CFG_LIB_CMDUART_MAXMSGSIZE    (256)
    #define CFG_LIB_CMDUART_DROPCR        (0)
    #define CFG_LIB_CMDUART_ENABLEIRQ     (0)
    #define CFG_LIB_CMDUART_IRQPORT       (0)
    #define CFG_LIB_CMDUART_IRQPIN        (7)
    #define CFG_LIB_CMDUART_SHORTERRORS   (0)
    #define CFG_LIB_CMDUART_CONFIRMREADY  (0)
    #define CFG_LIB_CMDUART_LONGSYSINFO   (1)
/*=========================================================================*/


/*=========================================================================
    TFT LCD
    -----------------------------------------------------------------------

    CFG_LIB_TFTLCD                  If defined, this will cause drivers for
                                a pre-determined LCD screen to be included
                                during build.  Only one LCD driver can be
                                included during the build process (for ex.
                                'drivers/displays/hw/ILI9325.c')
    CFG_LIB_TFTLCD_INCLUDESMALLFONTS If set to 1, smallfont support will be
                                included for 3x6, 5x8, 7x8 and 8x8 fonts.
                                This should only be enabled if these small
                                fonts are required since there is already
                                support for larger fonts generated with
                                Dot Factory
                                http://www.pavius.net/downloads/tools/53-the-dot-factory
    CFG_LIB_TFTLCD_USEAAFONTS       If set to a non-zero value, anti-aliased
                                fonts will be used instead of regular 1-bit
                                font.  These result in much higher-
                                quality text, but the fonts are 2 or 4
                                times larger than plain bitmap fonts and
                                take a bit more rendering time to display.
    CFG_LIB_TFTLCD_TS_DEFAULTTHRESHOLD  Default minimum threshold to trigger a
                                touch event with the touch screen (and exit
                                from 'tsWaitForEvent' in touchscreen.c).
                                Should be an 8-bit value somewhere between
                                8 and 75 in normal circumstances.  This is
                                the default value and may be overriden by
                                a value stored in EEPROM.
    CFG_LIB_TFTLCD_TS_KEYPADDELAY   The delay in milliseconds between key
                                presses in dialogue boxes
    ----------------------------------------------------------------------*/
//    #define CFG_LIB_TFTLCD
    #define CFG_LIB_TFTLCD_INCLUDESMALLFONTS   (0)
    #define CFG_LIB_TFTLCD_USEAAFONTS          (0)
    #define CFG_LIB_TFTLCD_TS_DEFAULTTHRESHOLD (50)
    #define CFG_LIB_TFTLCD_TS_KEYPADDELAY      (100)
/*=========================================================================*/


/*=========================================================================
    MICRO-SD CARD
    -----------------------------------------------------------------------

    CFG_LIB_SDCARD                If this field is defined SD Card and FAT32
                              file system support will be included
    CFG_LIB_SDCARD_SPIPORT        SSP Port used for the SD card (0 or 1)
    CFG_LIB_SDCARD_READONLY       If this is set to 1, all commands to
                              write to the SD card will be removed
                              saving some flash space.
    CFG_LIB_SDCARD_CDPORT         The card detect port number
    CFG_LIB_SDCARD_CDPIN          The card detect pin number

    NOTE:                     All config settings for FAT32 are defined
                              in ffconf.h
    -----------------------------------------------------------------------*/
//    #define CFG_LIB_SDCARD
    #define CFG_LIB_SDCARD_READONLY         (0)   // Must be 0 or 1
    #define CFG_LIB_SDCARD_SPIPORT          (1)
    #define CFG_LIB_SDCARD_SSELPORT         (1)
    #define CFG_LIB_SDCARD_SSELPIN          (23)
    #define CFG_LIB_SDCARD_CDPORT           (0)
    #define CFG_LIB_SDCARD_CDPIN            (2)
    #define CFG_LIB_SDCARD_ENBLPORT         (0)
    #define CFG_LIB_SDCARD_ENBLPIN          (0)
    #define CFG_LIB_SDCARD_PRESENT_LEVEL    (0)   // If CD == Vcc when card present set to (1)

    #ifdef CFG_LIB_SDCARD
      #if !((CFG_LIB_SDCARD_READONLY == 0) || (CFG_LIB_SDCARD_READONLY == 1))
        #error "Invalid value for CFG_LIB_SDCARD_READONLY"
      #endif
      #if !((CFG_LIB_SDCARD_SPIPORT == 0) || (CFG_LIB_SDCARD_SPIPORT == 1))
        #error "Invalid SPI port for CFG_LIB_SDCARD_SPIPORT"
      #endif
    #endif
/*=========================================================================*/



/*=========================================================================
    RTC SUPPORT
    -----------------------------------------------------------------------

    CFG_LIB_RTC                     If defined, RTC support will be included.
                                Requires external HW.
    -----------------------------------------------------------------------*/
    // #define CFG_LIB_RTC

    #if defined(CFG_LIB_RTC) && !defined(CFG_LIB_ENABLE_I2C)
      #error "CFG_LIB_ENABLE_I2C must be defined with CFG_LIB_RTC"
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
