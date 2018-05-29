#include <cstdio>
#include <cstring>
#include <cstdint>

#include "hidapi.h"

int main()
{
	const uint16_t vendor_id = 0x17EF;
	const uint16_t product_id = 0x6048;

	if (hid_init()) {
		return -1;
	}

	hid_device *dev = hid_open(vendor_id, product_id, 0);

	if (dev == 0) {
		printf("TP Keyboard not found. Have you run it with 'sudo'?\n");
		return 0;
	}

	unsigned char buf[4];

	// sensitivity
	// 18 02 05 - Sensitivity, 01--09 in windows, 00--FF works
	buf[0] = 0x18;
	buf[1] = 0x02;
	buf[2] = 0x08;
	hid_write(dev, buf, 3);

	hid_close(dev);
	return 0;
}
