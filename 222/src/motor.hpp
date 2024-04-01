#include "vex.h"
#include "cmath"
using namespace vex;
extern motor motor1_left;
extern motor motor1_right;
extern motor motor2_left;
extern motor motor2_right;
extern timer time1;
extern inertial inertial1;
extern bool r1,r2,l1,l2;
//-------------------------------
extern void spin_direction(float z);
//extern void spin_direction_test(float z);
extern void stage(motor x,float y,float z);
extern void stage2(motor x,float y,float z);
extern void stage3(motor x,float y,float z);
extern void stage4(motor x,float y,float z);
extern void crastidrome(float x);
extern void all_stop(void);
extern void planed_route(void);
