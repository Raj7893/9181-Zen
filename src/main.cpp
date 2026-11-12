/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       rajve                                                     */
/*    Created:      11/4/2026, 7:03:22 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
// All driveTrainMotors
motor DriveFrontLeft = motor(PORT9, ratio6_1, true);
motor DriveFrontRight = motor(PORT3, ratio6_1, false);
motor DriveBackLeft = motor(PORT6, ratio6_1, true);
motor DriveBackRight = motor(PORT4, ratio6_1, false);
motor test = motor(PORT16, ratio18_1, true);
// DriveTrain MotorGroups
motor_group driveLeft = motor_group(DriveBackLeft, DriveFrontLeft);
motor_group driveRight = motor_group(DriveBackRight, DriveFrontRight);
controller Controller1 = controller(primary);




/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/




void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
  float throttle = Controller1.Axis3.value();
  if (throttle < 5 && throttle > -5)
  {
   throttle = 0;
   
  }
 float turn = Controller1.Axis1.value();
  if (turn < 5 && turn > -5)
  {
   turn = 0;
  }
  if (Controller1.ButtonL2.pressing())
  {
    throttle = throttle/2;
    turn = turn/2;
  }
float leftPow = throttle + turn ;
float RightPow = throttle - turn;


    driveLeft.spin(fwd,leftPow,percent);
    driveRight.spin(fwd,RightPow,percent);
    // break the drivetrain so 
   if (leftPow == 0)
   {
    driveLeft.stop(brake);

   }
   if (RightPow == 0)
   {
    driveRight.stop(brake);
   }
    

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
