#include"motor.hpp"
using namespace std;
motor motor1_left(19,-1);
motor motor2_left(18,-1);
motor motor1_right(14); 
motor motor2_right(11);  
timer time1;
inertial inertial1(15);
// double myx=inertial1.acceleration(xaxis);//x轴加速度
// double myy=inertial1.acceleration(yaxis);
// double myz=inertial1.acceleration(zaxis);

// double mygx=inertial1.gyroRate(xaxis,dps);//翻滚角速度
// double mygy=inertial1.gyroRate(yaxis,dps);
// double mygz=inertial1.gyroRate(zaxis,dps);

// double myroll=inertial1.roll(deg);   //翻滚角
// double mypitch=inertial1.pitch(deg);
double myyaw=inertial1.yaw(deg);
double myheading=inertial1.heading(deg);
vex::brain       Brain2;
bool r1,r2,l1,l2=0;




// void spin_direction(float z)
// {
//     float myyaw=0;
//     // inertial1.calibrate();
//     // waitUntil(!inertial1.isCalibrating());
//     // inertial1.resetRotation();
//     inertial1.resetHeading();
//     myheading=inertial1.heading(deg);
//     Brain2.Screen.setCursor(9,1);
//     if(myheading<=180)
//         myyaw=myheading;
//         else
//         myyaw=myheading-360;
//     while (1)
//     {
//         Brain2.Screen.clearLine(9);
//         Brain2.Screen.print(myyaw);
//         myheading=inertial1.heading(deg);
//         if(myheading<=180)
//         myyaw=myheading;
//         else
//         myyaw=myheading-360;
//          if(abs(abs(myyaw)-abs(z))<1)
//         {
//         r1=0;r2=0;l1=0;l2=0;
//         all_stop();
//         break;
//         }

//         if(abs(abs(myyaw)-abs(z))<2)
//         {
//         r1=0;r2=0;l1=0;l2=0;
//         all_stop();
//         break;
//         }

//         if(!l1)
//         stage2(motor1_left,(z-myyaw)*0.8);
//         if(!l2)
//         stage(motor2_left,(z-myyaw)*0.8);
//         if(!r1)
//         stage3(motor1_right,-(z-myyaw)*0.8);
//         if(!r2)
//         stage4(motor2_right,-(z-myyaw)*0.8);
        
//         if(abs(abs(myyaw)-abs(z))<3)
//         {
//         r1=0;r2=0;l1=0;l2=0;
//         all_stop();
//         break;
//         }
//     }  
// }

void crastidrome(float x)
{
    float myyaw=0;
    float speed=0;
    inertial1.resetHeading();
    myheading=inertial1.heading(deg);
    Brain2.Screen.setCursor(9,1);
    if(myheading<=180)
        myyaw=myheading;
        else
        myyaw=myheading-360;

    time1.clear();
    while(1)
    {

        myheading=inertial1.heading(deg);
        if(myheading<=180)
        myyaw=myheading;
        else
        myyaw=myheading-360;
        if(!l2)
        stage(motor2_left,x,myyaw*10);

        if(!r1)
        stage2(motor1_right,x,myyaw*10);
        
        if(!r2)
        stage3(motor2_right,x,myyaw*10);
        if(!l1)
        stage4(motor1_left,x,myyaw*10);

        Brain2.Screen.clearLine(6);
        Brain2.Screen.setCursor(6,1);
        Brain2.Screen.print(l1);
        Brain2.Screen.setCursor(6,3);
        Brain2.Screen.print(l2);
        Brain2.Screen.setCursor(6,5);
        Brain2.Screen.print(r2);
        Brain2.Screen.setCursor(6,7);
        Brain2.Screen.print(r2);
        if(l1==1&&l2==1&&r1==1&&r2==1)
        {
            Brain2.Screen.clearLine(6);
        Brain2.Screen.setCursor(6,1);
        Brain2.Screen.print("over");
            r1=0;r2=0;l1=0;l2=0;
            all_stop();
            break;
        }
        if(time1.time()>5000)
    {
      all_stop();
      break;
    }
    }
}

void all_stop(void)
{
    motor1_left.stop(hold);
    motor1_right.stop(hold);
    motor2_left.stop(hold);
    motor2_right.stop(hold);
}

void planed_route(void)
{
     float distance5=320;
    crastidrome(4*distance5);
    
    spin_direction(90);//spin_direction(80);
   
    crastidrome(2*distance5);
   
    spin_direction(135);//spin_direction(128);
   
    crastidrome(2.8*distance5);
    
    spin_direction(-45);//spin_direction(-35);
    
    crastidrome(1.8*distance5);
    
    spin_direction(-90);//spin_direction(-83);
    
    crastidrome(6*distance5+100);
    
    spin_direction(-45);//spin_direction(-40);
    
    crastidrome(2.6*distance5);
    
    spin_direction(-135);//spin_direction(-122);
    
    crastidrome(4*distance5);
    
    spin_direction(90);//spin_direction(80);
    
    crastidrome(1.8*distance5);
    
    spin_direction(90);//spin_direction(80);
    
    crastidrome(1.8*distance5);
   
    spin_direction(90);//spin_direction(83);
    
    crastidrome(4.1*distance5);
    
    spin_direction(90);//spin_direction(83);
    
    crastidrome(3*distance5);
    all_stop();
}





void stage(motor x,float y,float z=0) 
{
    static bool signal=0;
    static float distance1=0;
    switch (x.index())
       {
       case 19:
        z=-z;break;
       case 18:
        z=-z;
        break;
       default:
        break;
       }

    if(!signal)
    {
        signal=1;
        x.resetPosition();
        if(y>0)
        x.spin(directionType::rev,(60+z),pct);
        else if(y<0)
        x.spin(directionType::fwd,(60+z),pct);
    }
    distance1=x.position(deg);
    
    if(abs(distance1)>abs(y))
    {
        signal=0;
        distance1=0;
        switch (x.index())
       {
       case 19:
        l1=1;break;
       case 18:
        l2=1;
        break;
        case 14:
        r1=1;break;
        case 11:
        r2=1;break;
       default:
        break;
       }
    }
}

void stage2(motor x,float y,float z=0) 
{
    static bool signal=0;
    static float distance2=0;
    switch (x.index())
       {
       case 19:
        z=-z;break;
       case 18:
        z=-z;
        break;
       default:
        break;
       }
    if(!signal)
    {
        signal=1;
        x.resetPosition();
        if(y>0)
        x.spin(directionType::rev,(60+z),pct);
        else if(y<0)
        x.spin(directionType::fwd,(60+z),pct);
    }
    distance2=x.position(deg);
    
    if(abs(distance2)>abs(y))
    {
        //x.stop();
        signal=0;
        distance2=0;
        switch (x.index())
       {
       case 19:
        l1=1;break;
       case 18:
        l2=1;
        break;
        case 14:
        r1=1;break;
        case 11:
        r2=1;break;
       default:
        break;
       }
    }
}

void stage3(motor x,float y,float z=0) 
{
    static bool signal=0;
    static float distance3=0;
    switch (x.index())
       {
       case 19:
        z=-z;break;
       case 18:
        z=-z;
        break;
       default:
        break;
       }
    if(!signal)
    {
        signal=1;
        x.resetPosition();
        if(y>0)
        x.spin(directionType::rev,(60+z),pct);
        else if(y<0)
        x.spin(directionType::fwd,(60+z),pct);
    }
    distance3=x.position(deg);
    
    if(abs(distance3)>abs(y))
    {
        //x.stop();
        signal=0;
        distance3=0;
        switch (x.index())
       {
       case 19:
        l1=1;break;
       case 18:
        l2=1;
        break;
        case 14:
        r1=1;break;
        case 11:
        r2=1;break;
       default:
        break;
       }
    }
}

void stage4(motor x,float y,float z=0) 
{
    static bool signal=0;
    static float distance4=0;
    switch (x.index())
       {
       case 19:
        z=-z;break;
       case 18:
        z=-z;
        break;
       default:
        break;
       }
    if(!signal)
    {
        signal=1;
        x.resetPosition();
        if(y>0)
        x.spin(directionType::rev,(60+z),pct);
        else if(y<0)
        x.spin(directionType::fwd,(60+z),pct);
    }
    distance4=x.position(deg);
    
    if(abs(distance4)>abs(y))
    {
        //x.stop();
        signal=0;
        distance4=0;
        switch (x.index())
       {
       case 19:
        l1=1;break;
       case 18:
        l2=1;
        break;
        case 14:
        r1=1;break;
        case 11:
        r2=1;break;
       default:
        break;
       }
    }
}



void spin_direction(float z)
{
    float myyaw=0;
    float speed=0;
    time1.clear();
    inertial1.resetHeading();
    myheading=inertial1.heading(deg);
    Brain2.Screen.setCursor(9,1);
    if(myheading<=180)
        myyaw=myheading;
        else
        myyaw=myheading-360;
    while (1)
    {
        
        myheading=inertial1.heading(deg);
        if(myheading<=180)
        myyaw=myheading;
        else
        myyaw=myheading-360;

        Brain2.Screen.clearLine(9);
        Brain2.Screen.print(myyaw);
        if(abs(abs(myyaw)-abs(z))<0.2||abs(abs(myyaw)-abs(z))<0.5)
        {
        all_stop();
        break;
        }
         
        if(z>=0)
        {
        speed=pow(abs(z-myyaw)/16,2)>0.95?95:pow(abs(z-myyaw)/16,2)*40;
        speed=speed<15?15:speed;
        }
        else
        {
        speed=pow(abs(z-myyaw)/16,2)>0.95?-95:-pow(abs(z-myyaw)/16,2)*40;
        speed=speed>-15?-15:speed;
        }
        
        motor1_left.spin(directionType::rev,speed,rpm);
        motor2_left.spin(directionType::rev,speed,rpm);
        motor1_right.spin(directionType::rev,-speed,rpm);
        motor2_right.spin(directionType::rev,-speed,rpm);
       if(time1.time()>3000)
    {
      all_stop();
      break;
    }
    }  
}
