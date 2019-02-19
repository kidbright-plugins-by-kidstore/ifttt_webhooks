#ifndef __IFTTT_H__
#define __IFTTT_H__

#include "driver.h"
#include "device.h"
#include "esp_log.h"

#include "esp_http_client.h"

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "kidbright32.h"

class IFTTT : public Device {
	private:
		char value[3][100];

	public:
		// constructor
		IFTTT();
		// override
		void init(void);
		void process(Driver *drv);
		int prop_count(void);
		bool prop_name(int index, char *name);
		bool prop_unit(int index, char *unit);
		bool prop_attr(int index, char *attr);
		bool prop_read(int index, char *value);
		bool prop_write(int index, char *value);
		
		// method
		void set(uint8_t n, char *value) ; 
		void set(uint8_t n, double value) ;
		void set(uint8_t n, int value) ; 
		void set(uint8_t n, bool value) ; 
		
		esp_err_t send(char *key, char *event) ;
		
};

#endif
