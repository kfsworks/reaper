#include "usb_system.hpp"

USBSystem::USBSystem() {
  //LIBUSB_SUCCESS
  int r = libusb_init(nullptr);
}

USBSystem::~USBSystem() {
  libusb_exit(nullptr);
}
