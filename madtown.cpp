#include "madtown.h"

class madtown : public IterativeRobot
{
public:
	madtown() {
		//Create your motor controllers, compressors, drivetrain, etc. here
	}
    
	void RobotInit() {                          //Runs once when robot is turned on
		//Typically not necessary to use.  In the past we have used it to update the lcd once in the beginning
		drive = new RobotDrive(2,3,5,6);

		leftJoystick = new Joystick(1);
		rightJoystick = new Joystick(2);

		shifter1 = new DoubleSolenoid(1,2);
		shifter2 = new DoubleSolenoid(3,4);

		uselessJoystick = new Joystick(3);
		
		spinny = new Talon(8);
		intake = new Solenoid(5);
		
		compressor = new Compressor(6, 1);
		compressor->Start();

		timer = new Timer();
		timer->Start();
		
		SmartDashboard::PutNumber("State", 420);
		SmartDashboard::PutString("Code Changed", __TIME__);
	}
	
	void AutonomousInit() {
		SmartDashboard::PutNumber("State", 666);
		
		autoStartTime = timer->Get();
		SmartDashboard::PutNumber("Auto start time", autoStartTime);

		shifter1->Set(DoubleSolenoid::kForward);
		shifter2->Set(DoubleSolenoid::kForward);
	}
	
	void TeleopInit() {
		SmartDashboard::PutNumber("State", 1337);
	}
	
	void AutonomousPeriodic() {
		double timeInAuto = timer->Get() - autoStartTime;
        if (timeInAuto < 2.0) {
        	drive->TankDrive(-1.0, -1.0);
        	spinny->Set(0);
      	} else {
        	drive->TankDrive(0.0, 0.0);
        	spinny->Set(1);
        }
	}
	
	void TeleopPeriodic() {
		drive->TankDrive(leftJoystick->GetY(), rightJoystick->GetY());

		if (leftJoystick->GetRawButton(3)){
			shifter1->Set(DoubleSolenoid::kForward);
			shifter2->Set(DoubleSolenoid::kForward);
		}


		if (rightJoystick->GetRawButton(3)){
			shifter1->Set(DoubleSolenoid::kReverse);
			shifter2->Set(DoubleSolenoid::kReverse);
		}

		// Intake
		if (uselessJoystick->GetTrigger() || uselessJoystick->GetY() < -0.75) {
			intake->Set(1);
		} else {
			intake->Set(0);
		}

		// Wheel
		if (uselessJoystick->GetRawButton(3)) {
			spinny->Set(1);
		}
		if (uselessJoystick->GetRawButton(2)) {
			spinny->Set(-1);
		}
		if (!uselessJoystick->GetRawButton(3) && !uselessJoystick->GetRawButton(2)) {
			spinny->Set(0);
		}

		
	}
};

START_ROBOT_CLASS(madtown);
