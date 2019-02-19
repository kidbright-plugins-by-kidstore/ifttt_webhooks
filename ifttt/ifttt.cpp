#ifndef __IFTTT_CPP__
#define __IFTTT_CPP__

#include "ifttt.h"

IFTTT::IFTTT() { }

void IFTTT::init(void) {
	esp_log_level_set("*", ESP_LOG_INFO);
	
	memset(this->value, 0, sizeof value);
	
	// clear error flag
	error = false;
	// set initialized flag
	initialized = true;
}

int IFTTT::prop_count(void) {
	return 0;
}

bool IFTTT::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool IFTTT::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool IFTTT::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool IFTTT::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool IFTTT::prop_write(int index, char *value) {
	// not supported
	return false;
}

void IFTTT::process(Driver *drv) {
	
}

void IFTTT::set(uint8_t n, char *value) {
	strcpy(this->value[n-1], value);
}

void IFTTT::set(uint8_t n, double value) {
	sprintf(this->value[n-1], "%f", value);
}

void IFTTT::set(uint8_t n, int value) {
	itoa(value, this->value[n-1], 10);
}

void IFTTT::set(uint8_t n, bool value) {
	this->value[n-1][0] = value ? '1' : '0';
	this->value[n-1][1] = 0;
}


esp_err_t IFTTT::send(char *key, char *event) {
	char *url = (char *)malloc(200);
	memset(url, 0, 200);

	sprintf(url, "http://maker.ifttt.com/trigger/%s/with/key/%s", event, key);
	ESP_LOGI("IFTTT", "Url: %s", url);
	
	char *value1Buf = (char *)malloc(100);
	char *value2Buf = (char *)malloc(100);
	char *value3Buf = (char *)malloc(100);
	
	memset(value1Buf, 0, 100);
	memset(value2Buf, 0, 100);
	memset(value3Buf, 0, 100);
	
	uint8_t i, i2;
	
	i2 = 0;
	for (i=0;i<strlen(value[0]);i++) {
		if (value[0][i] == '"') value1Buf[i2++] = '\\';
		value1Buf[i2++] = value[0][i];
	}
	
	i2 = 0;
	for (i=0;i<strlen(value[1]);i++) {
		if (value[1][i] == '"') value2Buf[i2++] = '\\';
		value2Buf[i2++] = value[1][i];
	}
	
	i2 = 0;
	for (i=0;i<strlen(value[2]);i++) {
		if (value[2][i] == '"') value3Buf[i2++] = '\\';
		value3Buf[i2++] = value[2][i];
	}
	
	char *data = (char *)malloc(320);
	sprintf(data, "{\"value1\":\"%s\",\"value2\":\"%s\",\"value3\":\"%s\"}", value1Buf, value2Buf, value3Buf);
	
	free(value1Buf);
	free(value2Buf);
	free(value3Buf);
	
	// Use esp http api
	esp_http_client_config_t config = {
        .url = url
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_POST);
	esp_http_client_set_post_field(client, data, strlen(data));
	esp_http_client_set_header(client, "Content-Type", "application/json");
	
	ESP_LOGI("IFTTT", "Data: %s, len: %d", data, strlen(data));

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
		uint16_t len = esp_http_client_get_content_length(client);
		uint16_t code = esp_http_client_get_status_code(client);
		
        ESP_LOGI("IFTTT", "HTTPS Status = %d, content_length = %d", code, len);
		
		/*
		memset(data, 0, 100);
		esp_http_client_read(client, data, len);
		
		if (code != 200) {
			ESP_LOGI("IFTTT", "Content: %s", data);
		}
		*/
    } else {
        ESP_LOGE("IFTTT", "Error perform http request %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);
	
	free(url);
	free(data);
	memset(value, 0, sizeof value);
	
	return err;
}

#endif
