/*
 * owon-utils - a set of programs to use with OWON Oscilloscopes
 * Copyright (c) 2012  Levi Larsen <levi.larsen@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef __OWON__USB_H__
#define __OWON__USB_H__

#ifndef USB_DEBUG
#define USB_DEBUG 1
#endif

#define OWON_USB_VENDOR_ID 0x5345
#define OWON_USB_PRODUCT_ID 0x1234

#define OWON_USB_INTERFACE 0x0
#define OWON_USB_CONFIGURATION 0x1

#define OWON_USB_ENDPOINT_IN 0x81
#define OWON_USB_ENDPOINT_OUT 0x03

// Transfer timout in milliseconds
#define OWON_USB_TRANSFER_TIMEOUT 1000

enum owon_start_command_type {
	DUMP_BMP = 0,
	DUMP_BIN,
	DUMP_MEMDEPTH,
	DUMP_DEBUGTXT,
	DUMP_COUNT
};

void owon_usb_init(void);
struct usb_device *owon_usb_get_device(int dnum);
size_t owon_usb_get_device_count();
struct usb_dev_handle *owon_usb_easy_open(int dnum);
struct usb_dev_handle *owon_usb_open(struct usb_device *dev);
int owon_usb_read(struct usb_dev_handle *dev_handle, char **buffer, enum owon_start_command_type type);
void owon_usb_close(struct usb_dev_handle *dev_handle);

#endif // __OWON__USB_H__