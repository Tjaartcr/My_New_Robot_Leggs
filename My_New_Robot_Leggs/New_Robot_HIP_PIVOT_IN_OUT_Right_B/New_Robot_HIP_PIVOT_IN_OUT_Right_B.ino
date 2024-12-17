


//#######################################################################################################################################

//#include <SoftwareSerial.h>
//
//SoftwareSerial MySerial(12, 13); // RX, TX

String X_Left;
long int X_Left_Out;
int My_Message_To_Send;

//#######################################################################################################################################

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//#######################################################################################################################################

//#include <MPU9250_WE.h>
////#include <Wire.h>
//#define MPU9250_ADDR 0x68
//MPU9250_WE myMPU9250 = MPU9250_WE(MPU9250_ADDR);


//  xyzFloat gValue = myMPU9250.getGValues();
//  xyzFloat angle = myMPU9250.getAngles();
  //#######################################################################################################################################
//                      MOTORS ON / OFF SWITCH CONTROL

#define Motors_On_Off_Switch 40
int Motors_On_Off_Switch_State;

volatile bool Run_Robot;
volatile bool Stop_Robot;
  

//#######################################################################################################################################
//                      REMOTE CONTROL SYSTEM

#define Analog_In_X_Joy_setpoint A0
int ANALOG_IN_X_JOY_SETPOINT = 0;
int Analog_In_X_Joy_Current_setpoint;

#define Analog_In_Y_Joy_setpoint A1
int ANALOG_IN_Y_JOY_SETPOINT = 0;
int Analog_In_Y_Joy_Current_setpoint;

int New_Ankle_Pivot_Left_Right_setpoint;
int New_Ankle_Pivot_Up_Down_setpoint;
int New_Knee_Bend_Straight_setpoint;
int New_Hip_Bend_Back_setpoint;
int New_Hip_Pivot_Left_Right_setpoint;
int New_Left_Hip_Pivot_In_Out_setpoint;
int New_Right_Hip_Pivot_In_Out_setpoint;


#define Remote_On_Off_Switch 33
int Remote_On_Off_SwitchState;

#define Joy_Switch_Button 35
int Joy_Switch_ButtonState;

#define Menu_Up_Button 37
int Menu_Up_ButtonState;

#define Menu_Down_Button 39
int Menu_Down_ButtonState;

#define Menu_Enter_Button 41
int Menu_Enter_ButtonState;

#define Menu_Exit_Button 43
int Menu_Exit_ButtonState;

#define Analog_In_Slider_setpoint A14
int ANALOG_IN_SLIDER_SETPOINT = 0;
int Analog_In_Slider_Current_setpoint;


#define Analog_In_Pot_setpoint A15
int ANALOG_IN_POT_SETPOINT = 0;
int Analog_In_Pot_Current_setpoint;

int Current_Angle_Set;
int Current_Angle;

#define HeartbeatLED 48


//___________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

//#######################################################################################################################################
//         REMOTE CONTROL MENU SYSTEM

int Menu = 0;
int Menu_Up;
int Menu_Down;
int Menu_Enter;
int Menu_Exit;


int Menu_Cursor_Row;
int Menu_Cursor_Colomn;


//___________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

//#######################################################################################################################################
//          RIGHT LEG PIN CONFIGURATION AND DECLARATION

#define Right_Ankle_Pivot_Left_Right_MotorPin1  4               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Right_Ankle_Pivot_Left_Right_MotorPin2  5                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Right_Ankle_Pivot_Left_Right_MotorENA  12                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Right_Ankle_Pivot_Up_Down_MotorPin1  6               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Right_Ankle_Pivot_Up_Down_MotorPin2  7                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Right_Ankle_Pivot_Up_Down_MotorENA  13                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Right_Knee_Bend_Straight_MotorPin1  8               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Right_Knee_Bend_Straight_MotorPin2  9               // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Right_Hip_Pivot_Forward_Backward_MotorPin1  10               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Right_Hip_Pivot_Forward_Backward_MotorPin2  11                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Right_Hip_Pivot_Left_Right_MotorPin1  14               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Right_Hip_Pivot_Left_Right_MotorPin2  15                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Right_Hip_Pivot_Left_Right_MotorENA  44                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Right_Hip_Pivot_In_Out_MotorPin1  16               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Right_Hip_Pivot_In_Out_MotorPin2  17                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Right_Hip_Pivot_In_Out_MotorENA  45                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board


//#define Right_Heel_Switch 60
//int Right_Heel_Switch_State;
//
//#define Right_Big_Toe_Switch 61
//int Right_Big_Toe_Switch_State;
//
//#define Right_Small_Toe_Switch 23
//int Right_Small_Toe_Switch_State;
//
//#define Right_Big_Toe_Bump_Switch 42
//int Right_Big_Toe_Bump_Switch_State;
//
//#define Right_Small_Toe_Bump_Switch 62
//int Right_Small_Toe_Bump_Switch_State;

////________________________________________________________________________________
////          RIGHT LEG ANKLE LEFT & RIGHT ANALOG REFRENCE AND DECLARATION
//
//#define Analog_Right_Ankle_Left_Right_Actual A3
//int ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT  = 0;
//int Right_Ankle_Pivot_Left_Right_Current_Angle;
//int RIGHT_ANKLE_LEFT_RIGHT_MIN = 50;
//int RIGHT_ANKLE_LEFT_RIGHT_MAX = 140;
//
//volatile bool RIGHT_ANKLE_LEFT_RIGHT_MIN_STOP = false;
//volatile bool RIGHT_ANKLE_LEFT_RIGHT_MAX_STOP = false;
//
//volatile bool RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//volatile bool RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//volatile bool RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//volatile bool RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
//
//int Right_Ankle_Left_Right_Angle_To_Go_To;
//int Right_Ankle_Left_Right_Angle_Speed;
//
//
//int Right_Ankle_Pivot_Left_Right_Offset = 10;
//int Right_Ankle_Pivot_Left_Right_Offset1 = 5;
//
////#######################################################################################################################################
//
//


//________________________________________________________________________________
//          RIGHT LEG ANKLE LEFT & RIGHT ANALOG REFRENCE AND DECLARATION

#define Analog_Right_Ankle_Left_Right_Actual A2
int ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT  = 0;
int Right_Ankle_Pivot_Left_Right_Current_Angle;
int RIGHT_ANKLE_LEFT_RIGHT_MIN = 40;
int RIGHT_ANKLE_LEFT_RIGHT_MAX = 110;

int Right_Ankle_Left_Right_Joy_Min;
int Right_Ankle_Left_Right_Joy_Max;

volatile bool RIGHT_ANKLE_LEFT_RIGHT_MIN_STOP = false;
volatile bool RIGHT_ANKLE_LEFT_RIGHT_MAX_STOP = false;

volatile bool RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
volatile bool RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
volatile bool RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
volatile bool RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

int Right_Ankle_Left_Right_Angle_To_Go_To;
int Right_Ankle_Left_Right_Angle_Speed;


int Right_Ankle_Pivot_Left_Right_Offset = 10;
int Right_Ankle_Pivot_Left_Right_Offset1 = 5;

//________________________________________________________________________________
//          RIGHT LEG ANKLE UP & DOWN ANALOG REFRENCE AND DECLARATION

#define Analog_Right_Ankle_Pivot_Up_Down_Actual A3
int ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT  = 0;
int Right_Ankle_Pivot_Up_Down_Current_Angle;
int RIGHT_ANKLE_PIVOT_UP_DOWN_MIN = 40;
int RIGHT_ANKLE_PIVOT_UP_DOWN_MAX = 130;



volatile bool RIGHT_ANKLE_PIVOT_UP_DOWN_MIN_STOP = false;
volatile bool RIGHT_ANKLE_PIVOT_UP_DOWN_MAX_STOP = false;

volatile bool RIGHT_ANKLE_PIVOT_UP_STOPPED = false;
volatile bool RIGHT_ANKLE_PIVOT_DOWN_STOPPED = false;
volatile bool RIGHT_ANKLE_PIVOT_UP_RUNNING = false;
volatile bool RIGHT_ANKLE_PIVOT_DOWN_RUNNING = false;


int Right_Ankle_Pivot_Up_Down_Angle_To_Go_To;
int Right_Ankle_Pivot_Up_Down_Angle_Speed;


int Right_Ankle_Pivot_Up_Down_Offset = 10;
int Right_Ankle_Pivot_Up_Down_Offset1 = 5;


//________________________________________________________________________________
//          RIGHT LEG KNEE BEND & STRAIGHGT ANALOG REFRENCE AND DECLARATION

#define Analog_Right_Knee_Bend_Straight_Actual A4
int ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT  = 0;
int Right_Knee_Bend_Straight_Current_Angle;
int RIGHT_KNEE_BEND_STRAIGHT_MIN = 40;
int RIGHT_KNEE_BEND_STRAIGHT_MAX = 130;



volatile bool RIGHT_KNEE_BEND_STRAIGHT_MIN_STOP = false;
volatile bool RIGHT_KNEE_BEND_STRAIGHT_MAX_STOP = false;

volatile bool RIGHT_KNEE_STRAIGHT_STOPPED = false;
volatile bool RIGHT_KNEE_BEND_STOPPED = false;
volatile bool RIGHT_KNEE_STRAIGHT_RUNNING = false;
volatile bool RIGHT_KNEE_BEND_RUNNING = false;


int Right_Knee_Bend_Straight_Angle_To_Go_To;
int Right_Knee_Bend_Straight_Angle_Speed;


int Right_Knee_Bend_Straight_Offset = 10;
int Right_Knee_Bend_Straight_Offset1 = 5;


//________________________________________________________________________________
//          RIGHT LEG HIP BEND & STRAIGHT ANALOG REFRENCE AND DECLARATION

#define Analog_Right_Hip_Bend_Back_Actual A5
int ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT  = 0;
int Right_Hip_Bend_Back_Current_Angle;
int RIGHT_HIP_BEND_BACK_MIN = 40;
int RIGHT_HIP_BEND_BACK_MAX = 130;



volatile bool RIGHT_HIP_BEND_BACK_MIN_STOP = false;
volatile bool RIGHT_HIP_BEND_BACK_MAX_STOP = false;

volatile bool RIGHT_HIP_BACK_STOPPED = false;
volatile bool RIGHT_HIP_BEND_STOPPED = false;
volatile bool RIGHT_HIP_BACK_RUNNING = false;
volatile bool RIGHT_HIP_BEND_RUNNING = false;


int Right_Hip_Bend_Back_Angle_To_Go_To;
int Right_Hip_Bend_Back_Angle_Speed;


int Right_Hip_Bend_Back_Offset = 10;
int Right_Hip_Bend_Back_Offset1 = 5;


//________________________________________________________________________________
//          RIGHT LEG HIP IN & OUT ANALOG REFRENCE AND DECLARATION

#define Analog_Right_Hip_Pivot_In_Out_Actual A6
int ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT  = 0;
int Right_Hip_Pivot_In_Out_Current_Angle;
int RIGHT_HIP_PIVOT_IN_OUT_MIN = 40;
int RIGHT_HIP_PIVOT_IN_OUT_MAX = 130;



volatile bool RIGHT_HIP_PIVOT_IN_OUT_MIN_STOP = false;
volatile bool RIGHT_HIP_PIVOT_IN_OUT_MAX_STOP = false;

volatile bool RIGHT_HIP_PIVOT_IN_STOPPED = false;
volatile bool RIGHT_HIP_PIVOT_OUT_STOPPED = false;
volatile bool RIGHT_HIP_PIVOT_IN_RUNNING = false;
volatile bool RIGHT_HIP_PIVOT_OUT_RUNNING = false;


int Right_Hip_Pivot_In_Out_Angle_To_Go_To;
int Right_Hip_Pivot_In_Out_Angle_Speed;


int Right_Hip_Pivot_In_Out_Offset = 10;
int Right_Hip_Pivot_In_Out_Offset1 = 5;

//________________________________________________________________________________
//          RIGHT LEG HIP LEFT & RIGHT ANALOG REFRENCE AND DECLARATION

#define Analog_Right_Hip_Pivot_Left_Right_Actual A7
int ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT  = 0;
int Right_Hip_Pivot_Left_Right_Current_Angle;
int RIGHT_HIP_PIVOT_LEFT_RIGHT_MIN = 40;
int RIGHT_HIP_PIVOT_LEFT_RIGHT_MAX = 130;


volatile bool RIGHT_HIP_PIVOT_LEFT_RIGHT_MIN_STOP = false;
volatile bool RIGHT_HIP_PIVOT_LEFT_RIGHT_MAX_STOP = false;

volatile bool RIGHT_HIP_PIVOT_LEFT_STOPPED = false;
volatile bool RIGHT_HIP_PIVOT_RIGHT_STOPPED = false;
volatile bool RIGHT_HIP_PIVOT_LEFT_RUNNING = false;
volatile bool RIGHT_HIP_PIVOT_RIGHT_RUNNING = false;


int Right_Hip_Pivot_Left_Right_Angle_To_Go_To;
int Right_Hip_Pivot_Left_Right_Angle_Speed;


int Right_Hip_Pivot_Left_Right_Offset = 10;
int Right_Hip_Pivot_Left_Right_Offset1 = 5;

////___________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

//#######################################################################################################################################
//          LEFT LEG PIN CONFIGURATION AND DECLARATION


#define Left_Ankle_Pivot_Left_Right_MotorPin1  24               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Left_Ankle_Pivot_Left_Right_MotorPin2  26                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Left_Ankle_Pivot_Left_Right_MotorENA  2                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Left_Ankle_Pivot_Up_Down_MotorPin1  28               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Left_Ankle_Pivot_Up_Down_MotorPin2  30                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Left_Ankle_Pivot_Up_Down_MotorENA  3                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Left_Knee_Bend_Straight_MotorPin1  25               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Left_Knee_Bend_Straight_MotorPin2  27                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Left_Hip_Bend_Back_MotorPin1  29               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Left_Hip_Bend_Back_MotorPin2  31                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Left_Hip_Pivot_Left_Right_MotorPin1  32               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Left_Hip_Pivot_Left_Right_MotorPin2  34                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Left_Hip_Pivot_Left_Right_MotorENA  46                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

#define Left_Hip_Pivot_In_Out_MotorPin1  36               // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define Left_Hip_Pivot_In_Out_MotorPin2  38                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define Left_Hip_Pivot_In_Out_MotorENA  47                // IN2 pin on the ULN2003A driver to pin D2 on NodeMCU board

//#define Left_Heel_Switch 33
//int Left_Heel_Switch_State;
//
//#define Left_Big_Toe_Switch 35
//int Left_Big_Toe_Switch_State;
//
//#define Left_Small_Toe_Switch 37
//int Left_Small_Toe_Switch_State;
//
//
//#define Left_Big_Toe_Bump_Switch 39
//int Left_Big_Toe_Bump_Switch_State;
//
//#define Left_Small_Toe_Bump_Switch 41
//int Left_Small_Toe_Bump_Switch_State;

//________________________________________________________________________________
//          LEFT LEG ANKLE LEFT & RIGHT ANALOG REFRENCE AND DECLARATION

#define Analog_Left_Ankle_Left_Right_Actual A8
int ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT  = 0;
int Left_Ankle_Pivot_Left_Right_Current_Angle;
int LEFT_ANKLE_LEFT_RIGHT_MIN = 60;
int LEFT_ANKLE_LEFT_RIGHT_MAX = 140;
int Left_Ankle_Left_Right_Timer_Speed;


volatile bool LEFT_ANKLE_LEFT_RIGHT_MIN_STOP = false;
volatile bool LEFT_ANKLE_LEFT_RIGHT_MAX_STOP = false;

volatile bool LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
volatile bool LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
volatile bool LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
volatile bool LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;


int Left_Ankle_Left_Right_Angle_To_Go_To;
int Left_Ankle_Left_Right_Angle_Speed;


int Left_Ankle_Pivot_Left_Right_Offset = 10;
int Left_Ankle_Pivot_Left_Right_Offset1 = 5;

//________________________________________________________________________________
//          LEFT LEG ANKLE UP & DOWN ANALOG REFRENCE AND DECLARATION

#define Analog_Left_Ankle_Pivot_Up_Down_Actual A9
int ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT  = 0;
int Left_Ankle_Pivot_Up_Down_Current_Angle;
int LEFT_ANKLE_PIVOT_UP_DOWN_MIN = 70;
int LEFT_ANKLE_PIVOT_UP_DOWN_MAX = 120;



volatile bool LEFT_ANKLE_PIVOT_UP_DOWN_MIN_STOP = false;
volatile bool LEFT_ANKLE_PIVOT_UP_DOWN_MAX_STOP = false;

volatile bool LEFT_ANKLE_PIVOT_UP_STOPPED = false;
volatile bool LEFT_ANKLE_PIVOT_DOWN_STOPPED = false;
volatile bool LEFT_ANKLE_PIVOT_UP_RUNNING = false;
volatile bool LEFT_ANKLE_PIVOT_DOWN_RUNNING = false;


int Left_Ankle_Pivot_Up_Down_Angle_To_Go_To;
int Left_Ankle_Pivot_Up_Down_Angle_Speed;


int Left_Ankle_Pivot_Up_Down_Offset = 10;
int Left_Ankle_Pivot_Up_Down_Offset1 = 5;


//________________________________________________________________________________
//          LEFT LEG KNEE BEND & STRAIGHGT ANALOG REFRENCE AND DECLARATION

#define Analog_Left_Knee_Bend_Straight_Actual A10
int ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT  = 0;
int Left_Knee_Bend_Straight_Current_Angle;
int LEFT_KNEE_BEND_STRAIGHT_MIN = 40;
int LEFT_KNEE_BEND_STRAIGHT_MAX = 130;



volatile bool LEFT_KNEE_BEND_STRAIGHT_MIN_STOP = false;
volatile bool LEFT_KNEE_BEND_STRAIGHT_MAX_STOP = false;

volatile bool LEFT_KNEE_STRAIGHT_STOPPED = false;
volatile bool LEFT_KNEE_BEND_STOPPED = false;
volatile bool LEFT_KNEE_STRAIGHT_RUNNING = false;
volatile bool LEFT_KNEE_BEND_RUNNING = false;


int Left_Knee_Bend_Straight_Angle_To_Go_To;
int Left_Knee_Bend_Straight_Angle_Speed;


int Left_Knee_Bend_Straight_Offset = 10;
int Left_Knee_Bend_Straight_Offset1 = 5;


//________________________________________________________________________________
//          LEFT LEG HIP BEND & STRAIGHT ANALOG REFRENCE AND DECLARATION

#define Analog_Left_Hip_Bend_Back_Actual A11
int ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT  = 0;
int Left_Hip_Bend_Back_Current_Angle;
int LEFT_HIP_BEND_BACK_MIN = 40;
int LEFT_HIP_BEND_BACK_MAX = 130;



volatile bool LEFT_HIP_BEND_BACK_MIN_STOP = false;
volatile bool LEFT_HIP_BEND_BACK_MAX_STOP = false;

volatile bool LEFT_HIP_BACK_STOPPED = false;
volatile bool LEFT_HIP_BEND_STOPPED = false;
volatile bool LEFT_HIP_BACK_RUNNING = false;
volatile bool LEFT_HIP_BEND_RUNNING = false;


int Left_Hip_Bend_Back_Angle_To_Go_To;
int Left_Hip_Bend_Back_Angle_Speed;


int Left_Hip_Bend_Back_Offset = 10;
int Left_Hip_Bend_Back_Offset1 = 5;


//________________________________________________________________________________
//          LEFT LEG HIP IN & OUT ANALOG REFRENCE AND DECLARATION

#define Analog_Left_Hip_Pivot_In_Out_Actual A12
int ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT  = 0;
int Left_Hip_Pivot_In_Out_Current_Angle;
int LEFT_HIP_PIVOT_IN_OUT_MIN = 40;
int LEFT_HIP_PIVOT_IN_OUT_MAX = 130;


volatile bool LEFT_HIP_PIVOT_IN_OUT_MIN_STOP = false;
volatile bool LEFT_HIP_PIVOT_IN_OUT_MAX_STOP = false;

volatile bool LEFT_HIP_PIVOT_IN_STOPPED = false;
volatile bool LEFT_HIP_PIVOT_OUT_STOPPED = false;
volatile bool LEFT_HIP_PIVOT_IN_RUNNING = false;
volatile bool LEFT_HIP_PIVOT_OUT_RUNNING = false;


int Left_Hip_Pivot_In_Out_Angle_To_Go_To;
int Left_Hip_Pivot_In_Out_Angle_Speed;


int Left_Hip_Pivot_In_Out_Offset = 10;
int Left_Hip_Pivot_In_Out_Offset1 = 5;

//________________________________________________________________________________
//          LEFT LEG HIP IN & OUT ANALOG REFRENCE AND DECLARATION

#define Analog_Left_Hip_Pivot_Left_Right_Actual A13
int ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT  = 0;
int Left_Hip_Pivot_Left_Right_Current_Angle;
int LEFT_HIP_PIVOT_LEFT_RIGHT_MIN = 40;
int LEFT_HIP_PIVOT_LEFT_RIGHT_MAX = 130;



volatile bool LEFT_HIP_PIVOT_LEFT_RIGHT_MIN_STOP = false;
volatile bool LEFT_HIP_PIVOT_LEFT_RIGHT_MAX_STOP = false;

volatile bool LEFT_HIP_PIVOT_LEFT_STOPPED = false;
volatile bool LEFT_HIP_PIVOT_RIGHT_STOPPED = false;
volatile bool LEFT_HIP_PIVOT_LEFT_RUNNING = false;
volatile bool LEFT_HIP_PIVOT_RIGHT_RUNNING = false;


int Left_Hip_Pivot_Left_Right_Angle_To_Go_To;
int Left_Hip_Pivot_Left_Right_Angle_Speed;


int Left_Hip_Pivot_Left_Right_Offset = 10;
int Left_Hip_Pivot_Left_Right_Offset1 = 5;


////___________________________________________________________________________________________
//#########################################################################################################################################
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________


//***********************************************
//            SERIAL PRINT TIMER

unsigned long SerialPrintTime = 50;
unsigned long SerialPrintStartTime;
unsigned long SerialPrintProgress;
unsigned long SerialPrintResetTime = 1000;

int SerialPrintState;

//***********************************************

//***********************************************
//            HEARTBEAT TIMER

unsigned long HeartbeatLEDTime = 50;
unsigned long HeartbeatLEDStartTime;
unsigned long HeartbeatLEDProgress;
unsigned long HeartbeatLEDResetTime = 1000;

int HeartbeatLEDState;

//***********************************************      
//***********************************************
//            MENU 0 FLIP FLOP TIMER

unsigned long Menu_Flip_Flop_Time = 3000;
unsigned long Menu_Flip_Flop_StartTime;
unsigned long Menu_Flip_Flop_Progress;
unsigned long Menu_Flip_Flop_ResetTime = 6000;

int Menu_Flip_Flop_State;

//*********************************************** 
//***********************************************
//            LEFT ANKLE LEFT RIGHT SPEED TIMER

unsigned long Left_Ankle_Left_Right_Speed_Time = 200;
//unsigned long Left_Ankle_Left_Right_Speed_Time = Left_Ankle_Left_Right_Timer_Speed;
unsigned long Left_Ankle_Left_Right_Speed_StartTime;
unsigned long Left_Ankle_Left_Right_Speed_Progress;
unsigned long Left_Ankle_Left_Right_Speed_ResetTime = 205;
//unsigned long Left_Ankle_Left_Right_Speed_ResetTime = Left_Ankle_Left_Right_Timer_Speed + 5;

int Left_Ankle_Left_Right_Speed_State;

//***********************************************               
//***********************************************
//           SERIAL PRINT DELAY TIMER

void serialprintTimer() {

  SerialPrintProgress = millis() - SerialPrintStartTime;     // Servo Head Progress

  if (SerialPrintProgress <= SerialPrintTime) {
    SerialPrintState = HIGH;
    digitalWrite(HeartbeatLED, HIGH);
  }

  if (SerialPrintProgress >= SerialPrintTime) {
    SerialPrintState = LOW;
    digitalWrite(HeartbeatLED, LOW);    
  }

  if (SerialPrintProgress >= SerialPrintResetTime) {
    SerialPrintStartTime = millis();
  }
}




//***********************************************
//           HEART BEAT DELAY TIMER

void HeartbeatLEDTimer() {

  HeartbeatLEDProgress = millis() - HeartbeatLEDStartTime;     // Servo Head Progress

  if (HeartbeatLEDProgress <= HeartbeatLEDTime) {
    HeartbeatLEDState = HIGH;
//    digitalWrite(HeartbeatLED, HIGH);
  }

  if (HeartbeatLEDProgress >= HeartbeatLEDTime) {
    HeartbeatLEDState = LOW;
//    digitalWrite(HeartbeatLED, LOW);    
  }

  if (HeartbeatLEDProgress >= HeartbeatLEDResetTime) {
    HeartbeatLEDStartTime = millis();
  }
}


//***********************************************
//           MENU 0 FLIP FLOP DELAY TIMER

void Menu_Flip_Flop_Timer() {

  Menu_Flip_Flop_Progress = millis() - Menu_Flip_Flop_StartTime;     // Servo Head Progress

  if (Menu_Flip_Flop_Progress <= Menu_Flip_Flop_Time) {
    Menu_Flip_Flop_State = HIGH;
  }

  if (Menu_Flip_Flop_Progress >= Menu_Flip_Flop_Time) {
    Menu_Flip_Flop_State = LOW;
  }

  if (Menu_Flip_Flop_Progress >= Menu_Flip_Flop_ResetTime) {
    Menu_Flip_Flop_StartTime = millis();
  }
}

//***********************************************
//            LEFT ANKLE LEFT RIGHT SPEED TIMER

void Left_Ankle_Left_Right_Speed_Timer() {

  Left_Ankle_Left_Right_Speed_Progress = millis() - Left_Ankle_Left_Right_Speed_StartTime;     // Servo Head Progress

  if (Left_Ankle_Left_Right_Speed_Progress <= Left_Ankle_Left_Right_Speed_Time) {
    Left_Ankle_Left_Right_Speed_State = LOW;
  }

  if (Left_Ankle_Left_Right_Speed_Progress >= Left_Ankle_Left_Right_Speed_Time) {
    Left_Ankle_Left_Right_Speed_State = HIGH;
  }

  if (Left_Ankle_Left_Right_Speed_Progress >= Left_Ankle_Left_Right_Speed_ResetTime) {
    Left_Ankle_Left_Right_Speed_StartTime = millis();
  }
}


//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void setup() {
 
  Serial.begin(115200);
  Serial.println("Robot System has Started...");
  Serial.println("Please ensure that the POWER switch is ON.");

  // set the data rate for the SoftwareSerial port
//  MySerial.begin(9600);
//  MySerial.println("Hello, Its me, the Robot?");

//delay(1000);

pinMode(HeartbeatLED, OUTPUT);
HeartbeatLEDStartTime = millis();
Menu_Flip_Flop_StartTime = millis();
//Left_Ankle_Left_Right_Speed_StartTime = micros();
Left_Ankle_Left_Right_Speed_StartTime = millis();


//***********************************************      
//***********************************************
//           LEFT LEG

pinMode(Left_Ankle_Pivot_Left_Right_MotorPin1, OUTPUT);
pinMode(Left_Ankle_Pivot_Left_Right_MotorPin2, OUTPUT);

pinMode(Left_Ankle_Pivot_Up_Down_MotorPin1, OUTPUT);
pinMode(Left_Ankle_Pivot_Up_Down_MotorPin2, OUTPUT);

pinMode(Left_Knee_Bend_Straight_MotorPin1, OUTPUT);
pinMode(Left_Knee_Bend_Straight_MotorPin2, OUTPUT);

pinMode(Left_Hip_Bend_Back_MotorPin1, OUTPUT);
pinMode(Left_Hip_Bend_Back_MotorPin2, OUTPUT);

pinMode(Left_Hip_Pivot_Left_Right_MotorPin1, OUTPUT);
pinMode(Left_Hip_Pivot_Left_Right_MotorPin2, OUTPUT);

pinMode(Left_Hip_Pivot_In_Out_MotorPin1, OUTPUT);
pinMode(Left_Hip_Pivot_In_Out_MotorPin2, OUTPUT);

//pinMode(Left_Heel_Switch, INPUT_PULLUP);
//pinMode(Left_Big_Toe_Switch, INPUT_PULLUP);
//pinMode(Left_Small_Toe_Switch, INPUT_PULLUP);
//pinMode(Left_Big_Toe_Bump_Switch, INPUT_PULLUP);
//pinMode(Left_Small_Toe_Bump_Switch, INPUT_PULLUP);


//***********************************************      
//***********************************************
//           RIGHT LEG


pinMode(Right_Ankle_Pivot_Left_Right_MotorPin1, OUTPUT);
pinMode(Right_Ankle_Pivot_Left_Right_MotorPin2, OUTPUT);

pinMode(Right_Ankle_Pivot_Up_Down_MotorPin1, OUTPUT);
pinMode(Right_Ankle_Pivot_Up_Down_MotorPin2, OUTPUT);

pinMode(Right_Knee_Bend_Straight_MotorPin1, OUTPUT);
pinMode(Right_Knee_Bend_Straight_MotorPin2, OUTPUT);

pinMode(Right_Hip_Pivot_Forward_Backward_MotorPin1, OUTPUT);
pinMode(Right_Hip_Pivot_Forward_Backward_MotorPin2, OUTPUT);

pinMode(Right_Hip_Pivot_Left_Right_MotorPin1, OUTPUT);
pinMode(Right_Hip_Pivot_Left_Right_MotorPin2, OUTPUT);

pinMode(Right_Hip_Pivot_In_Out_MotorPin1, OUTPUT);
pinMode(Right_Hip_Pivot_In_Out_MotorPin2, OUTPUT);

//
//pinMode(Right_Heel_Switch, INPUT_PULLUP);
//pinMode(Right_Big_Toe_Switch, INPUT_PULLUP);
//pinMode(Right_Small_Toe_Switch, INPUT_PULLUP);
//pinMode(Right_Big_Toe_Bump_Switch, INPUT_PULLUP);
//pinMode(Right_Small_Toe_Bump_Switch, INPUT_PULLUP);


//***********************************************      
//***********************************************
//           REMOTE CONTROLL

pinMode(Remote_On_Off_Switch, INPUT_PULLUP);
pinMode(Joy_Switch_Button, INPUT);
pinMode(Menu_Up_Button, INPUT_PULLUP);
pinMode(Menu_Down_Button, INPUT_PULLUP);
pinMode(Menu_Enter_Button, INPUT_PULLUP);
pinMode(Menu_Exit_Button, INPUT_PULLUP);


//**********************************************
//**********************************************
//            MOTORS ON / OFF SWITCH

pinMode(Motors_On_Off_Switch, INPUT_PULLUP);

//**********************************************
//**********************************************

//


//  if(!myMPU9250.init()){
//    Serial.println("MPU9250 does not respond");
//  }
//  else{
//    Serial.println("MPU9250 is connected");
//  }

  // Print a message to the LCD.

  lcd.init();
  lcd.backlight();
//  lcd.setCursor(0,0);
//  lcd.print("Initializing.");
//  delay(500);
//  lcd.clear();
//  lcd.print("Initializing..");
//  delay(500);
//  lcd.clear();
//  lcd.print("Initializing...");
//  delay(500);
//  lcd.clear();
//  lcd.print("Initializing....");
//  delay(500);
//  lcd.clear();
    
//3   if(!myMPU9250.init()){
//  lcd.setCursor(0,0);
//  lcd.print("Gyroscopic System");
//  lcd.setCursor(0,1);
//  lcd.print("OFFLINE");
//  Serial.println("Gyroscopic System OFFLINE");
//  }
//  else{
//  lcd.setCursor(0,0);
//  lcd.print("Gyroscopic System");
//  lcd.setCursor(0,1);
//  lcd.print("ONLINE");
//  Serial.println("Gyroscopic System ONLINE");
//  }
//
//
//  Serial.println("Position you MPU9250 flat and don't move it - calibrating...");
//  delay(1000);
//  myMPU9250.autoOffsets();
//  Serial.println("Done!");
//  
//  myMPU9250.setAccRange(MPU9250_ACC_RANGE_2G);
// 
//  myMPU9250.enableAccDLPF(true);
//
// /*  Digital low pass filter (DLPF) for the accelerometer (if DLPF enabled) 
//   *  MPU9250_DPLF_0, MPU9250_DPLF_2, ...... MPU9250_DPLF_7 
//   *   DLPF     Bandwidth [Hz]      Delay [ms]    Output rate [kHz]
//   *     0           460               1.94           1
//   *     1           184               5.80           1
//   *     2            92               7.80           1
//   *     3            41              11.80           1
//   *     4            20              19.80           1
//   *     5            10              35.70           1
//   *     6             5              66.96           1
//   *     7           460               1.94           1
//   */
//  myMPU9250.setAccDLPF(MPU9250_DLPF_6);   
//  lcd.clear();
  
//delay(1000);


}








//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************


void loop() {

//SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
//DigitalRead_Pins();
//Check_All_Analog_Input_Signals();

Robot_Procedures();

}


//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************



void Robot_Procedures(){
  
Left_Ankle_Left_Right_Speed_Timer();

SerialPrint();
HeartbeatLEDTimer();
GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

Check_Motors_Cut_Off_Switch();

if (Remote_On_Off_SwitchState == HIGH){
  
Test_Remote_Inputs_Signals();

//Left_Ankle_Pivot_Left_Right_Testing();
//Right_Ankle_Pivot_Left_Right_Testing();
//
//Left_Ankle_Pivot_Up_Down_Testing();
//Right_Ankle_Pivot_Up_Down_Testing();
//
//Left_Knee_Bend_Straight_Testing();
//Right_Knee_Bend_Straight_Testing();
//
//Left_Hip_Bend_Back_Testing();
//Right_Hip_Bend_Back_Testing();
//
//Left_Hip_Pivot_Left_Right_Testing();
//Right_Hip_Pivot_Left_Right_Testing();
//
//Left_Hip_Pivot_In_Out_Testing();
//Right_Hip_Pivot_In_Out_Testing();
//
//Menu_Control();

}


if (Stop_Robot == true){
DigitalRead_Pins();
Check_All_Analog_Input_Signals();
  
Check_Motors_Cut_Off_Switch();
Stop_All_Motors();  

}

else if  (Run_Robot == true){

//Left_Ankle_Pivot_Left_Right_Testing();
//Right_Ankle_Pivot_Left_Right_Testing();

//Left_Ankle_Pivot_Up_Down_Testing();
//Right_Ankle_Pivot_Up_Down_Testing();

//Left_Knee_Bend_Straight_Testing();
//Right_Knee_Bend_Straight_Testing();

//Left_Hip_Bend_Back_Testing();
//Right_Hip_Bend_Back_Testing();

//Left_Hip_Pivot_Left_Right_Testing();
//Right_Hip_Pivot_Left_Right_Testing();

//Left_Hip_Pivot_In_Out_Testing();
Right_Hip_Pivot_In_Out_Testing();

//Menu_Control();


}

}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Check_Motors_Cut_Off_Switch(){
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


if (Motors_On_Off_Switch_State == LOW){
  Stop_Robot = false;
  Run_Robot = true;
} 
else if (Motors_On_Off_Switch_State == HIGH){
  Stop_Robot = true;
  Run_Robot = false;  
  Stop_All_Motors();

}
}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

void Stop_All_Motors(){
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin1, LOW);
digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin2, LOW);

digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, LOW);
digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin2, LOW);

digitalWrite(Left_Knee_Bend_Straight_MotorPin1, LOW);
digitalWrite(Left_Knee_Bend_Straight_MotorPin2, LOW);

digitalWrite(Left_Hip_Bend_Back_MotorPin1, LOW);
digitalWrite(Left_Hip_Bend_Back_MotorPin2, LOW);

digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, LOW);
digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin2, LOW);
analogWrite(Left_Hip_Pivot_Left_Right_MotorENA, 0);



digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, LOW);
digitalWrite(Left_Hip_Pivot_In_Out_MotorPin2, LOW);
analogWrite(Left_Hip_Pivot_In_Out_MotorENA, 0);


//***********************************************      
//***********************************************
//           RIGHT LEG


digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, LOW);
digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin2, LOW);

digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, LOW);
digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin2, LOW);

digitalWrite(Right_Knee_Bend_Straight_MotorPin1, LOW);
digitalWrite(Right_Knee_Bend_Straight_MotorPin2, LOW);

digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, LOW);
digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin2, LOW);

digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, LOW);
digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin2, LOW);
digitalWrite(Right_Hip_Pivot_Left_Right_MotorENA, LOW);

digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, LOW);
digitalWrite(Right_Hip_Pivot_In_Out_MotorPin2, LOW);
digitalWrite(Right_Hip_Pivot_In_Out_MotorENA, LOW);

}


void DigitalRead_Pins(){



//**********************************************************
//            MOTORS ON / OFF SWITCH

Motors_On_Off_Switch_State = digitalRead(Motors_On_Off_Switch);

////**********************************************************
////          LEFT FOOT SWITCHES
//
//Left_Heel_Switch_State = digitalRead(Left_Heel_Switch);
//Left_Big_Toe_Switch_State = digitalRead(Left_Big_Toe_Switch);
//Left_Small_Toe_Switch_State = digitalRead(Left_Small_Toe_Switch);
//Left_Big_Toe_Bump_Switch_State = digitalRead(Left_Big_Toe_Bump_Switch);
//Left_Small_Toe_Bump_Switch_State = digitalRead(Left_Small_Toe_Bump_Switch);
//
////**********************************************************
////          RIGHT FOOT SWITCHES
//
//Right_Heel_Switch_State = digitalRead(Right_Heel_Switch);
//Right_Big_Toe_Switch_State = digitalRead(Right_Big_Toe_Switch);
//Right_Small_Toe_Switch_State = digitalRead(Right_Small_Toe_Switch);
//Right_Big_Toe_Bump_Switch_State = digitalRead(Right_Big_Toe_Bump_Switch);
//Right_Small_Toe_Bump_Switch_State = digitalRead(Right_Small_Toe_Bump_Switch);

//**********************************************************
//            REMOTE BUTTONS

Remote_On_Off_SwitchState = digitalRead(Remote_On_Off_Switch);
Joy_Switch_ButtonState = digitalRead(Joy_Switch_Button);
Menu_Up_ButtonState = digitalRead(Menu_Up_Button);
Menu_Down_ButtonState = digitalRead(Menu_Down_Button);
Menu_Enter_ButtonState = digitalRead(Menu_Enter_Button);
Menu_Exit_ButtonState = digitalRead(Menu_Exit_Button);

}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************


void Check_All_Analog_Input_Signals(){


    // Read new position
  ANALOG_IN_X_JOY_SETPOINT = analogRead(Analog_In_X_Joy_setpoint);
  ANALOG_IN_X_JOY_SETPOINT = map(ANALOG_IN_X_JOY_SETPOINT, 0, 1023, 180, 0);
  Analog_In_X_Joy_Current_setpoint = ANALOG_IN_X_JOY_SETPOINT;
  
//  Current_Angle = ANALOG_IN_X_JOY_SETPOINT;

//  ANALOG_IN_Y_JOY_SETPOINT = analogRead(Analog_In_Y_Joy_setpoint);
//  ANALOG_IN_Y_JOY_SETPOINT = map(ANALOG_IN_Y_JOY_SETPOINT, 0, 1023, 180, 0);
//  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;


  New_Ankle_Pivot_Left_Right_setpoint = analogRead(Analog_In_Y_Joy_setpoint);
  New_Ankle_Pivot_Left_Right_setpoint = map(New_Ankle_Pivot_Left_Right_setpoint, 0, 1023, 120, 60);
  ANALOG_IN_Y_JOY_SETPOINT = New_Ankle_Pivot_Left_Right_setpoint;
  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;



  New_Left_Hip_Pivot_In_Out_setpoint = analogRead(Analog_In_Y_Joy_setpoint);
  New_Left_Hip_Pivot_In_Out_setpoint = map(New_Left_Hip_Pivot_In_Out_setpoint, 0, 1023, 160, 20);
  ANALOG_IN_Y_JOY_SETPOINT = New_Left_Hip_Pivot_In_Out_setpoint;
  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;


  New_Right_Hip_Pivot_In_Out_setpoint = analogRead(Analog_In_Y_Joy_setpoint);
  New_Right_Hip_Pivot_In_Out_setpoint = map(New_Right_Hip_Pivot_In_Out_setpoint, 0, 1023, 170, 10);
  ANALOG_IN_Y_JOY_SETPOINT = New_Right_Hip_Pivot_In_Out_setpoint;
  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;







  ANALOG_IN_SLIDER_SETPOINT = analogRead(Analog_In_Slider_setpoint);
  ANALOG_IN_SLIDER_SETPOINT = map(ANALOG_IN_SLIDER_SETPOINT, 0, 1023, 180, 0);
  Analog_In_Slider_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;

  ANALOG_IN_POT_SETPOINT = analogRead(Analog_In_Pot_setpoint);
  ANALOG_IN_POT_SETPOINT = map(ANALOG_IN_POT_SETPOINT, 0, 1023, 0, 180);
  Analog_In_Pot_Current_setpoint = ANALOG_IN_POT_SETPOINT;


  ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT = analogRead(Analog_Left_Ankle_Left_Right_Actual);
  ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT = map(ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT, 1023, 0, 180, 0);
//  Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Left_Ankle_Pivot_Left_Right_Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT;

  ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT = analogRead(Analog_Right_Ankle_Left_Right_Actual);
  ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT = map(ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Right_Ankle_Pivot_Left_Right_Current_Angle = ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT;



  ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = analogRead(Analog_Left_Ankle_Pivot_Up_Down_Actual);
  ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = map(ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
  Left_Ankle_Pivot_Left_Right_Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;

  ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = analogRead(Analog_Right_Ankle_Pivot_Up_Down_Actual);
  ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = map(ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT, 1023, 0, 180, 0);
//  Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
  Right_Ankle_Pivot_Left_Right_Current_Angle = ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;


  ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT = analogRead(Analog_Left_Knee_Bend_Straight_Actual);
  ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT = map(ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
  Left_Knee_Bend_Straight_Current_Angle = ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;

  ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT = analogRead(Analog_Right_Knee_Bend_Straight_Actual);
  ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT = map(ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
  Right_Knee_Bend_Straight_Current_Angle = ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT;

  ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT = analogRead(Analog_Left_Hip_Bend_Back_Actual);
  ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT = map(ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT, 0, 1023, 180, 0);
//  Current_Angle = ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;
  Left_Hip_Bend_Back_Current_Angle = ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;

  ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT = analogRead(Analog_Right_Hip_Bend_Back_Actual);
  ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT = map(ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT, 1023, 0, 180, 0);
//  Current_Angle = ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;
  Right_Hip_Bend_Back_Current_Angle = ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT;

  ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = analogRead(Analog_Left_Hip_Pivot_Left_Right_Actual);
  ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = map(ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Left_Hip_Pivot_Left_Right_Current_Angle = ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;

  ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = analogRead(Analog_Right_Hip_Pivot_Left_Right_Actual);
  ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = map(ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Right_Hip_Pivot_Left_Right_Current_Angle = ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;

  ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT = analogRead(Analog_Left_Hip_Pivot_In_Out_Actual);
  ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT = map(ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
  Left_Hip_Pivot_In_Out_Current_Angle = ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT;

  ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT = analogRead(Analog_Right_Hip_Pivot_In_Out_Actual);
  ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT = map(ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
  Right_Hip_Pivot_In_Out_Current_Angle = ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
  
}


//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

//*****************************************************************************************************************************************
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void GyroScope(){

//SerialPrint();
//
//  xyzFloat gValue = myMPU9250.getGValues();
//  xyzFloat angle = myMPU9250.getAngles();
//
//  
//
//
//if (SerialPrintState == HIGH){
//
///* For g-values the corrected raws are used */
//
////  Serial.print("g-x      = ");
////  Serial.print(gValue.x);
////  Serial.print("  |  g-y      = ");
////  Serial.print(gValue.y);
////  Serial.print("  |  g-z      = ");
////  Serial.println(gValue.z);
//
///* Angles are also based on the corrected raws. Angles are simply calculated by
//   angle = arcsin(g Value) */
//  Serial.print("Angle x  = ");
//  Serial.print(angle.x);
//  Serial.print("  |  Angle y  = ");
//  Serial.print(angle.y);
//  Serial.print("  |  Angle z  = ");
//  Serial.println(angle.z);
//
//  Serial.print("Orientation of the module: ");
//  Serial.println(myMPU9250.getOrientationAsString());
//
//  Serial.println();
//  
//}
  
}





//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Left_Ankle_Pivot_Left_Right_Testing(){
  
//Left_Ankle_Left_Right_Speed_Timer();

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  lcd.setCursor(0,0);
  lcd.print("Set point Y: ");
  lcd.print(ANALOG_IN_Y_JOY_SETPOINT);
  lcd.setCursor(0,1);
  lcd.print("S: ");
  lcd.print("L: ");
  lcd.print(ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  lcd.print(" ");
  lcd.print("R: ");
  lcd.print(ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  lcd.print("  ");

  Left_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();


//if (Left_Ankle_Left_Right_Speed_State == LOW){
// Left_Ankle_Pivot_Left_Right_Stop();
//// delay(200);
//}

if ((ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_Y_JOY_SETPOINT - 5) && (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_Y_JOY_SETPOINT + 5)){
Left_Ankle_Left_Right_Speed_Timer();

//if (Left_Ankle_Left_Right_Speed_State == LOW){
 Left_Ankle_Pivot_Left_Right_Stop();
//// delay(200);
//}

}

else{

if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 >= LEFT_ANKLE_LEFT_RIGHT_MIN + 10){
if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT >= ANALOG_IN_Y_JOY_SETPOINT){

 Left_Ankle_Pivot_Left();
}


// if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT  >= ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT ){
//
//Left_Ankle_Pivot_Left();
// }

}
 

if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2 <= LEFT_ANKLE_LEFT_RIGHT_MAX - 10){
if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT <= ANALOG_IN_Y_JOY_SETPOINT){

 Left_Ankle_Pivot_Right();
  
}
 
// if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT  <= ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT){
// 
//Left_Ankle_Pivot_Right();
// }
 
}

}
}


//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************


void Right_Ankle_Pivot_Left_Right_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  lcd.setCursor(0,1);
  lcd.print("Set point Y: ");
  lcd.print(ANALOG_IN_Y_JOY_SETPOINT);
  lcd.print(" ");
  lcd.setCursor(0,2);
  lcd.print("S: ");
  lcd.print("L: ");
  lcd.print(ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  lcd.print(" ");
  lcd.print("R: ");
  lcd.print(ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  lcd.print("  ");

Right_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();


if ((ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_Y_JOY_SETPOINT - 5) && (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_Y_JOY_SETPOINT + 5)){

 Right_Ankle_Pivot_Stop();
  
}

else{

if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 >= RIGHT_ANKLE_LEFT_RIGHT_MIN + 10){
if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2  >= ANALOG_IN_Y_JOY_SETPOINT){
  
 Right_Ankle_Pivot_Left();

}

// if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT >= ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT){
//
// Right_Ankle_Pivot_Left();
// }

}


if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2 <= RIGHT_ANKLE_LEFT_RIGHT_MAX - 10){
if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 <= ANALOG_IN_Y_JOY_SETPOINT){
  
 Right_Ankle_Pivot_Right();
  
}
 
// if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT <= ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT){
// 
//Right_Ankle_Pivot_Right();
// }
// 
//}

}

}

}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Ankle_Pivot_Up_Down_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  ////lcd.setCursor(0,2);
  ////lcd.print("Set point X: ");
  ////lcd.print(ANALOG_IN_X_JOY_SETPOINT);
  ////lcd.print(" ");
  ////lcd.setCursor(0,3);
  ////lcd.print("L: ");
  ////lcd.print(ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT);
  ////lcd.print(" ");
//  ////lcd.print("R: ");
//  //lcd.print(ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT);
//  //lcd.print("  ");

  Left_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();


if ((ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 >= ANALOG_IN_X_JOY_SETPOINT - 5) && (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5  <= ANALOG_IN_X_JOY_SETPOINT + 5)){

 Left_Ankle_Pivot_Up_Down_Stop();
  
}

else{

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 2 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 2){
if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 2  >= ANALOG_IN_X_JOY_SETPOINT){

 Left_Ankle_Pivot_Up();

}


// if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT  >= ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT ){
//
//Left_Ankle_Pivot_Up();
// }

}
 

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 2 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 2){
if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 2 <= ANALOG_IN_X_JOY_SETPOINT){

 Left_Ankle_Pivot_Down();
  
}
 
// if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT  <= ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT){
// 
//Left_Ankle_Pivot_Down();
// }
 
}

}
}

//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Ankle_Pivot_Up_Down_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


  //lcd.setCursor(0,2);
  //lcd.print("Set point X: ");
  //lcd.print(ANALOG_IN_X_JOY_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(9,3);
//  //lcd.print("L: ");
//  //lcd.print(ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT);
//  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT);
  //lcd.print("  ");


Right_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();


if ((ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 >= ANALOG_IN_X_JOY_SETPOINT - 5) && (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5  <= ANALOG_IN_X_JOY_SETPOINT + 5)){

 Right_Ankle_Pivot_Up_Down_Stop();
  
}

else{

if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 2 >= RIGHT_ANKLE_PIVOT_UP_DOWN_MIN + 2){
if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 2  >= ANALOG_IN_X_JOY_SETPOINT){
  
 Right_Ankle_Pivot_Up();

}

// if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT >= ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT){
//
// Right_Ankle_Pivot_Up();
// }

}


if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 2 <= RIGHT_ANKLE_PIVOT_UP_DOWN_MAX - 2){
if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 2 <= ANALOG_IN_X_JOY_SETPOINT){
  
 Right_Ankle_Pivot_Down();
  
}
 
// if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT <= ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT){
// 
//Right_Ankle_Pivot_Down();
// }
 
}

}

}


//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Knee_Bend_Straight_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  //lcd.setCursor(0,1);
  //lcd.print("Set Slider : ");
  //lcd.print(ANALOG_IN_SLIDER_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT);
  //lcd.print("  ");

  Left_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check();


if ((ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 Left_Knee_Bend_Straight_Stop();
  
}

else{

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 2 >= LEFT_KNEE_BEND_STRAIGHT_MIN + 2){
if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){

 Left_Knee_Bend();

}


// if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT  >= ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT ){
//
//Left_Knee_Bend();
// }

}
 

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 2 <= LEFT_KNEE_BEND_STRAIGHT_MAX - 2){
if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){

 Left_Knee_Straight();
  
}
 
// if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT  <= ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT){
// 
//Left_Knee_Straight();
// }
 
}

}
}

//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Knee_Bend_Straight_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


  //lcd.setCursor(0,1);
  //lcd.print("Set Slider: ");
  //lcd.print(ANALOG_IN_SLIDER_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT);
  //lcd.print("  ");


Right_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();


if ((ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 Right_Knee_Bend_Straight_Stop();
  
}

else{

if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 2 >= RIGHT_KNEE_BEND_STRAIGHT_MIN + 2){
if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){
  
 Right_Knee_Bend();

}

// if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT >= ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT){
//
// Right_Knee_Bend();
// }

}


if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 2 <= RIGHT_KNEE_BEND_STRAIGHT_MAX - 2){
if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){
  
 Right_Knee_Straight();
  
}
 
// if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT <= ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT){
// 
//Right_Knee_Straight();
// }
 
}

}

}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Hip_Bend_Back_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  //lcd.setCursor(0,1);
  //lcd.print("Set Slider : ");
  //lcd.print(ANALOG_IN_SLIDER_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT);
  //lcd.print("  ");

  Left_Hip_Bend_Back_AnalogSignals_and_EndStops_Check();


if ((ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 5 >= ANALOG_IN_POT_SETPOINT - 5) && (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 5  <= ANALOG_IN_POT_SETPOINT + 5)){

 Left_Hip_Bend_Back_Stop();
  
}

else{

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 2 >= LEFT_HIP_BEND_BACK_MIN + 2){
if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 2  >= ANALOG_IN_POT_SETPOINT){

 Left_Hip_Bend();

}


// if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT  >= ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT ){
//
//Left_Hip_Bend();
// }

}
 

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 2 <= LEFT_HIP_BEND_BACK_MAX - 2){
if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 2 <= ANALOG_IN_POT_SETPOINT){

 Left_Hip_Back();
  
}
 
// if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT  <= ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT){
// 
//Left_Hip_Back();
// }
 
}

}
}

//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Bend_Back_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


  //lcd.setCursor(0,1);
  //lcd.print("Set Sider : ");
  //lcd.print(ANALOG_IN_SLIDER_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT);
  //lcd.print("  ");


Right_Hip_Bend_Back_AnalogSignals_and_EndStops_Check();


if ((ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 Right_Hip_Bend_Back_Stop();
  
}

else{

if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 2 >= RIGHT_HIP_BEND_BACK_MIN + 2){
if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){
  
 Right_Knee_Bend();

}

// if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT >= ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT){
//
// Right_Knee_Bend();
// }

}


if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 2 <= RIGHT_HIP_BEND_BACK_MAX - 2){
if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){
  
 Right_Hip_Back();
  
}
 
// if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT <= ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT){
// 
//Right_Hip_Back();
// }
 
}

}

}


//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Hip_Pivot_Left_Right_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  //lcd.setCursor(0,1);
  //lcd.print("Set Pot : ");
  //lcd.print(ANALOG_IN_POT_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  //lcd.print("  ");

  Left_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();


if ((ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_POT_SETPOINT - 5) && (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_POT_SETPOINT + 5)){

 Left_Hip_Pivot_Left_Right_Stop();
  
}

else{

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 >= LEFT_HIP_PIVOT_LEFT_RIGHT_MIN + 2){
if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2  >= ANALOG_IN_POT_SETPOINT){

 Left_Hip_Pivot_Left();

}


// if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT  >= ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT ){
//
//Left_Hip_Pivot_Left();
// }

}
 

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2 <= LEFT_HIP_PIVOT_LEFT_RIGHT_MAX - 2){
if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 <= ANALOG_IN_POT_SETPOINT){

 Left_Hip_Pivot_Right();
  
}
 
// if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT  <= ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT){
// 
//Left_Hip_Pivot_Right();
// }
 
}

}
}

//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Pivot_Left_Right_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


  //lcd.setCursor(0,1);
  //lcd.print("Set Pot: ");
  //lcd.print(ANALOG_IN_POT_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT);
  //lcd.print("  ");


Right_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();


if ((ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_POT_SETPOINT - 5) && (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_POT_SETPOINT + 5)){

 Right_Hip_Pivot_Left_Right_Stop();
  
}

else{

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 >= RIGHT_HIP_PIVOT_LEFT_RIGHT_MIN + 2){
if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2  >= ANALOG_IN_POT_SETPOINT){
  
 Right_Hip_Pivot_Left();

}

// if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT >= ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT){
//
// Right_Hip_Pivot_Left();
// }

}


if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2 <= RIGHT_HIP_PIVOT_LEFT_RIGHT_MAX - 2){
if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 <= ANALOG_IN_POT_SETPOINT){
  
 Right_Hip_Pivot_Right();
  
}
 
// if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT <= ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT){
// 
//Right_Hip_Pivot_Right();
// }
 
}

}

}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Hip_Pivot_In_Out_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


  //lcd.setCursor(0,1);
  //lcd.print("Set point Y: ");
  //lcd.print(ANALOG_IN_Y_JOY_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT);
  //lcd.print("  ");

  Left_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check();


if ((ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 2 >= New_Left_Hip_Pivot_In_Out_setpoint - 2) && (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 2  <= New_Left_Hip_Pivot_In_Out_setpoint + 2)){

 Left_Hip_Pivot_In_Out_Stop();
  
}

else{

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 2 >= LEFT_HIP_PIVOT_IN_OUT_MIN + 2){
if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT >= New_Left_Hip_Pivot_In_Out_setpoint){

 Left_Hip_Pivot_In();

}


// if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT  >= ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT ){
//
//Left_Hip_Pivot_In();
// }

}
 

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 2 <= LEFT_HIP_PIVOT_IN_OUT_MAX - 2){
if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT <= New_Left_Hip_Pivot_In_Out_setpoint){

 Left_Hip_Pivot_Out();
  
}
 
// if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT  <= ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT){
// 
//Left_Hip_Pivot_Out();
// }
 
}

}
}

//*****************************************************************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Pivot_In_Out_Testing(){
  

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


  //lcd.setCursor(0,1);
  //lcd.print("Set point Y: ");
  //lcd.print(ANALOG_IN_Y_JOY_SETPOINT);
  //lcd.print(" ");
  //lcd.setCursor(0,2);
  //lcd.print("L: ");
  //lcd.print(ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT);
  //lcd.print(" ");
  //lcd.print("R: ");
  //lcd.print(ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT);
  //lcd.print("  ");


Right_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check();


if ((ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 2 >= New_Left_Hip_Pivot_In_Out_setpoint - 2) && (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 2  <= New_Left_Hip_Pivot_In_Out_setpoint + 2)){

 Right_Hip_Pivot_In_Out_Stop();
  
}

else{

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 2 >= RIGHT_HIP_PIVOT_IN_OUT_MIN + 2){
if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT >= New_Left_Hip_Pivot_In_Out_setpoint){
  
 Right_Hip_Pivot_In();

}

// if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT >= ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT){
//
// Right_Hip_Pivot_In();
// }

}


if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 2 <= RIGHT_HIP_PIVOT_IN_OUT_MAX - 2){
if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT <= New_Left_Hip_Pivot_In_Out_setpoint){
  
 Right_Hip_Pivot_Out();
  
}
 
// if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT <= ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT){
// 
//Right_Hip_Pivot_Out();
// }
 
}

}

}



//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  Left_Ankle_Left_Right_Angle_To_Go_To = ANALOG_IN_Y_JOY_SETPOINT - ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Left_Ankle_Left_Right_Angle_Speed = map(Left_Ankle_Left_Right_Angle_To_Go_To, 1, 95, 240, 255);
  
  Left_Ankle_Left_Right_Timer_Speed = map(Left_Ankle_Left_Right_Angle_To_Go_To, 0, 180, 400, 1000);

  if (Left_Ankle_Left_Right_Timer_Speed <= -1){
    Left_Ankle_Left_Right_Timer_Speed = (Left_Ankle_Left_Right_Timer_Speed - 20) * -1;
  }else{
    Left_Ankle_Left_Right_Timer_Speed = Left_Ankle_Left_Right_Timer_Speed * 1;
  }
  if (Left_Ankle_Left_Right_Timer_Speed <= 0){
    Left_Ankle_Left_Right_Timer_Speed = 0;
  }
  
  if (Left_Ankle_Left_Right_Timer_Speed >= 405){
    Left_Ankle_Left_Right_Timer_Speed = 405;
  }
  
  
  if (Left_Ankle_Left_Right_Angle_Speed <= -1){
    Left_Ankle_Left_Right_Angle_Speed = (Left_Ankle_Left_Right_Angle_Speed - 20) * -1;
  }else{
    Left_Ankle_Left_Right_Angle_Speed = Left_Ankle_Left_Right_Angle_Speed * 1;
  }
  
  if (Left_Ankle_Left_Right_Angle_Speed <= 0){
    Left_Ankle_Left_Right_Angle_Speed = 0;
  }
  
  if (Left_Ankle_Left_Right_Angle_Speed >= 255){
    Left_Ankle_Left_Right_Angle_Speed = 255;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();
  
  Right_Ankle_Left_Right_Angle_To_Go_To = ANALOG_IN_Y_JOY_SETPOINT - ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Right_Ankle_Left_Right_Angle_Speed = map(Right_Ankle_Left_Right_Angle_To_Go_To, -5, 88, 240, 255);

  if (Right_Ankle_Left_Right_Angle_Speed <= -1){
    Right_Ankle_Left_Right_Angle_Speed = (Right_Ankle_Left_Right_Angle_Speed - 20) * -1;
  }else{
    Right_Ankle_Left_Right_Angle_Speed = Right_Ankle_Left_Right_Angle_Speed * 1;
  }
  
  if (Right_Ankle_Left_Right_Angle_Speed <= 0){
    Right_Ankle_Left_Right_Angle_Speed = 0;
  }
  
  if (Right_Ankle_Left_Right_Angle_Speed >= 255){
    Right_Ankle_Left_Right_Angle_Speed = 255;
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


//    // Read new position
//  ANALOG_IN_X_JOY_SETPOINT = analogRead(Analog_In_X_Joy_setpoint);
//  ANALOG_IN_X_JOY_SETPOINT = map(ANALOG_IN_X_JOY_SETPOINT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_IN_X_JOY_SETPOINT;
//  
//
//  ANALOG_IN_Y_JOY_SETPOINT = analogRead(Analog_In_Y_Joy_setpoint);
//  ANALOG_IN_Y_JOY_SETPOINT = map(ANALOG_IN_Y_JOY_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;
//
//
//  ANALOG_IN_SLIDER_SETPOINT = analogRead(Analog_In_Slider_setpoint);
//  ANALOG_IN_SLIDER_SETPOINT = map(ANALOG_IN_SLIDER_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Slider_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
//  ANALOG_IN_POT_SETPOINT = analogRead(Analog_In_Pot_setpoint);
//  ANALOG_IN_POT_SETPOINT = map(ANALOG_IN_POT_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Pot_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
// 
//
//  ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = analogRead(Analog_Left_Ankle_Pivot_Up_Down_Actual);
//  ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = map(ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
//  Left_Ankle_Pivot_Left_Right_Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
//
//  ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = analogRead(Analog_Right_Ankle_Left_Right_Actual);
//  ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT = map(ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
//  Right_Ankle_Pivot_Left_Right_Current_Angle = ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Left_Ankle_Pivot_Up_Down_Angle_To_Go_To = ANALOG_IN_X_JOY_SETPOINT - ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
  Left_Ankle_Pivot_Up_Down_Angle_Speed = map(Left_Ankle_Pivot_Up_Down_Angle_To_Go_To, 1, 95, 240, 255);
  
  if (Left_Ankle_Pivot_Up_Down_Angle_Speed <= -1){
    Left_Ankle_Pivot_Up_Down_Angle_Speed = (Left_Ankle_Pivot_Up_Down_Angle_Speed - 20) * -1;
  }else{
    Left_Ankle_Pivot_Up_Down_Angle_Speed = Left_Ankle_Pivot_Up_Down_Angle_Speed * 1;
  }
  
  if (Left_Ankle_Pivot_Up_Down_Angle_Speed <= 0){
    Left_Ankle_Pivot_Up_Down_Angle_Speed = 0;
  }
  
  if (Left_Ankle_Pivot_Up_Down_Angle_Speed >= 255){
    Left_Ankle_Pivot_Up_Down_Angle_Speed = 255;
  }


if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 5){
  LEFT_ANKLE_PIVOT_UP_DOWN_MIN_STOP = true;
}
else
{
  LEFT_ANKLE_PIVOT_UP_DOWN_MIN_STOP = false; 
}


if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 5){
  LEFT_ANKLE_PIVOT_UP_DOWN_MAX_STOP = true;  
}
else
{
  LEFT_ANKLE_PIVOT_UP_DOWN_MAX_STOP = false;  
}


  
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  Right_Ankle_Pivot_Up_Down_Angle_To_Go_To = ANALOG_IN_X_JOY_SETPOINT - ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT;
  Right_Ankle_Pivot_Up_Down_Angle_Speed = map(Right_Ankle_Pivot_Up_Down_Angle_To_Go_To, -5, 88, 240, 255);

  if (Right_Ankle_Pivot_Up_Down_Angle_Speed <= -1){
    Right_Ankle_Pivot_Up_Down_Angle_Speed = (Right_Ankle_Pivot_Up_Down_Angle_Speed - 20) * -1;
  }else{
    Right_Ankle_Pivot_Up_Down_Angle_Speed = Right_Ankle_Pivot_Up_Down_Angle_Speed * 1;
  }
  
  if (Right_Ankle_Pivot_Up_Down_Angle_Speed <= 0){
    Right_Ankle_Pivot_Up_Down_Angle_Speed = 0;
  }
  
  if (Right_Ankle_Pivot_Up_Down_Angle_Speed >= 255){
    Right_Ankle_Pivot_Up_Down_Angle_Speed = 255;
  }


if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5 <= RIGHT_ANKLE_PIVOT_UP_DOWN_MIN + 5){
  RIGHT_ANKLE_PIVOT_UP_DOWN_MIN_STOP = true;
}
else
{
  RIGHT_ANKLE_PIVOT_UP_DOWN_MIN_STOP = false; 
}


if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 >= RIGHT_ANKLE_PIVOT_UP_DOWN_MAX - 5){
  RIGHT_ANKLE_PIVOT_UP_DOWN_MAX_STOP = true;  
}
else
{
  RIGHT_ANKLE_PIVOT_UP_DOWN_MAX_STOP = false;  
}


//*********************************************************************************************

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////#################################################################################################################################################################################
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check(){

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

//    // Read new position
//  ANALOG_IN_X_JOY_SETPOINT = analogRead(Analog_In_X_Joy_setpoint);
//  ANALOG_IN_X_JOY_SETPOINT = map(ANALOG_IN_X_JOY_SETPOINT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_IN_X_JOY_SETPOINT;
//  
//
//  ANALOG_IN_Y_JOY_SETPOINT = analogRead(Analog_In_Y_Joy_setpoint);
//  ANALOG_IN_Y_JOY_SETPOINT = map(ANALOG_IN_Y_JOY_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;
//
//
//
//  ANALOG_IN_SLIDER_SETPOINT = analogRead(Analog_In_Slider_setpoint);
//  ANALOG_IN_SLIDER_SETPOINT = map(ANALOG_IN_SLIDER_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Slider_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
//  ANALOG_IN_POT_SETPOINT = analogRead(Analog_In_Pot_setpoint);
//  ANALOG_IN_POT_SETPOINT = map(ANALOG_IN_POT_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Pot_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;

 
//  ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT = analogRead(Analog_Left_Knee_Bend_Straight_Actual);
//  ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT = map(ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
//  Left_Knee_Bend_Straight_Current_Angle = ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
//
//  ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT = analogRead(Analog_Right_Knee_Bend_Straight_Actual);
//  ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT = map(ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
//  Right_Knee_Bend_Straight_Current_Angle = ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Left_Knee_Bend_Straight_Angle_To_Go_To = ANALOG_IN_SLIDER_SETPOINT - ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
  Left_Knee_Bend_Straight_Angle_Speed = map(Left_Knee_Bend_Straight_Angle_To_Go_To, 1, 95, 240, 255);
  
  if (Left_Knee_Bend_Straight_Angle_Speed <= -1){
    Left_Knee_Bend_Straight_Angle_Speed = (Left_Knee_Bend_Straight_Angle_Speed - 20) * -1;
  }else{
    Left_Knee_Bend_Straight_Angle_Speed = Left_Knee_Bend_Straight_Angle_Speed * 1;
  }
  
  if (Left_Knee_Bend_Straight_Angle_Speed <= 0){
    Left_Knee_Bend_Straight_Angle_Speed = 0;
  }
  
  if (Left_Knee_Bend_Straight_Angle_Speed >= 255){
    Left_Knee_Bend_Straight_Angle_Speed = 255;
  }


if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 <= LEFT_KNEE_BEND_STRAIGHT_MIN + 5){
  LEFT_KNEE_BEND_STRAIGHT_MIN_STOP = true;
}
else
{
  LEFT_KNEE_BEND_STRAIGHT_MIN_STOP = false; 
}


if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 >= LEFT_KNEE_BEND_STRAIGHT_MAX - 5){
  LEFT_KNEE_BEND_STRAIGHT_MAX_STOP = true;  
}
else
{
  LEFT_KNEE_BEND_STRAIGHT_MAX_STOP = false;  
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

 
  Right_Knee_Bend_Straight_Angle_To_Go_To = ANALOG_IN_SLIDER_SETPOINT - ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT;
  Right_Knee_Bend_Straight_Angle_Speed = map(Right_Knee_Bend_Straight_Angle_To_Go_To, -5, 88, 240, 255);

  if (Right_Knee_Bend_Straight_Angle_Speed <= -1){
    Right_Knee_Bend_Straight_Angle_Speed = (Right_Knee_Bend_Straight_Angle_Speed - 20) * -1;
  }else{
    Right_Knee_Bend_Straight_Angle_Speed = Right_Knee_Bend_Straight_Angle_Speed * 1;
  }
  
  if (Right_Knee_Bend_Straight_Angle_Speed <= 0){
    Right_Knee_Bend_Straight_Angle_Speed = 0;
  }
  
  if (Right_Knee_Bend_Straight_Angle_Speed >= 255){
    Right_Knee_Bend_Straight_Angle_Speed = 255;
  }


if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 <= RIGHT_KNEE_BEND_STRAIGHT_MIN + 5){
  RIGHT_KNEE_BEND_STRAIGHT_MIN_STOP = true;
}
else
{
  RIGHT_KNEE_BEND_STRAIGHT_MIN_STOP = false; 
}


if (ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 >= RIGHT_KNEE_BEND_STRAIGHT_MAX - 5){
  RIGHT_KNEE_BEND_STRAIGHT_MAX_STOP = true;  
}
else
{
  RIGHT_KNEE_BEND_STRAIGHT_MAX_STOP = false;  
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Hip_Bend_Back_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


//    // Read new position
//  ANALOG_IN_X_JOY_SETPOINT = analogRead(Analog_In_X_Joy_setpoint);
//  ANALOG_IN_X_JOY_SETPOINT = map(ANALOG_IN_X_JOY_SETPOINT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_IN_X_JOY_SETPOINT;
//  
//
//  ANALOG_IN_Y_JOY_SETPOINT = analogRead(Analog_In_Y_Joy_setpoint);
//  ANALOG_IN_Y_JOY_SETPOINT = map(ANALOG_IN_Y_JOY_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;
//
//
//  ANALOG_IN_SLIDER_SETPOINT = analogRead(Analog_In_Slider_setpoint);
//  ANALOG_IN_SLIDER_SETPOINT = map(ANALOG_IN_SLIDER_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Slider_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
//  ANALOG_IN_POT_SETPOINT = analogRead(Analog_In_Pot_setpoint);
//  ANALOG_IN_POT_SETPOINT = map(ANALOG_IN_POT_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Pot_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
// 
//
//  ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT = analogRead(Analog_Left_Hip_Bend_Back_Actual);
//  ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT = map(ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;
//  Left_Hip_Bend_Back_Current_Angle = ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;
//
//  ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT = analogRead(Analog_Right_Hip_Bend_Back_Actual);
//  ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT = map(ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;
//  Right_Hip_Bend_Back_Current_Angle = ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Left_Hip_Bend_Back_Angle_To_Go_To = ANALOG_IN_SLIDER_SETPOINT - ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT;
  Left_Hip_Bend_Back_Angle_Speed = map(Left_Hip_Bend_Back_Angle_To_Go_To, 1, 95, 240, 255);
  
  if (Left_Hip_Bend_Back_Angle_Speed <= -1){
    Left_Hip_Bend_Back_Angle_Speed = (Left_Hip_Bend_Back_Angle_Speed - 20) * -1;
  }else{
    Left_Hip_Bend_Back_Angle_Speed = Left_Hip_Bend_Back_Angle_Speed * 1;
  }
  
  if (Left_Hip_Bend_Back_Angle_Speed <= 0){
    Left_Hip_Bend_Back_Angle_Speed = 0;
  }
  
  if (Left_Hip_Bend_Back_Angle_Speed >= 255){
    Left_Hip_Bend_Back_Angle_Speed = 255;
  }

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 5 <= LEFT_HIP_BEND_BACK_MIN + 5){
  LEFT_HIP_BEND_BACK_MIN_STOP = true;
}
else
{
  LEFT_HIP_BEND_BACK_MIN_STOP = false; 
}


if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 5 >= LEFT_HIP_BEND_BACK_MAX - 5){
  LEFT_HIP_BEND_BACK_MAX_STOP = true;  
}
else
{
  LEFT_HIP_BEND_BACK_MAX_STOP = false;  
}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Bend_Back_AnalogSignals_and_EndStops_Check(){


SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  Right_Hip_Bend_Back_Angle_To_Go_To = ANALOG_IN_SLIDER_SETPOINT - ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT;
  Right_Hip_Bend_Back_Angle_Speed = map(Right_Hip_Bend_Back_Angle_To_Go_To, -5, 88, 240, 255);

  if (Right_Hip_Bend_Back_Angle_Speed <= -1){
    Right_Hip_Bend_Back_Angle_Speed = (Right_Hip_Bend_Back_Angle_Speed - 20) * -1;
  }else{
    Right_Hip_Bend_Back_Angle_Speed = Right_Hip_Bend_Back_Angle_Speed * 1;
  }
  
  if (Right_Hip_Bend_Back_Angle_Speed <= 0){
    Right_Hip_Bend_Back_Angle_Speed = 0;
  }
  
  if (Right_Hip_Bend_Back_Angle_Speed >= 255){
    Right_Hip_Bend_Back_Angle_Speed = 255;
  }


if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 5 <= RIGHT_HIP_BEND_BACK_MIN + 5){
  RIGHT_HIP_BEND_BACK_MIN_STOP = true;
}
else
{
  RIGHT_HIP_BEND_BACK_MIN_STOP = false; 
}


if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 5 >= RIGHT_HIP_BEND_BACK_MAX - 5){
  RIGHT_HIP_BEND_BACK_MAX_STOP = true;  
}
else
{
  RIGHT_HIP_BEND_BACK_MAX_STOP = false;  
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check(){

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

//    // Read new position
//  ANALOG_IN_X_JOY_SETPOINT = analogRead(Analog_In_X_Joy_setpoint);
//  ANALOG_IN_X_JOY_SETPOINT = map(ANALOG_IN_X_JOY_SETPOINT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_IN_X_JOY_SETPOINT;
//  
//
//  ANALOG_IN_Y_JOY_SETPOINT = analogRead(Analog_In_Y_Joy_setpoint);
//  ANALOG_IN_Y_JOY_SETPOINT = map(ANALOG_IN_Y_JOY_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;
//
//
//  ANALOG_IN_SLIDER_SETPOINT = analogRead(Analog_In_Slider_setpoint);
//  ANALOG_IN_SLIDER_SETPOINT = map(ANALOG_IN_SLIDER_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Slider_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
//  ANALOG_IN_POT_SETPOINT = analogRead(Analog_In_Pot_setpoint);
//  ANALOG_IN_POT_SETPOINT = map(ANALOG_IN_POT_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Pot_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
// 

//  ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = analogRead(Analog_Left_Hip_Pivot_Left_Right_Actual);
//  ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = map(ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
//  Left_Hip_Pivot_Left_Right_Current_Angle = ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
//
//  ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = analogRead(Analog_Right_Hip_Pivot_Left_Right_Actual);
//  ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT = map(ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
//  Right_Hip_Pivot_Left_Right_Current_Angle = ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Left_Hip_Pivot_Left_Right_Angle_To_Go_To = ANALOG_IN_POT_SETPOINT - ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Left_Hip_Pivot_Left_Right_Angle_Speed = map(Left_Hip_Pivot_Left_Right_Angle_To_Go_To, 1, 95, 240, 255);
  
  if (Left_Hip_Pivot_Left_Right_Angle_Speed <= -1){
    Left_Hip_Pivot_Left_Right_Angle_Speed = (Left_Hip_Pivot_Left_Right_Angle_Speed - 20) * -1;
  }else{
    Left_Hip_Pivot_Left_Right_Angle_Speed = Left_Hip_Pivot_Left_Right_Angle_Speed * 1;
  }
  
  if (Left_Hip_Pivot_Left_Right_Angle_Speed <= 0){
    Left_Hip_Pivot_Left_Right_Angle_Speed = 0;
  }
  
  if (Left_Hip_Pivot_Left_Right_Angle_Speed >= 255){
    Left_Hip_Pivot_Left_Right_Angle_Speed = 255;
  }


if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 <= LEFT_HIP_PIVOT_LEFT_RIGHT_MIN + 5){
  LEFT_HIP_PIVOT_LEFT_RIGHT_MIN_STOP = true;
}
else
{
  LEFT_HIP_PIVOT_LEFT_RIGHT_MIN_STOP = false; 
}

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= LEFT_HIP_PIVOT_LEFT_RIGHT_MAX - 5){
  LEFT_HIP_PIVOT_LEFT_RIGHT_MAX_STOP = true;  
}
else
{
  LEFT_HIP_PIVOT_LEFT_RIGHT_MAX_STOP = false;  
}

}
  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check(){

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  Right_Hip_Pivot_Left_Right_Angle_To_Go_To = ANALOG_IN_POT_SETPOINT - ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT;
  Right_Hip_Pivot_Left_Right_Angle_Speed = map(Right_Hip_Pivot_Left_Right_Angle_To_Go_To, -5, 88, 240, 255);

  if (Right_Hip_Pivot_Left_Right_Angle_Speed <= -1){
    Right_Hip_Pivot_Left_Right_Angle_Speed = (Right_Hip_Pivot_Left_Right_Angle_Speed - 20) * -1;
  }else{
    Right_Hip_Pivot_Left_Right_Angle_Speed = Right_Hip_Pivot_Left_Right_Angle_Speed * 1;
  }
  
  if (Right_Hip_Pivot_Left_Right_Angle_Speed <= 0){
    Right_Hip_Pivot_Left_Right_Angle_Speed = 0;
  }
  
  if (Right_Hip_Pivot_Left_Right_Angle_Speed >= 255){
    Right_Hip_Pivot_Left_Right_Angle_Speed = 255;
  }

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 <= RIGHT_HIP_PIVOT_LEFT_RIGHT_MIN + 5){
  RIGHT_HIP_PIVOT_LEFT_RIGHT_MIN_STOP = true;
}
else
{
  RIGHT_HIP_PIVOT_LEFT_RIGHT_MIN_STOP = false; 
}


if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= RIGHT_HIP_PIVOT_LEFT_RIGHT_MAX - 5){
  RIGHT_HIP_PIVOT_LEFT_RIGHT_MAX_STOP = true;  
}
else
{
  RIGHT_HIP_PIVOT_LEFT_RIGHT_MAX_STOP = false;  
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

void Left_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check(){

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

//    // Read new position
//  ANALOG_IN_X_JOY_SETPOINT = analogRead(Analog_In_X_Joy_setpoint);
//  ANALOG_IN_X_JOY_SETPOINT = map(ANALOG_IN_X_JOY_SETPOINT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_IN_X_JOY_SETPOINT;
//  
//
//  ANALOG_IN_Y_JOY_SETPOINT = analogRead(Analog_In_Y_Joy_setpoint);
//  ANALOG_IN_Y_JOY_SETPOINT = map(ANALOG_IN_Y_JOY_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Y_Joy_Current_setpoint = ANALOG_IN_Y_JOY_SETPOINT;
//
//
//
//  ANALOG_IN_SLIDER_SETPOINT = analogRead(Analog_In_Slider_setpoint);
//  ANALOG_IN_SLIDER_SETPOINT = map(ANALOG_IN_SLIDER_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Slider_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
//  ANALOG_IN_POT_SETPOINT = analogRead(Analog_In_Pot_setpoint);
//  ANALOG_IN_POT_SETPOINT = map(ANALOG_IN_POT_SETPOINT, 0, 1023, 0, 180);
//  Analog_In_Pot_Current_setpoint = ANALOG_IN_SLIDER_SETPOINT;
//
// 
//  ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT = analogRead(Analog_Left_Hip_Pivot_In_Out_Actual);
//  ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT = map(ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT, 0, 1023, 0, 180);
//  Current_Angle = ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
//  Left_Hip_Pivot_In_Out_Current_Angle = ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
//
//  ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT = analogRead(Analog_Right_Hip_Pivot_In_Out_Actual);
//  ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT = map(ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT, 1023, 0, 0, 180);
//  Current_Angle = ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
//  Right_Hip_Pivot_In_Out_Current_Angle = ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Left_Hip_Pivot_In_Out_Angle_To_Go_To = New_Left_Hip_Pivot_In_Out_setpoint - ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
  Left_Hip_Pivot_In_Out_Angle_Speed = map(Left_Hip_Pivot_In_Out_Angle_To_Go_To, 1, 95, 240, 255);
  
  if (Left_Hip_Pivot_In_Out_Angle_Speed <= -1){
    Left_Hip_Pivot_In_Out_Angle_Speed = (Left_Hip_Pivot_In_Out_Angle_Speed - 20) * -1;
  }else{
    Left_Hip_Pivot_In_Out_Angle_Speed = Left_Hip_Pivot_In_Out_Angle_Speed * 1;
  }
  
  if (Left_Hip_Pivot_In_Out_Angle_Speed <= 0){
    Left_Hip_Pivot_In_Out_Angle_Speed = 0;
  }
  
  if (Left_Hip_Pivot_In_Out_Angle_Speed >= 255){
    Left_Hip_Pivot_In_Out_Angle_Speed = 255;
  }


if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5 <= LEFT_HIP_PIVOT_IN_OUT_MIN + 5){
  LEFT_HIP_PIVOT_IN_OUT_MIN_STOP = true;
}
else
{
  LEFT_HIP_PIVOT_IN_OUT_MIN_STOP = false; 
}


if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 5 >= LEFT_HIP_PIVOT_IN_OUT_MAX - 5){
  LEFT_HIP_PIVOT_IN_OUT_MAX_STOP = true;  
}
else
{
  LEFT_HIP_PIVOT_IN_OUT_MAX_STOP = false;  
}

}  

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Right_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check(){

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  Right_Hip_Pivot_In_Out_Angle_To_Go_To = New_Left_Hip_Pivot_In_Out_setpoint - ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT;
  Right_Hip_Pivot_In_Out_Angle_Speed = map(Right_Hip_Pivot_In_Out_Angle_To_Go_To, -5, 88, 240, 255);

  if (Right_Hip_Pivot_In_Out_Angle_Speed <= -1){
    Right_Hip_Pivot_In_Out_Angle_Speed = (Right_Hip_Pivot_In_Out_Angle_Speed - 20) * -1;
  }else{
    Right_Hip_Pivot_In_Out_Angle_Speed = Right_Hip_Pivot_In_Out_Angle_Speed * 1;
  }
  
  if (Right_Hip_Pivot_In_Out_Angle_Speed <= 0){
    Right_Hip_Pivot_In_Out_Angle_Speed = 0;
  }
  
  if (Right_Hip_Pivot_In_Out_Angle_Speed >= 255){
    Right_Hip_Pivot_In_Out_Angle_Speed = 255;
  }

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5 <= RIGHT_HIP_PIVOT_IN_OUT_MIN + 5){
  RIGHT_HIP_PIVOT_IN_OUT_MIN_STOP = true;
}
else
{
  RIGHT_HIP_PIVOT_IN_OUT_MIN_STOP = false; 
}


if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 5 >= RIGHT_HIP_PIVOT_IN_OUT_MAX - 5){
  RIGHT_HIP_PIVOT_IN_OUT_MAX_STOP = true;  
}
else
{
  RIGHT_HIP_PIVOT_IN_OUT_MAX_STOP = false;  
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   |\      /|    |-------|     --------      |-------|    |-----\      /-----\                                   
//   | \    / |    |       |         |         |       |    |      |    /       \        
//   |  \  /  |    |       |         |         |       |    |     /     \         
//   |   \/   |    |       |         |         |       |    |- - -       \-----\              
//   |        |    |       |         |         |       |    |     \             \                   
//   |        |    |       |         |         |       |    |      \    \       /                             
//   |        |    |-------|         |         |-------|    |       \    \-----/                      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Left_Ankle_Pivot_Left_Right_Stop(){
 Left_Ankle_Left_Right_Speed_Timer();
SerialPrint();

if ((ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_Y_JOY_SETPOINT - 5) && (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_Y_JOY_SETPOINT + 5)){

 
//if (Left_Ankle_Left_Right_Speed_State == HIGH){
 digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin2, LOW); 
 digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 analogWrite(Left_Ankle_Pivot_Left_Right_MotorENA, 0);
// delay(100);
//}
 
}

}


void Left_Ankle_Pivot_Left(){
  
  Left_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_IN_Y_JOY_SETPOINT <= LEFT_ANKLE_LEFT_RIGHT_MIN){
  ANALOG_IN_Y_JOY_SETPOINT = LEFT_ANKLE_LEFT_RIGHT_MIN;
}


if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_LEFT_RIGHT_MIN){
if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT >= ANALOG_IN_Y_JOY_SETPOINT){
 if (Motors_On_Off_Switch_State == LOW){

 digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin2, HIGH);
 analogWrite(Left_Ankle_Pivot_Left_Right_MotorENA, 80);
}
}
}

//else

if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 <= LEFT_ANKLE_LEFT_RIGHT_MIN + 10){
//if (Left_Ankle_Left_Right_Speed_State == HIGH){
  digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin2, LOW);
 analogWrite(Left_Ankle_Pivot_Left_Right_MotorENA, 0);
// delay(100);
//}
}

}

void Left_Ankle_Pivot_Right(){
  
  Left_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();


if (ANALOG_IN_Y_JOY_SETPOINT >= LEFT_ANKLE_LEFT_RIGHT_MAX){
  ANALOG_IN_Y_JOY_SETPOINT = LEFT_ANKLE_LEFT_RIGHT_MAX;
}


if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 <= LEFT_ANKLE_LEFT_RIGHT_MAX){
if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT <= ANALOG_IN_Y_JOY_SETPOINT){

 if (Motors_On_Off_Switch_State == LOW){

  digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin2, LOW);
  analogWrite(Left_Ankle_Pivot_Left_Right_MotorENA, 100);


 }

}
}

//else

if (ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= LEFT_ANKLE_LEFT_RIGHT_MAX - 10){
//if (Left_Ankle_Left_Right_Speed_State == HIGH){
  digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Ankle_Pivot_Left_Right_MotorPin2, LOW);
  analogWrite(Left_Ankle_Pivot_Left_Right_MotorENA, 0);
// delay(100);
//}
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Left_Ankle_Pivot_Up_Down_Stop(){
 
if ((ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 >= ANALOG_IN_X_JOY_SETPOINT - 5) && (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5  <= ANALOG_IN_X_JOY_SETPOINT + 5)){

 digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin2, LOW); 
 digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  analogWrite(Left_Ankle_Pivot_Up_Down_MotorENA, 0);
// delay(100);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}


//void Left_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Left_Ankle_Pivot_Up(){
  
  Left_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();
  
if (ANALOG_IN_Y_JOY_SETPOINT <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
  ANALOG_IN_Y_JOY_SETPOINT = LEFT_ANKLE_PIVOT_UP_DOWN_MIN;
}

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 5){
if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 2  >= ANALOG_IN_X_JOY_SETPOINT){

 digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin2, HIGH);
 analogWrite(Left_Ankle_Pivot_Up_Down_MotorENA, 100);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Left");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

//else

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 10 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin2, LOW);
  analogWrite(Left_Ankle_Pivot_Up_Down_MotorENA, 0);
// delay(100);
}

}

void Left_Ankle_Pivot_Down(){
  
  Left_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();
  
if (ANALOG_IN_Y_JOY_SETPOINT >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){
  ANALOG_IN_Y_JOY_SETPOINT = LEFT_ANKLE_PIVOT_UP_DOWN_MAX;
}

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 5){

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 2 <= ANALOG_IN_X_JOY_SETPOINT){

  digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin2, LOW);
  analogWrite(Left_Ankle_Pivot_Up_Down_MotorENA, 100);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

//else

if (ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 10 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Ankle_Pivot_Up_Down_MotorPin2, LOW);
  analogWrite(Left_Ankle_Pivot_Up_Down_MotorENA, 0);
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Left_Knee_Bend_Straight_Stop(){
 
if ((ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 digitalWrite(Left_Knee_Bend_Straight_MotorPin2, LOW); 
 digitalWrite(Left_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}


//void Left_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Left_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Left_Knee_Bend(){
  
  Left_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){

 digitalWrite(Left_Knee_Bend_Straight_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Knee_Bend_Straight_MotorPin2, LOW);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Left");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Left_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Knee_Bend_Straight_MotorPin2, LOW);
}

}

void Left_Knee_Straight(){
  
  Left_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){

  digitalWrite(Left_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Knee_Bend_Straight_MotorPin2, HIGH);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Left_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Knee_Bend_Straight_MotorPin2, LOW);
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Left_Hip_Bend_Back_Stop(){
 
if ((ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 digitalWrite(Left_Hip_Bend_Back_MotorPin2, LOW); 
 digitalWrite(Left_Hip_Bend_Back_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}


//void Left_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Left_Hip_Bend_Back_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Left_Hip_Bend(){
  
  Left_Hip_Bend_Back_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){

 digitalWrite(Left_Hip_Bend_Back_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Bend_Back_MotorPin2, HIGH);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Left");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Left_Hip_Bend_Back_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Bend_Back_MotorPin2, LOW);
}

}

void Left_Hip_Back(){
  
  Left_Hip_Bend_Back_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){

  digitalWrite(Left_Hip_Bend_Back_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Hip_Bend_Back_MotorPin2, LOW);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Left_Hip_Bend_Back_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Bend_Back_MotorPin2, LOW);
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Left_Hip_Pivot_Left_Right_Stop(){
 
if ((ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_POT_SETPOINT - 5) && (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_POT_SETPOINT + 5)){

 digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin2, LOW); 
 digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Pivot_Left_Right_MotorENA, LOW);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}


//void Left_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Left_Hip_Pivot_Left(){
  
  Left_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2  >= ANALOG_IN_POT_SETPOINT){

 digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin2, LOW);
 digitalWrite(Left_Hip_Pivot_Left_Right_MotorENA, HIGH);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Left");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin2, LOW);
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorENA, LOW);
}

}

void Left_Hip_Pivot_Right(){
  
  Left_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 <= ANALOG_IN_POT_SETPOINT){

  digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin2, HIGH);
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorENA, HIGH);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Pivot_Left_Right_MotorPin2, LOW);
  digitalWrite(Left_Hip_Pivot_Left_Right_MotorENA, LOW);
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                          
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Left_Hip_Pivot_In_Out_Stop(){
 
if ((ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 5 >= New_Left_Hip_Pivot_In_Out_setpoint - 5) && (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5  <= New_Left_Hip_Pivot_In_Out_setpoint + 5)){

 digitalWrite(Left_Hip_Pivot_In_Out_MotorPin2, LOW); 
 digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Hip_Pivot_In_Out_MotorENA, 0);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Left Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}


//void Left_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Left_Hip_Pivot_In(){
  
  Left_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT >= LEFT_HIP_PIVOT_IN_OUT_MIN){
if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 2  >= New_Left_Hip_Pivot_In_Out_setpoint){

 digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Pivot_In_Out_MotorPin2, HIGH);
  digitalWrite(Left_Hip_Pivot_In_Out_MotorENA, 20);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("LEFT HIP GOING IN");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT <= LEFT_HIP_PIVOT_IN_OUT_MIN){
  digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Pivot_In_Out_MotorPin2, LOW);
  digitalWrite(Left_Hip_Pivot_In_Out_MotorENA, 0);
}

}

void Left_Hip_Pivot_Out(){
  
  Left_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT <= LEFT_HIP_PIVOT_IN_OUT_MAX){

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 2 <= New_Left_Hip_Pivot_In_Out_setpoint){

  digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Left_Hip_Pivot_In_Out_MotorPin2, LOW);
  digitalWrite(Left_Hip_Pivot_In_Out_MotorENA, 20);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("LEFT HIP GOING OUT");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT >= LEFT_HIP_PIVOT_IN_OUT_MAX){
  digitalWrite(Left_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Left_Hip_Pivot_In_Out_MotorPin2, LOW);
  digitalWrite(Left_Hip_Pivot_In_Out_MotorENA, 0);
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//            |-----\       -----     /----\     |     |    -------                                                     
//            |      \        |      /      \    |     |       |                                          
//            |      |        |      |           |     |       |       
//            |_____/         |      |           |-----|       |                                
//            |     \         |      |   ---|    |     |       |                                   
//            |      \        |      \     /     |     |       |                                
//            |       \     -----     \---/      |     |       |                                            
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Right_Ankle_Pivot_Stop(){
  
if ((ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2 >= ANALOG_IN_Y_JOY_SETPOINT - 2) && (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2  <= ANALOG_IN_Y_JOY_SETPOINT + 2)){

  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, LOW);
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin2, LOW);
  analogWrite(Right_Ankle_Pivot_Left_Right_MotorENA, 0);

// delay(100);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right Ankle Stopped");
//  Serial.println("");
//  Serial.println("");

}
}

//void Right_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
// 
//}

void Right_Ankle_Pivot_Left(){

  Right_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_IN_Y_JOY_SETPOINT <= RIGHT_ANKLE_LEFT_RIGHT_MIN){
  ANALOG_IN_Y_JOY_SETPOINT = RIGHT_ANKLE_LEFT_RIGHT_MIN;
}

if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 >= RIGHT_ANKLE_LEFT_RIGHT_MIN + 5){
if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2  >= ANALOG_IN_Y_JOY_SETPOINT){
 
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin2, LOW); 
  analogWrite(Right_Ankle_Pivot_Left_Right_MotorENA, 100);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Left");
//  Serial.println("");
//  Serial.println("");
}
}

if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 10  <= RIGHT_ANKLE_LEFT_RIGHT_MIN + 10){
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin2, LOW);  
  analogWrite(Right_Ankle_Pivot_Left_Right_MotorENA, 0);
// delay(100);
}
}

void Right_Ankle_Pivot_Right(){

  Right_Ankle_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_IN_Y_JOY_SETPOINT >= RIGHT_ANKLE_LEFT_RIGHT_MAX){
  ANALOG_IN_Y_JOY_SETPOINT = RIGHT_ANKLE_LEFT_RIGHT_MAX;
}

if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 <= RIGHT_ANKLE_LEFT_RIGHT_MAX - 5){
if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 <= ANALOG_IN_Y_JOY_SETPOINT){

  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin2, HIGH);  
  analogWrite(Right_Ankle_Pivot_Left_Right_MotorENA, 180);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");

}
}

if (ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT + 10 >= RIGHT_ANKLE_LEFT_RIGHT_MAX - 10){
  
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Ankle_Pivot_Left_Right_MotorPin2, LOW);  
  analogWrite(Right_Ankle_Pivot_Left_Right_MotorENA, 0);
// delay(100);
 
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Ankle_Pivot_Up_Down_Stop(){
 
if ((ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 >= ANALOG_IN_X_JOY_SETPOINT - 5) && (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5  <= ANALOG_IN_X_JOY_SETPOINT + 5)){

 digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin2, LOW); 
 digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  analogWrite(Right_Ankle_Pivot_Up_Down_MotorENA, 0);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}


//void Right_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Right_Ankle_Pivot_Up(){
  
  Right_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();
  
if (ANALOG_IN_Y_JOY_SETPOINT <= RIGHT_ANKLE_PIVOT_UP_DOWN_MIN){
  ANALOG_IN_Y_JOY_SETPOINT = RIGHT_ANKLE_PIVOT_UP_DOWN_MIN;
}

if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5 >= RIGHT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 2  >= ANALOG_IN_X_JOY_SETPOINT){

 digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin2, HIGH);
  analogWrite(Right_Ankle_Pivot_Up_Down_MotorENA, 170);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5 <= RIGHT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin2, LOW);
  analogWrite(Right_Ankle_Pivot_Up_Down_MotorENA, 0);
}

}

void Right_Ankle_Pivot_Down(){
  
  Right_Ankle_Pivot_Up_Down_AnalogSignals_and_EndStops_Check();
  
if (ANALOG_IN_Y_JOY_SETPOINT >= RIGHT_ANKLE_PIVOT_UP_DOWN_MAX){
  ANALOG_IN_Y_JOY_SETPOINT = RIGHT_ANKLE_PIVOT_UP_DOWN_MAX;
}

if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT + 5 <= RIGHT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 2 <= ANALOG_IN_X_JOY_SETPOINT){

  digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin2, LOW);
  analogWrite(Right_Ankle_Pivot_Up_Down_MotorENA, 170);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT - 5 >= RIGHT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Ankle_Pivot_Up_Down_MotorPin2, LOW);
  analogWrite(Right_Ankle_Pivot_Up_Down_MotorENA, 0);
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Knee_Bend_Straight_Stop(){
 
if ((ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 digitalWrite(Right_Knee_Bend_Straight_MotorPin2, LOW); 
 digitalWrite(Right_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}

//void Right_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Right_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Right_Knee_Bend(){
  
  Right_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){

 digitalWrite(Right_Knee_Bend_Straight_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Knee_Bend_Straight_MotorPin2, LOW);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Right_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Knee_Bend_Straight_MotorPin2, LOW);
}

}

void Right_Knee_Straight(){
  
  Right_Knee_Bend_Straight_AnalogSignals_and_EndStops_Check();

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){

  digitalWrite(Right_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Knee_Bend_Straight_MotorPin2, HIGH);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Right_Knee_Bend_Straight_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Knee_Bend_Straight_MotorPin2, LOW);
}

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Right_Hip_Bend_Back_Stop(){
 
if ((ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 5 >= ANALOG_IN_SLIDER_SETPOINT - 5) && (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 5  <= ANALOG_IN_SLIDER_SETPOINT + 5)){

 digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin2, LOW); 
 digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}

//void Right_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Right_Hip_Bend(){
  
  Right_Hip_Bend_Back_AnalogSignals_and_EndStops_Check();

if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 2  >= ANALOG_IN_SLIDER_SETPOINT){

 digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin2, HIGH);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin2, LOW);
}

}

void Right_Hip_Back(){
  
  Right_Hip_Bend_Back_AnalogSignals_and_EndStops_Check();

if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 2 <= ANALOG_IN_SLIDER_SETPOINT){

  digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin2, LOW);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Forward_Backward_MotorPin2, LOW);
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Pivot_Left_Right_Stop(){
 
if ((ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 >= ANALOG_IN_POT_SETPOINT - 5) && (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5  <= ANALOG_IN_POT_SETPOINT + 5)){

 digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin2, LOW); 
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorENA, LOW);
 
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}

//void Right_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Right_Hip_Pivot_Left(){
  
  Right_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MIN){
if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 2  >= ANALOG_IN_POT_SETPOINT){

 digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin2, HIGH);
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorENA, HIGH);
 

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Left");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MIN + 10){
  digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin2, LOW);
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorENA, LOW);
}

}

void Right_Hip_Pivot_Right(){
  
  Right_Hip_Pivot_Left_Right_AnalogSignals_and_EndStops_Check();

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT + 5 <= LEFT_ANKLE_PIVOT_UP_DOWN_MAX){

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 2 <= ANALOG_IN_POT_SETPOINT){

  digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin2, LOW);
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorENA, HIGH);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorPin2, LOW);
 digitalWrite(Right_Hip_Pivot_Left_Right_MotorENA, LOW);
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Right_Hip_Pivot_In_Out_Stop(){
 
if ((ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 5 >= New_Right_Hip_Pivot_In_Out_setpoint - 5) && (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5  <= New_Right_Hip_Pivot_In_Out_setpoint + 5)){

 digitalWrite(Right_Hip_Pivot_In_Out_MotorPin2, LOW); 
 digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_In_Out_MotorENA, 0);

//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right Ankle Stopped");
//  Serial.println("");
//  Serial.println("");
  
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = true;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;
  
}

}

//void Right_Ankle_Pivot_Right_Stop(){
//
//  digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
//
//// LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = true;
//// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;  
// 
//}

void Right_Hip_Pivot_In(){
  
  Right_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check();

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5 >= RIGHT_HIP_PIVOT_IN_OUT_MIN){
if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 2  >= New_Right_Hip_Pivot_In_Out_setpoint){

 digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_In_Out_MotorPin2, HIGH);
 digitalWrite(Right_Hip_Pivot_In_Out_MotorENA, 20);
 
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Left");
//  Serial.println("");
//  Serial.println("");
  
// LEFT_ANKLE_PIVOT_LEFT_RUNNING = true;
// LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// LEFT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
// RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
// RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5 <= RIGHT_HIP_PIVOT_IN_OUT_MIN + 10){
  digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_In_Out_MotorPin2, LOW);
 digitalWrite(Right_Hip_Pivot_In_Out_MotorENA, 0);
}

}

void Right_Hip_Pivot_Out(){
  
  Right_Hip_Pivot_In_Out_AnalogSignals_and_EndStops_Check();

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT + 5 <= RIGHT_HIP_PIVOT_IN_OUT_MAX){

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 2 <= New_Right_Hip_Pivot_In_Out_setpoint){

  digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, HIGH);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
  digitalWrite(Right_Hip_Pivot_In_Out_MotorPin2, LOW);
 digitalWrite(Right_Hip_Pivot_In_Out_MotorENA, 20);
  
//  Serial.println("");
//  Serial.println("");
//  Serial.println("Right going Right");
//  Serial.println("");
//  Serial.println("");
    
//LEFT_ANKLE_PIVOT_LEFT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//LEFT_ANKLE_PIVOT_RIGHT_RUNNING = true;
//LEFT_ANKLE_PIVOT_LEFT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_STOPPED = false;
//RIGHT_ANKLE_PIVOT_RIGHT_RUNNING = false;
//RIGHT_ANKLE_PIVOT_LEFT_RUNNING = false;

}
}

else

if (ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT - 5 >= LEFT_ANKLE_PIVOT_UP_DOWN_MAX - 10){
  digitalWrite(Right_Hip_Pivot_In_Out_MotorPin1, LOW);          // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
 digitalWrite(Right_Hip_Pivot_In_Out_MotorPin2, LOW);
 digitalWrite(Right_Hip_Pivot_In_Out_MotorENA, 0);
}

}



//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//*****************************************************************************************************************************************

//*****************************************************************************************************************************************


void Test_Remote_Inputs_Signals(){



SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();

  //lcd.setCursor(0,0);
  //lcd.print("Set Y: ");

  //lcd.setCursor(10,0);  
  //lcd.print(Analog_In_Y_Joy_Current_setpoint);
  //lcd.print("  ");

  //lcd.setCursor(14,0);  
  //lcd.print(Remote_On_Off_SwitchState);
  //lcd.print(" ");
  
  //lcd.setCursor(16,0);  
  //lcd.print(Menu_Up_ButtonState);
  //lcd.print(" ");


  //lcd.setCursor(0,1);
  //lcd.print("Set X: ");


  //lcd.setCursor(10,1);
  //lcd.print(Analog_In_X_Joy_Current_setpoint);
  //lcd.print("   ");

    
  //lcd.setCursor(14,1);  
  //lcd.print(Joy_Switch_ButtonState);
  //lcd.print("   ");

  //lcd.setCursor(16,1);  
  //lcd.print(Menu_Down_ButtonState);
  //lcd.print("   ");



  //lcd.setCursor(0,2);
  //lcd.print("Set Z: ");

  //lcd.setCursor(10,2);
  //lcd.print(Analog_In_Slider_Current_setpoint);
  //lcd.print("   ");  


  //lcd.setCursor(16,2);
  //lcd.print(Menu_Enter_ButtonState);
  //lcd.print("   ");  

  
  //lcd.setCursor(0,3);
  //lcd.print("Set Pot: ");

  //lcd.setCursor(10,3);
  //lcd.print(Analog_In_Pot_Current_setpoint);
  //lcd.print("   ");

  //lcd.setCursor(16,3);
  //lcd.print(Menu_Exit_ButtonState);
  //lcd.print("   ");

  

  
}

//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________
//

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#################################################################################################################################################################################
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************

void SerialPrint(){
  
serialprintTimer();

if (SerialPrintState == HIGH){

Serial.println("");

////
////Serial.println("");
////Serial.print("HeartbeatLEDProgress : ");
////Serial.print(HeartbeatLEDProgress);
////
////Serial.println("");
////Serial.print("HeartbeatLEDState : ");
////Serial.print(HeartbeatLEDState);
////
////Serial.println("");
//
//
////*****************************************************************************************************************************************
////         MOTOR ON / OFF SWITCH MONITORING 
//
//Serial.println("");
//Serial.print("Motors_On_Off_Switch_State : ");
//Serial.print(Motors_On_Off_Switch_State);
//
//Serial.println("");
//Serial.print("Run_Robot : ");
//Serial.print(Run_Robot);
//
//Serial.println("");
//Serial.print("Stop_Robot : ");
//Serial.print(Stop_Robot);
//
//Serial.println("");
//Serial.print("Left_Ankle_Left_Right_Speed_Progress : ");
//Serial.print(Left_Ankle_Left_Right_Speed_Progress);

//Serial.println("");
//Serial.print("Left_Ankle_Left_Right_Speed_State : ");
//Serial.print(Left_Ankle_Left_Right_Speed_State);
//
//Serial.println("");
//Serial.print("Left_Ankle_Left_Right_Timer_Speed : ");
//Serial.print(Left_Ankle_Left_Right_Timer_Speed);
//
//Serial.println("");

////*****************************************************************************************************************************************
////          REMOTE CONTROL MONITORING
//
//Serial.println("");
//Serial.print("Remote_On_Off_SwitchState : ");
//Serial.print(Remote_On_Off_SwitchState);
//
Serial.println("");
Serial.print("Analog_In_X_Joy_Current_setpoint : ");
Serial.print(Analog_In_X_Joy_Current_setpoint);

Serial.println("");
Serial.print("Analog_In_Y_Joy_Current_setpoint : ");
Serial.print(Analog_In_Y_Joy_Current_setpoint);

Serial.println("");
Serial.println("");


Serial.println("");
Serial.print("New_Ankle_Pivot_Left_Right_setpoint : ");
Serial.print(New_Ankle_Pivot_Left_Right_setpoint);

Serial.println("");
Serial.print("New_Left_Hip_Pivot_In_Out_setpoint : ");
Serial.print(New_Left_Hip_Pivot_In_Out_setpoint);

Serial.println("");
Serial.print("New_Right_Hip_Pivot_In_Out_setpoint : ");
Serial.print(New_Right_Hip_Pivot_In_Out_setpoint);



//Serial.println("");
//Serial.print("Analog_In_Slider_Current_setpoint : ");
//Serial.print(Analog_In_Slider_Current_setpoint);
//
//Serial.println("");
//Serial.print("Analog_In_Pot_Current_setpoint : ");
//Serial.print(Analog_In_Pot_Current_setpoint);
//
//
////Serial.println("");
////Serial.print("Joy_Switch_ButtonState: ");
////Serial.print(Joy_Switch_ButtonState);     
////
////Serial.println("");
////Serial.print("Menu_Up_ButtonState: ");
////Serial.print(Menu_Up_ButtonState);     
////
////Serial.println("");
////Serial.print("Menu_Down_ButtonState: ");
////Serial.print(Menu_Down_ButtonState);  
////
////Serial.println("");
////Serial.print("Menu_Enter_ButtonState: ");
////Serial.print(Menu_Enter_ButtonState);     
////
////
////Serial.println("");
////Serial.print("Menu_Exit_ButtonState: ");
////Serial.print(Menu_Exit_ButtonState);  

Serial.println("");
Serial.println("");

////*****************************************************************************************************************************************
////            MENU SETUP MONITORING
//
////Serial.println("");
////Serial.print("Menu: ");
////Serial.print(Menu);  
//
////*****************************************************************************************************************************************
//
//
//
//
////Serial.println("");
////Serial.print("Ankle_Left_Right_Current_Act_Angle : ");
////Serial.print(ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
////
//////Serial.println("");
//////Serial.print("RotaryPosition: ");
//////Serial.print(RotaryPosition);     
//
//Serial.println("");
//Serial.print("Right_Ankle_Pivot_Left_Right_Current_Angle: ");
//Serial.print(Right_Ankle_Pivot_Left_Right_Current_Angle);     

Serial.println("");
Serial.print("ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT: ");
Serial.print(ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);  

//Serial.println("");
//Serial.print("Left_Ankle_Pivot_Left_Right_Current_Angle: ");
//Serial.print(Left_Ankle_Pivot_Left_Right_Current_Angle);     

Serial.println("");
Serial.print("ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT: ");
Serial.print(ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);  

Serial.println("");

/////////////////////////////////////////////////////////////////////////////////
//
//Serial.println("");
//Serial.print("Right_Ankle_Pivot_Up_Down_Current_Angle: ");
//Serial.print(Right_Ankle_Pivot_Up_Down_Current_Angle);     

Serial.println("");
Serial.print("ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT: ");
Serial.print(ANALOG_RIGHT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT);  

//Serial.println("");
//Serial.print("Left_Ankle_Pivot_Up_Down_Current_Angle: ");
//Serial.print(Left_Ankle_Pivot_Up_Down_Current_Angle);     

Serial.println("");
Serial.print("ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT: ");
Serial.print(ANALOG_LEFT_ANKLE_PIVOT_UP_DOWN_ANGLE_ACT);  

Serial.println("");

/////////////////////////////////////////////////////////////////////////////////
//
//Serial.println("");
//Serial.print("Right_Knee_Bend_Straight_Current_Angle: ");
//Serial.print(Right_Knee_Bend_Straight_Current_Angle);     
//
//Serial.println("");
//Serial.print("ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT: ");
//Serial.print(ANALOG_RIGHT_KNEE_BEND_STRAIGHT_ANGLE_ACT);  
//
//Serial.println("");
//Serial.print("Left_Knee_Bend_Straight_Current_Angle: ");
//Serial.print(Left_Knee_Bend_Straight_Current_Angle);     
//
//Serial.println("");
//Serial.print("ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT: ");
//Serial.print(ANALOG_LEFT_KNEE_BEND_STRAIGHT_ANGLE_ACT);  
//
//Serial.println("");
//
/////////////////////////////////////////////////////////////////////////////////
//
//Serial.println("");
//Serial.print("Right_Hip_Bend_Back_Current_Angle: ");
//Serial.print(Right_Hip_Bend_Back_Current_Angle);     
//
//Serial.println("");
//Serial.print("ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT: ");
//Serial.print(ANALOG_RIGHT_HIP_BEND_BACK_ANGLE_ACT);  
//
//Serial.println("");
//Serial.print("Left_Hip_Bend_Back_Current_Angle: ");
//Serial.print(Left_Hip_Bend_Back_Current_Angle);     
//
//Serial.println("");
//Serial.print("ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT: ");
//Serial.print(ANALOG_LEFT_HIP_BEND_BACK_ANGLE_ACT);  
//
//Serial.println("");
//
/////////////////////////////////////////////////////////////////////////////////
//
//Serial.println("");
//Serial.print("Right_Hip_Pivot_Left_Right_Current_Angle: ");
//Serial.print(Right_Hip_Pivot_Left_Right_Current_Angle);     
//
//Serial.println("");
//Serial.print("ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT: ");
//Serial.print(ANALOG_RIGHT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT);  
//
//Serial.println("");
//Serial.print("Left_Hip_Pivot_Left_Right_Current_Angle: ");
//Serial.print(Left_Hip_Pivot_Left_Right_Current_Angle);     
//
//Serial.println("");
//Serial.print("ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT: ");
//Serial.print(ANALOG_LEFT_HIP_PIVOT_LEFT_RIGHT_ANGLE_ACT);  

Serial.println("");

///////////////////////////////////////////////////////////////////////////////
//
//Serial.println("");
//Serial.print("Right_Hip_Pivot_In_Out_Current_Angle: ");
//Serial.print(Right_Hip_Pivot_In_Out_Current_Angle);     

Serial.println("");
Serial.print("ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT: ");
Serial.print(ANALOG_RIGHT_HIP_PIVOT_IN_OUT_ANGLE_ACT);  

//Serial.println("");
//Serial.print("Left_Hip_Pivot_In_Out_Current_Angle: ");
//Serial.print(Left_Hip_Pivot_In_Out_Current_Angle);     

Serial.println("");
Serial.print("ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT: ");
Serial.print(ANALOG_LEFT_HIP_PIVOT_IN_OUT_ANGLE_ACT);  

Serial.println("");
//
/////////////////////////////////////////////////////////////////////////////////



////Serial.println("");
////Serial.print("RotaryPosition: ");
////Serial.print(RotaryPosition);     


//Serial.println("");
//Serial.print("Left_Ankle_Left_Right_Angle_To_Go_To: ");
//Serial.print(Left_Ankle_Left_Right_Angle_To_Go_To);  
//
//Serial.println("");
//Serial.print("Right_Ankle_Left_Right_Angle_To_Go_To: ");
//Serial.print(Right_Ankle_Left_Right_Angle_To_Go_To);  
////
//Serial.println("");
//Serial.print("Left_Ankle_Left_Right_Angle_Speed: ");
//Serial.print(Left_Ankle_Left_Right_Angle_Speed);     
//
//Serial.println("");
//Serial.print("Right_Ankle_Left_Right_Angle_Speed: ");
//Serial.print(Right_Ankle_Left_Right_Angle_Speed);  

Serial.println("");

//Serial.println("");
//Serial.print("LEFT_ANKLE_LEFT_RIGHT_MIN_STOP : ");
//Serial.print(LEFT_ANKLE_LEFT_RIGHT_MIN_STOP);
//
//Serial.println("");
//Serial.print("LEFT_ANKLE_LEFT_RIGHT_MAAX_STOP: ");
//Serial.print(LEFT_ANKLE_LEFT_RIGHT_MAX_STOP);     
//
//Serial.println("");
//Serial.print("RIGHT_ANKLE_LEFT_RIGHT_MIN_STOP: ");
//Serial.print(RIGHT_ANKLE_LEFT_RIGHT_MIN_STOP);     
//
//Serial.println("");
//Serial.print("RIGHT_ANKLE_LEFT_RIGHT_MAX_STOP: ");
//Serial.print(RIGHT_ANKLE_LEFT_RIGHT_MAX_STOP);  
//
//Serial.println("");
//Serial.println("");

//Serial.println("");
//Serial.print("LEFT_ANKLE_PIVOT_LEFT_STOPPED: ");
//Serial.print(LEFT_ANKLE_PIVOT_LEFT_STOPPED);     
//
//Serial.println("");
//Serial.print("LEFT_ANKLE_PIVOT_RIGHT_STOPPED: ");
//Serial.print(LEFT_ANKLE_PIVOT_RIGHT_STOPPED);  
//
//Serial.println("");
//Serial.print("LEFT_ANKLE_PIVOT_RIGHT_RUNNING: ");
//Serial.print(LEFT_ANKLE_PIVOT_RIGHT_RUNNING);     
//
//Serial.println("");
//Serial.print("LEFT_ANKLE_PIVOT_LEFT_RUNNING: ");
//Serial.print(LEFT_ANKLE_PIVOT_LEFT_RUNNING);  
//
//
//Serial.println("");
//Serial.print("RIGHT_ANKLE_PIVOT_LEFT_STOPPED : ");
//Serial.print(RIGHT_ANKLE_PIVOT_LEFT_STOPPED);
//
//Serial.println("");
//Serial.print("RIGHT_ANKLE_PIVOT_RIGHT_STOPPED: ");
//Serial.print(RIGHT_ANKLE_PIVOT_RIGHT_STOPPED);     
//
//Serial.println("");
//Serial.print("RIGHT_ANKLE_PIVOT_RIGHT_RUNNING: ");
//Serial.print(RIGHT_ANKLE_PIVOT_RIGHT_RUNNING);     
//
//Serial.println("");
//Serial.print("RIGHT_ANKLE_PIVOT_LEFT_RUNNING: ");
//Serial.print(RIGHT_ANKLE_PIVOT_LEFT_RUNNING);  
//
//

///* For g-values the corrected raws are used */
//  Serial.print("g-x      = ");
//  Serial.print(gValue.x);
//  Serial.print("  |  g-y      = ");
//  Serial.print(gValue.y);
//  Serial.print("  |  g-z      = ");
//  Serial.println(gValue.z);

/* Angles are also based on the corrected raws. Angles are simply calculated by
   angle = arcsin(g Value) */
//  Serial.print("Angle x  = ");
//  Serial.print(angle.x);
//  Serial.print("  |  Angle y  = ");
//  Serial.print(angle.y);
//  Serial.print("  |  Angle z  = ");
//  Serial.println(angle.z);

//  Serial.print("Orientation of the module: ");
//  Serial.println(myMPU9250.getOrientationAsString());




Serial.println("");
Serial.flush();


//   angle = arcsin(g Value) */
//  Serial.print("Angle x  = ");
//  Serial.print(angle.x);
//  Serial.print("  |  Angle y  = ");
//  Serial.print(angle.y);
//  Serial.print("  |  Angle z  = ");
//  Serial.println(angle.z);
//
//  Serial.print("Orientation of the module: ");
//  Serial.println(myMPU9250.getOrientationAsString());

//  //lcd.setCursor(0,0);
//  //lcd.print("Auto Screen Menu :");
  
//  //lcd.setCursor(0,0);
//  //lcd.print("Set Y: ");
//
//  //lcd.setCursor(10,0);  
//  //lcd.print(Analog_In_Y_Joy_Current_setpoint);
//  //lcd.print("  ");
//
//  //lcd.setCursor(14,0);  
//  //lcd.print(Remote_On_Off_SwitchState);
//  //lcd.print(" ");
//  
//  //lcd.setCursor(16,0);  
//  //lcd.print(Menu_Up_ButtonState);
//  //lcd.print(" ");
//
//
//  //lcd.setCursor(0,1);
//  //lcd.print("Set X: ");
//
//
//  //lcd.setCursor(10,1);
//  //lcd.print(Analog_In_X_Joy_Current_setpoint);
//  //lcd.print("   ");
//
//    
//  //lcd.setCursor(14,1);  
//  //lcd.print(Joy_Switch_ButtonState);
//  //lcd.print("   ");
//
//  //lcd.setCursor(16,1);  
//  //lcd.print(Menu_Down_ButtonState);
//  //lcd.print("   ");
//
//
//
//  //lcd.setCursor(0,2);
//  //lcd.print("Set Z: ");
//
//  //lcd.setCursor(10,2);
//  //lcd.print(Analog_In_Slider_Current_setpoint);
//  //lcd.print("   ");  
//
//
//  //lcd.setCursor(16,2);
//  //lcd.print(Menu_Enter_ButtonState);
//  //lcd.print("   ");  
//
//  
//  //lcd.setCursor(0,3);
//  //lcd.print("Set Pot: ");
//
//  //lcd.setCursor(10,3);
//  //lcd.print(Analog_In_Pot_Current_setpoint);
//  //lcd.print("   ");
//
//  //lcd.setCursor(16,3);
//  //lcd.print(Menu_Exit_ButtonState);
//  //lcd.print("   ");

  
  
//  //lcd.setCursor(0,1);
//  //lcd.print("A: ");
//  //lcd.print("L: ");
//  //lcd.print(ANALOG_LEFT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
//  //lcd.print(" ");
//  //lcd.print("R: ");
//  //lcd.print(ANALOG_RIGHT_ANKLE_PIVOT_LEFT_RIGHT_ANGLE_ACT);
//  //lcd.print("  ");

}

}
//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//*********************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************************************************************


void Menu_Startup(){
  
}


void Menu_Home(){
  
}


void Menu_Test_Remote_Inputs(){
  
}


void Menu_Test_Robot(){
  
}



void Menu_Test_LowerBody(){
  
}


void Menu_Test_Left_Leg(){
  
}


void Menu_Test_Right_Leg(){
  
}

void Menu_Test_Both_Legs(){
  
}


void Menu_Test_UpperBody(){
  
}



//*****************************************************************************************************************************************
////_________________________________________________________________________________________________________________________________________
//#########################################################################################################################################
////_________________________________________________________________________________________________________________________________________


void Menu_Control(){

SerialPrint();
//HeartbeatLEDTimer();
//GyroScope();
DigitalRead_Pins();
Check_All_Analog_Input_Signals();


//if (Remote_On_Off_SwitchState == HIGH){

if (Menu_Up_ButtonState == LOW){
  Menu = Menu++;
}
if (Menu_Down_ButtonState == LOW){
  Menu = Menu--;
}

if (Menu >= 10){
  Menu = 10;
}

if (Menu <= 0){
  Menu = 0;
}


if (Menu == 0){
  
 if (Menu_Flip_Flop_State == HIGH){

  //lcd.setCursor(0, 0);
  //lcd.print("Welcome my Robot Menu:");
  //lcd.setCursor(0, 1);
  //lcd.print("Developed by");
  //lcd.setCursor(0, 2);
  //lcd.print("Tjaart Cronje'");
  //lcd.clear();
  
  }else{
    
  //lcd.setCursor(0, 0);
  //lcd.print("Press the Menu + / -");
  //lcd.setCursor(0, 1);
  //lcd.print("Buttons to Enter Menu");  
  //lcd.setCursor(0, 2);
  //lcd.print("Use Enter and Exit "); 
  //lcd.setCursor(0, 3);
  //lcd.print("To Enter values");
  //lcd.clear();  
  
}
  }

if (Menu == 1){
  //lcd.setCursor(0, 0);
  Test_Remote_Inputs_Signals();

}



//#define Menu_Up_Button 37
//int Menu_Up_ButtonState;
//
//#define Menu_Down_Button 39
//int Menu_Down_ButtonState;
//
//#define Menu_Enter_Button 41
//int Menu_Enter_ButtonState;
//
//#define Menu_Exit_Button 43
//int Menu_Exit_ButtonState;
//
//int Menu_Cursor_Row;
//int Menu_Cursor_Colomn;


if (Menu == 2){

  Menu_Cursor_Colomn = 0;

  //lcd.setCursor(0, 0);
  //lcd.print("Left Ankle");
  //lcd.setCursor(0, 1);
  //lcd.print("Left Knee");
  //lcd.setCursor(0, 2);
  //lcd.print("Left Hip");
  
//if (//lcd.setCursor(0, 2) == //lcd.setCursor(Menu_Cursor_Colomn, Menu_Cursor_Row)){
if (Menu_Enter_ButtonState == LOW){
//lcd.print("hALLO");

//  Left_Ankle_Pivot_Left_Right_Testing();

  
}
  
//}

//if (//lcd.setCursor(0, 1)  == //lcd.setCursor(Menu_Cursor_Colomn, Menu_Cursor_Row)){
if (Menu_Enter_ButtonState == LOW){

//  Left_Ankle_Pivot_Left_Right_Testing();

  
}
  
//}

//if (//lcd.setCursor(0, 0) == //lcd.setCursor(Menu_Cursor_Colomn, Menu_Cursor_Row)){
if (Menu_Enter_ButtonState == LOW){

//  Left_Ankle_Pivot_Left_Right_Testing();

  
}
  
//}

//Menu_Cursor_Row
  
  //lcd.setCursor(Menu_Cursor_Colomn, Menu_Cursor_Row);
  
//Menu_Test_Robot();

}

if (Menu == 3){
  Right_Ankle_Pivot_Left_Right_Testing();
}


if (Menu == 3){
//  Left_Ankle_Pivot_Up_Down_Testing();
}

if (Menu == 3){
//  Left_Ankle_Pivot_Left_Right_Testing();
}

//}
  
}
