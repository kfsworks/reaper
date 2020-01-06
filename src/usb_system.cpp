#include "usb_system.hpp"

USBSystem::USBSystem() {
  //LIBUSB_SUCCESS
  int r = libusb_init(nullptr);
}

USBSystem::~USBSystem() {
  libusb_exit(nullptr);
}

void USBSystem::test() {
  libusb_device **devs;
  ssize_t cnt;

  cnt = libusb_get_device_list(nullptr, &devs);
  if (cnt < 0){
    return;
  }

//  print_devs(devs);
  libusb_device *dev;
  int i = 0, j = 0;
  uint8_t path[8];

  while ((dev = devs[i++]) != nullptr) {
    struct libusb_device_descriptor desc;
    int r = libusb_get_device_descriptor(dev, &desc);
    if (r < 0) {
      std::cout << "failed to get device descriptor" << std::endl;
      return;
    }

    std::cout << desc.idVendor << ":" << desc.idProduct << " (bus " << libusb_get_bus_number(dev) << ", device " << libusb_get_device_address(dev) << ")" << std::endl;

    r = libusb_get_port_numbers(dev, path, sizeof(path));
    if (r > 0) {
      std::cout << "path: " << path[0] << std::endl;
      for (j = 1; j < r; j++) {
        std::cout << "." << path[j];
      }
    }
    std::cout << std::endl;
  }

  libusb_free_device_list(devs, 1);
}
