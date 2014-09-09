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

#define CFG_LIB_STDIO_USBCDC   (FILE *)(0x40)
#define CFG_LIB_STDIO_UART     (FILE *)(0x41)

#ifdef CFG_LIB_PRINTF_USBCDC
#define printf(args...) fprintf(CFG_LIB_STDIO_USBCDC, args...)
#else
#ifdef CFG_LIB_PRINTF_UART
#define printf(args...) fprintf(CFG_LIB_STDIO_UART, args...)
#else
#define printf(args...)
#endif
#endif

#endif /* LIBIO_H_ */
