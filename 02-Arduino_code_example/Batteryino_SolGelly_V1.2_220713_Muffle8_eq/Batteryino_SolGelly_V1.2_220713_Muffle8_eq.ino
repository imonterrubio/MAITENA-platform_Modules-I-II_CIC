
/*  Creado por/Created by:


                    Evaristo Castillo Martín                   Icíar Monterrubio Santín                    CICenergigune

*/


#include <MultiStepper.h> 
#include <AccelStepper.h>
#include <Wire.h>   

#define Conejillo 1    
#define Lagartija 2  
#define Patita 03
#define Ada 04
#define Jane 05        
#define Valentina 06
#define Alice 07
#define Grace 8
#define EN 8    



#define Y_DIR 6   /* Direction pin for Y axis */
#define Y_STEP 3  /* Step pin for Y axis */

#define X1_DIR 7   /* Direction pin for X1 axis */
#define X1_STEP 4  /* Step pin for X1 axis */

#define X2_DIR 5   /* Direction pin for X2 axis */
#define X2_STEP 2  /* Step pin for X2 axis */

#define A_DIR 13  
#define A_STEP 12 


#define motorInterfaceType 1  

AccelStepper stepperY = AccelStepper(motorInterfaceType, Y_STEP, Y_DIR);    
AccelStepper stepperX1 = AccelStepper(motorInterfaceType, X1_STEP, X1_DIR);
AccelStepper stepperX2 = AccelStepper(motorInterfaceType, X2_STEP, X2_DIR);
MultiStepper pareados; 
                                                                     
                                                   

String A[8][13] = {                                                      
//Crucibles   NULL    1   2   3   4   5   6   7   8   9   10    11    12  
  /*NULL*/  {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
  /*Patita-SAU-Li3*/  {"0", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53", "2.53"},
  /*Grace-Fe4*/   {"  0 ", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22", "4.22"},
  /*Jane-CA5*/  {"0", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99", "2.99"},
  /*Valentina-EG6*/   {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
  /*Alice-Mn7*/   {"  0 ", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59", "7.59"},
  /*Ada8*/  {"0","W", "W", "W", "W", "W", "W", "W", "W", "W", "W", "W", "W"},
  /*9Ni*/   {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
};                                                      



int O[8][13] = {
  //Crucibles      0  1  2  3  4  5  6  7  8  9 10  11 12
  /*OrdenN0*/   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  /*OrdenN1*/   {0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
  /*OrdenN2*/   {0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
  /*OrdenN3*/   {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
  /*OrdenN4*/   {0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
  /*OrdenN5*/   {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
  /*OrdenN6*/   {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}, 
  /*OrdenN7*/   {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
};


int p[16][2] = {
  //              X    Y
  /*ORIGEN*/     {0, 0},     
  /*POSICIÓN1*/  { -1100, 350},
  /*POSICIÓN2*/  { -1100, 800},      //
  /*POSICIÓN3*/  { -1100, 1250},      //
  /*POSICIÓN4*/  { -1550, 350},      //
  /*POSICIÓN5*/  { -1550, 800},      //
  /*POSICIÓN6*/  { -1550, 1250},
  /*POSICIÓN7*/  { -2000, 350},
  /*POSICIÓN8*/  { -2000, 800},
  /*POSICIÓN9*/  { -2000, 1250},
  /*POSICIÓN10*/ { -2450, 350},
  /*POSICIÓN11*/ { -2450, 800},
  /*POSICIÓN12*/ { -2450, 1250},
  /*POSICIÓN13*/ {0, 0},
  /*POSICIÓN14*/ {0, 0},
  /*POSICIÓN15*/ { -350, 800},
};


String MixVolume = "20";                  
int WN;                                                 
String WashingVolume = "20";                           
String Washing2Volume = "25";                          

int y = 1;                                              
float s = 0.00;                                    
char computerdata[20];
byte received_from_computer = 0;
byte code = 0;                   //used to hold the I2C response code.        
char pmp_data[20];               //we make a 20 byte character array to hold incoming data from the EZO-PMP.
byte in_char = 0;                //used as a 1 byte buffer to store in bound bytes from the EZO-PMP.
byte i = 0;                      //counter used for pmp_data array.
int time_ = 250;                 //used to change the delay needed depending on the command sent to the EZO-PMP.


void setup() {                   


  Serial.begin(9600);     
  Wire.begin();           
  
  pinMode(EN, OUTPUT);
  pinMode(X2_DIR, OUTPUT);
  pinMode(X2_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_STEP, OUTPUT);
  pinMode(X1_DIR, OUTPUT);
  pinMode(X1_STEP, OUTPUT);
  pinMode(A_DIR, OUTPUT);
  pinMode(A_STEP, OUTPUT);

  /* Enable the X, Y, Z & Aux stepper outputs */
  digitalWrite(EN, LOW); //Low to enable


  stepperX1.setMaxSpeed(100.0);
  stepperX1.setAcceleration(1000.0);

  stepperX2.setMaxSpeed(100.0);
  stepperX2.setAcceleration(1000.0);

  stepperY.setMaxSpeed(150.0);
  stepperY.setAcceleration(150.0);

  pareados.addStepper(stepperX1);
  pareados.addStepper(stepperX2);

  //washing();            

}

void loop() {             
  Menu();                 


}
