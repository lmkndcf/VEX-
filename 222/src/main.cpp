/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       z                                                         */
/*    Created:      2024/3/8 14:21:20                                         */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// #include "vex.h"

// using namespace vex;
#include "motor.hpp"
// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
//学习一下回调函数，可以简化代码

int main()
 {
    float distance5=300; //半个格子的编码值
    inertial1.calibrate();
    waitUntil(!inertial1.isCalibrating());
    inertial1.resetRotation();
    Brain.Screen.printAt( 10, 50, "Hello V5" );
    planed_route();
    //time1.clear();
    // while(1)
    // {
    // spin_direction(-90);
    // Brain.Screen.clearScreen();
    // Brain.Screen.print(time1.time());
    // if(time1.time()>3000)
    // {
    //   all_stop();
    //   break;
    // }
    // }
    // while (1)
    // {
    //   motor1_left.spin(directionType::rev,10,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,15,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,25,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,35,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,45,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,55,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,65,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,75,rpm);
    //   //this_thread::sleep_for(20);
    //   motor1_left.spin(directionType::rev,85,rpm);
    //   //this_thread::sleep_for(20);
      
    // }
    
   
   }

