#include "bmp180.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
	char *i2c_device = "/dev/i2c-1";
	int address = 0x77;
	float alt;

	if (argc < 2) {
		printf("Usage: %s altitude_in_meter\n", argv[0]);
		return 1;
	}
	sscanf(argv[1], "%f", &alt);
	void *bmp = bmp180_init(address, i2c_device);
	
	
	if(bmp != NULL){
		bmp180_set_oss(bmp, 1);
		printf("%f\n", bmp180_pressure_at_sea_level(bmp, alt) / 100.0);
		bmp180_close(bmp);
	}
	
	return 0;
}
