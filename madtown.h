/*
 * Includes
 */
#include "WPILib.h"

/*
 * Defines
 */

/*
 * Motors
 */

Talon *spinny;

/*
 * Drive Train
 */

RobotDrive *drive;

/*
 * Timers
 */

double autoStartTime;
Timer *timer;

/*
 * Variables
 */

/*
 * Encoders
 */

/*
 * Controls
 */

Joystick *leftJoystick, *rightJoystick, *uselessJoystick;

/*
 * Pneumatics
 */

Solenoid *intake;
DoubleSolenoid *shifter1, *shifter2;
Compressor *compressor;

/*
 * Miscellaneous
 */
