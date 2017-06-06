#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#define SPEED 1000000
#define CSDAC 0
#define LDAC 2
#define CHDAC 0


void escribirDAC( void );

int main() {

	int file_des;

	wiringPiSetup();
	pinMode(CSDAC, OUTPUT);
	pinMode(LDAC, OUTPUT);

	file_des = wiringPiSPISetup(CHDAC, SPEED);

	escribirDAC();

	return 0;
}

void escribirDAC( void ) {

	unsigned char datos[2] =  {0x18, 0x00};
	unsigned char byte;

	digitalWrite(CSDAC, 0);
	digitalWrite(LDAC, 1);

	wiringPiSPIDataRW(CHDAC, datos, 2);

	digitalWrite((CSDAC, 1);

	digitalWrite(LDAC, 0);
	usleep(1);
	digitalWrite(LDAC, 1);
}
