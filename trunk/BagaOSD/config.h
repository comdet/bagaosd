//RSSI Choice (PWM or Analog)
#define RSSI_USE_PWM               ENABLED     //Use PWM to decode RSSI signal. This can be commented to use instead analog RSS

//RSSI PWM config
#define RSSI_PIN_PWM               12       //RSSI PWM digital pin number 
#define RSSI_RC_FILTER             8000    //RSSI constant to analyse PWM RSSI signal (https://sites.google.com/site/arduinorccar/lowpassfilter)
#define RSSI_RSSI_MAX              135      //RSSI Max signal value
#define RSSI_SCALE_MIN             3.5       //Min value for Sigmoid function
#define RSSI_SCALE_MAX             -2      //Max value for Sigmoid function


//RSSI Analog config
#define RSSI_PIN_ANALOG            A2   //RSSI_USE_PWM must be disabled to use it. -1 to disable, or A0, A1, A2, A3 (default A2)

//Radio receiver information
#define RC_PPM_MODE                ENABLED      //Decode PPM Sum with arduino pin 2. This can be commented to use standard RX configuration instead of PPM Sum configuration.
#define SERIAL_SUM_PPM             ROLL_PPM,PITCH_PPM,THROTTLE_PPM,YAW_PPM,X1_PPM,X2_PPM,FMODE_PPM,AUX4_PPM,8,9,10,11 //Order of PPM channels

//Sensor config
#define INTERNAL_VOLTAGE_REF       5160  //Internal voltage can vary, so to get the same measured value, we should compare to a fixed reference. This can be commented to be disabled.
//#define VOLTAGE_THROTTLE_COMP      0.14 //0 : no compensation. Used if sensor voltage drop too much when there's some throttle. This can be commented to be disabled.

//Voltage sensor
#define VOLTAGE_PIN                A0    //Voltage sensor pin
#define VOLTAGE_FACTOR             12.35 //Rise this value to lower voltage output value   
#define VOLTAGE_BUFFER             128   //Internal buffer to smooth voltage value

//Current sensor
#define CURRENT_PIN                A3    //Current sensor pin
#define CURRENT_FACTOR             2.46 //2.05  //1.85  //Rise this value to lower current output value   
#define CURRENT_BUFFER             128   //Internal buffer to smooth current value

//#define ESTIMATE_BATTERY_REMAINING  ENABLED   //Commented to use a current sensor, current sensor is not used if uncommented.
#define LIPO_CELL                  4     //Number of cell, for estimate capacity (ESTIMATE_BATTERY_REMAINING)
#define LIPO_CAPACITY_MAH          8000  //LIPO capacity in mah

//GPS Handler
#define DECODE_NAZA_GPS            TRUE  //TRUE : Decode Naza GPS Protocol - FALSE : Solder a wire and decode RAW uBlox Message
#define NAZA_COMPASS_TILT_COMP     FALSE  //TRUE : Experimental Tilt compensate compass information from Naza GPS, FALSE no tilt compensation, use COG instead of heading 

//Throttle
#define THROTTLE_PWM_MIN           1000
#define THROTTLE_PWM_MAX           2000

//Artificial horizon
#define PITCH_GAIN                 4.3 //Set Pitch Naza gain to 20 in Naza GUI
#define PITCH_LEVEL                1500
#define PITCH_INVERT               FALSE

#define ROLL_GAIN                  4.3 //Set Roll Naza gain to 20 in Naza GUI
#define ROLL_LEVEL                 1500
#define ROLL_INVERT                FALSE


/**
Standard receiver configuration
Pin 2           :   Throttle
Pin 4           :   Gimbal roll for horizon display
Pin 5           :   Gimbal pitch for horizon display
Pin 6           :   AUX (for pannel switch in MinimOSD)
Pin 7           :   FMode (Flight mode : Acro / Atti / Gps / Failsafe) - Flight Mode


PPM Sum receiver configuration
Pin 2           :   PPM Sum signal from receiver
Pin 4           :   Gimbal roll for horizon display  (it's not a PPM Sum signal)
Pin 5           :   Gimbal pitch for horizon display (it's not a PPM Sum signal)

RSSI Configuration 
Pin A2          :   Analog RSSI (#define RSSI_PIN_ANALOG)
Pin 12          :   PWM RSSI    (#define RSSI_PIN_PWM)

Sensor
Voltage sensor  :   A0 (#define VOLTAGE_PIN)
Current sensor  :   A3 (#define CURRENT_PIN)
GPS             :   RX

**/
