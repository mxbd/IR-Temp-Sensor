# IR-Temp-Sensor

**Using a microcontroller and infrared temp sensor to monitor and display ambient air and engine temp of a motorcycle on an OLED screen**

V1 is for 0.96" OLED Displays using a SSD1306 Driver (uses Adafruits library)

V2 is for 1.3" OLED Displays using a SH1106 Driver (uses 8glib library)


## Parts list:


1x Arduino Nano

1x MLX90614 I2C IR Sensor

1x 0.96" (SSD1306) or 1.3" (SH1106) OLED Display 

## Description:

Both the IR Sensor and Display use the I2C protocol to connect to the Arduino with a two-wire interface (SCL - Serial Clock Line and SDL - Serial Data Line), +5V and Ground in order to limit the amount of cables needed to power the system and transfer data as the housing will be relatively small. 

This set up will be used on an older air/engine-oil cooled motorcycle and used as a "bolt-on" part. The MLX90614 is used due to its relatively low cost, small size and factory calibrated wide operating range (-40°C…+125˚C for sensor temperature and
 -70°C…+380˚C for object temperature). Due to the IR Sensor being a non-contact temp sensor there is no need to open up any of the oil cooler lines in order to fit a sensor. The OLED Screen was chosen to minimize the current needed to power the display. The display should use an average of 20mA (...depending on how much of the display is lit) mostly due to the absence of a backlight. With high contrast and wide viewing angle the display should be readable even on the move.
 
As standard the MLX90614 is calibrated for an object emissivity of 1 (roughly that of a Matte Black Body). Although the emissivity can be recalibrated according to that of the object that is being measured (which would be neccesary for achieving very accurate temp values) it is not really required for this project. First of all according to various emissivity tables and the material and paint on the engine should correspond with an emissivity of roughly 0.75 - 0.9 at operating temp but more importantly the measurement will be used as a reference and not solely to measure absolute temp values.

The system will run off of the onboard 12V supply which should be regulated by the Arduinos internal voltage regulator as to supply the sensor and display with a constant 5V supply. Depending on the fluctuations in output voltage of the bike, which will be dependent on the revs, an external voltage regulator may be needed.

## Schematic:
![](schematic/TempSensorSchematic.jpg)

As long as each device has a different I2C address they can both be hooked up to the same SDA & SCL pins

## Set-Up

Test set-up

<img src="images/set_up.jpg" width="500" >

Start-Up Logo

<img src="images/start_up_logo.jpg" width="500" >

Temp readings example in housing   

<img src="images/temp_readings_example.jpg" width="500" >

                                
