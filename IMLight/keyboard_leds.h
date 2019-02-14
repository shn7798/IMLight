

#ifndef KEYBOARD_LED_H
#define KEYBOARD_LED_H

//#include <stdio.h>
//#include <getopt.h>
#include <stdlib.h>
#include <sysexits.h>
#include <mach/mach_error.h>

#include <IOKit/IOCFPlugIn.h>
#include <IOKit/hid/IOHIDLib.h>
#include <IOKit/hid/IOHIDUsageTables.h>

static IOHIDElementCookie capslock_cookie = (IOHIDElementCookie)0;
static IOHIDElementCookie numlock_cookie  = (IOHIDElementCookie)0;
static int capslock_value = -1;
static int numlock_value  = -1;

void  print_errmsg_if_io_err(int expr, char* msg);
void  print_errmsg_if_err(int expr, char* msg);

io_service_t find_a_keyboard(void);
void         find_led_cookies(IOHIDDeviceInterface122** handle);
void         create_hid_interface(io_object_t hidDevice,
                                  IOHIDDeviceInterface*** hdi);
int          manipulate_led(UInt32 whichLED, UInt32 value);

#endif
