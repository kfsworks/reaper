#ifndef USB_SYSTEM_H_
#define USB_SYSTEM_H_

#include <libusb.h>
#include <iostream>

class USBSystem {
  public:
    USBSystem();
    ~USBSystem();

  public:
    void test();
};

#endif // USB_SYSTEM_H_
