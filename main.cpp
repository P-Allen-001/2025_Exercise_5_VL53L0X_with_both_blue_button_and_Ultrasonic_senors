#include "mbed.h"

#include "VL53L0X.h"
#include "SRF05.h"

SRF05 srf_Left(PA_10,PB_3); // Output from PA_10 (D2) is connected to the Trigger pin of the SRF05, Input to PB_3 (D3) is connected to the SRF05 Echo_Pin. 
SRF05 srf_Right(PA_8,PA_9); // Output from PA_8 (D7) is connected to the Trigger pin of the SRF05, Input to PA_9 (D8) is connected to the SRF05 Echo_Pin.   


I2C i2c(PB_9,PB_8);
VL53L0X sensor(&i2c);
Serial      usb(USBTX, USBRX, 9600);

DigitalIn Blue_button(PC_13);

int main(void) {

    while (1){

    if (Blue_button==0)     {
                        sensor.init();
                        sensor.setModeContinuous();
                        sensor.startContinuous();

      while(Blue_button==0) {
                        wait(0.05);
                        printf("Distance: %d mm\r\n", sensor.getRangeMillimeters());
                            }
                            }


    if (Blue_button==1)     {

                             printf("Left: %.1f"  , srf_Left.read() ) ;
                             printf("  Right: %.1f\n", srf_Right.read());
                             printf("\n");
                             wait(0.05);   
                            }
    }
    }