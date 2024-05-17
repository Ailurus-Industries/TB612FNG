#include "TB6612FNG.h"
#include <Arduino.h>

TB6612FNG driver;

void setup()
{
	driver = TB6612FNG(
        13, 16,
        14, 15,
        17, 18,
        12
    );
}

void loop()
{
	driver.run(0, 255);
    delay(1000);
    driver.run(0,0);
    delay(1000);

}
