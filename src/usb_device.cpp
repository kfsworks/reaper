#include "usb_device.hpp"

USBDevice::USBDevice() {
  //LIBUSB_SUCCESS
  int r = libusb_init(nullptr);
}

USBDevice::~USBDevice() {
  libusb_exit(nullptr);
}
