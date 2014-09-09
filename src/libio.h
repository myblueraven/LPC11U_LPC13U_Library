/*
 * libio.h
 *
 *  Created on: Sep 9, 2014
 *      Author: iceman
 */

#ifndef LIBIO_H_
#define LIBIO_H_

#include <stdio.h>

#include "libconfig.h"

#define LIB_STDIO_USBCDC   (FILE *)(0x40)
#define LIB_STDIO_UART0    (FILE *)(0x41)
#define LIB_STDIO_UART1    (FILE *)(0x42)

#ifdef CFG_LIB_PRINTF_USBCDC
#define printf(args...) fprintf(LIB_STDIO_USBCDC, args...)
#else
#ifdef CFG_LIB_PRINTF_UART
#define printf(args...) fprintf(LIB_STDIO_UART0, args...)
#else
#define printf(args...)
#endif
#endif

#endif /* LIBIO_H_ */
