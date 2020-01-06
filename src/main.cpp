#include <stdio.h>
#include <iostream>
//#include "libusb.h"
#include "../include/usb_system.hpp"

int main(void) {
  USBSystem a;
  std::cout << "hi" << std::endl;

  a.test();

	return 0;
}
