#pragma comment(lib, "user32.lib")
#include "GimpLeapMaster.h"
#include <iostream>
#include <string.h>
#include <windows.h>
#include "Leap.h"
#include "GimpLeap-Listener.cpp"
#include "GimpLeapEvents.cpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace Leap;

//Leap Motion Controller
Controller controller;
//Listener for controller
GimpLeapListener listener;
//Event Handler
GimpLeapEvent glEvent;

const string fingerNames[] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};

//
void GimpLeapListener::onInit(const Controller& controller) {
  cout << "Initialized" << endl;
}

void GimpLeapListener::onConnect(const Controller& controller) {
  cout << "Connected" << endl;
  controller.enableGesture(Gesture::TYPE_CIRCLE);
  controller.enableGesture(Gesture::TYPE_KEY_TAP);
  controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
  controller.enableGesture(Gesture::TYPE_SWIPE);
}

void GimpLeapListener::onDisconnect(const Controller& controller) {
  // Note: not dispatched when running in a debugger.
  cout << "Disconnected" << endl;
}

void GimpLeapListener::onExit(const Controller& controller) {
  cout << "Exited" << endl;
}


//Every time the Leap sensor produces a frame, the listener will call this function
void GimpLeapListener::onFrame(const Controller& controller) {

	
	Frame frame = controller.frame();
	FingerList fingers = frame.fingers();

	//accept frames only every 500 microseconds
	timestampNow = frame.timestamp();					
	timestampDifference = timestampNow - timestampPrevious;
	if(timestampDifference < 500) return;
	timestampPrevious = frame.timestamp();

	//Do note read when 2 or no hands
	if (frame.hands().isEmpty()) return;
	if (frame.hands().count()==2) return;

	HandList hands = frame.hands();
	Hand hand = hands[0];


	int numOfFingers = fingers.extended().count();

	//Leap as Mouse Gesture
	if(numOfFingers == 1 || numOfFingers == 2)
	{
		//Iterate through fingers and find the index finger
		for (FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); ++fl) 
		{
		  Finger finger = *fl;
		  if(finger.isExtended() && fingerNames[finger.type()] == "Index")
		  {
			  Leap::Screen screen = controller.locatedScreens().closestScreenHit(finger);
			  //move cursor depending on the finger coordinates
			  glEvent.moveCursor(finger,screen);
		  }
		}  
	}
		
	//Default Gesture
	if((numOfFingers == 1  && fingerNames[fingers[0].type()] == "Index")
		|| (numOfFingers == 2  && fingerNames[fingers[0].type()] == "Index" && fingerNames[fingers[1].type()] == "Middle"))
	{
		//if state is click -> stop click
		if(glEvent.clickOnHold)
		{
			glEvent.clickOnHold = false;

			ZeroMemory(&glEvent.Input,sizeof(INPUT));									
			glEvent.Input.type        = INPUT_MOUSE;									
			glEvent.Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								
			SendInput( 1, &glEvent.Input, sizeof(INPUT) );											
		}

		//if state is rotating -> stop rotating
		if(glEvent.isRotating)
		{
			glEvent.isRotating = false;

			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0); 
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('R'),0x9e, 0,0);
			keybd_event(VkKeyScan('R'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VkKeyScan('R'),0x9e, 0,0);
			keybd_event(VkKeyScan('R'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_RETURN,0, 0,0);
			keybd_event(VK_RETURN,0, KEYEVENTF_KEYUP,0); 
		}
		else if(glEvent.isResizing) //if state is resizing -> stop resizing
		{ 
			glEvent.isResizing = false;

			glEvent.previousgrabStrength = NULL;
			glEvent.sizeIncreasing = false;
			glEvent.sizeDecreasing = false;

			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('S'),0x9e, 0,0);
			keybd_event(VkKeyScan('S'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_RETURN,0, 0,0);
			keybd_event(VK_RETURN,0, KEYEVENTF_KEYUP,0); 
		}	
		
	}

	//Draw or Drag gesture
	if(numOfFingers == 2 && !glEvent.isRotating && !glEvent.isResizing && !glEvent.clickOnHold)
	{
		if(fingerNames[fingers[0].type()] == "Thumb" && fingerNames[fingers[1].type()] == "Index" )
		{
			if(glEvent.move)
				glEvent.Drag(frame.fingers());
			else
				glEvent.Draw(frame.fingers());
		}
	}

	//rotate and resize starting gesture
	if (numOfFingers >= 4 || glEvent.isResizing)
	{
		//if state is clicking -> stop click
		if(glEvent.clickOnHold)
		{
			glEvent.clickOnHold = false;

			ZeroMemory(&glEvent.Input,sizeof(INPUT));									
			glEvent.Input.type        = INPUT_MOUSE;									
			glEvent.Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								
			SendInput( 1, &glEvent.Input, sizeof(INPUT) );											
		}

		//if !rotating
		if(!glEvent.isRotating)
		{
			glEvent.grabStrength = (int)(hand.pinchStrength()*10);
		
			//if grab strength > previous grab strength -> increase size
			if(glEvent.grabStrength < glEvent.previousgrabStrength && fingers.frontmost().tipVelocity().magnitude() > 10)
			{
				if(!glEvent.isResizing)
				{
					//start resize function
					glEvent.startResize();
				}
				glEvent.increaseSize();
				glEvent.sizeDecreasing = false;
				glEvent.sizeIncreasing = true;
			}//if grab strength < previous grab strength -> decrease size
			else if (glEvent.grabStrength > glEvent.previousgrabStrength && fingers.frontmost().tipVelocity().magnitude() > 10) 
			{
				if(!glEvent.isResizing)
				{
					//start resize function
					glEvent.startResize();
				}

				glEvent.decreaseSize();
				glEvent.sizeIncreasing = false;
				glEvent.sizeDecreasing = true;
			}// increase size
			else if (glEvent.sizeIncreasing)
			{
				glEvent.increaseSize();
			}// decrease size
			else if (glEvent.sizeDecreasing)
			{
				glEvent.decreaseSize();
			}

			glEvent.previousgrabStrength = glEvent.grabStrength;
		}

		//if not resizing
		if(!glEvent.isResizing)
		{
			Vector handNorm = hand.palmNormal();

			//if state is clicking -> stop click
			if(glEvent.clickOnHold)
			{
				glEvent.clickOnHold = false;

				ZeroMemory(&glEvent.Input,sizeof(INPUT));									
				glEvent.Input.type        = INPUT_MOUSE;									
				glEvent.Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;								
				SendInput( 1, &glEvent.Input, sizeof(INPUT) );											
			}
			
			// if hand tilted
			if (abs(handNorm.roll()) > 0.5)
			{
				
				if(!glEvent.isRotating)
				{
					//start rotate function
					glEvent.startRotate();
				}

				//Rotate clockwise
				if(handNorm.roll() < 0)
				{
					glEvent.rotateRight();
				}//Rotate counter-clockwise
				else
				{
					glEvent.rotateLeft();
				}
			}
		}
	}	
}

///////// GimpLeap UI Event Handler /////////

//This function is called when user presses the EXIT button
void GimpLeapMaster::GimpLeapMaster::removeListener(Object^  sender, EventArgs^  e)
{
		controller.removeListener(listener);
}

//This function is called when user presses UNDO Button
void GimpLeapMaster::GimpLeapMaster::Undo_Click2(System::Object^  sender, MouseEventArgs^  e)
{
	keybd_event(VK_MENU, 0, 0, 0);
	keybd_event(VK_TAB, 0, 0, 0);
	Sleep(5);
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
	Sleep(5);
	keybd_event(VK_LCONTROL,0 ,0 , 0); 
	keybd_event(VkKeyScan('Z'),0x9e, 0,0);
	keybd_event(VkKeyScan('Z'),0x9e, KEYEVENTF_KEYUP,0); 
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_KEYUP, 0); 

}

//This function is called when user presses REDO Button
void GimpLeapMaster::GimpLeapMaster::Redo_Click2(System::Object^  sender, MouseEventArgs^  e)
{
	keybd_event(VK_MENU, 0, 0, 0);
	keybd_event(VK_TAB, 0, 0, 0);
	Sleep(5);
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
	Sleep(5);
	keybd_event(VK_LCONTROL,0 ,0 , 0); 
	keybd_event(VkKeyScan('Y'),0x9e, 0,0);
	keybd_event(VkKeyScan('Y'),0x9e, KEYEVENTF_KEYUP,0); 
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_KEYUP, 0); 
}

//This function is called when user presses MOVE Button
void GimpLeapMaster::GimpLeapMaster::MoveButton_Click2(System::Object^  sender, System::EventArgs^  e)
{
	glEvent.move = true;
}

//This function is called when user presses DRAW Button
void GimpLeapMaster::GimpLeapMaster::PencilButton_Click2(System::Object^  sender, System::EventArgs^  e)
{
	glEvent.move = false;
}

//This function is called when user presses OFF Button
void GimpLeapMaster::GimpLeapMaster::OffButton_Click_2(System::Object^  sender, System::EventArgs^  e)
{
	//ass listener
	controller.addListener(listener);
	controller.setPolicyFlags(Leap::Controller::POLICY_BACKGROUND_FRAMES);
	//loop until controller has focus
	do
	{

	}while(!controller.hasFocus());

	//Turn ON all buttons
	::GimpLeapMaster::GimpLeapMaster::OffButton_Click_1(sender,e);
}

////This function is called when user presses ON Button
void GimpLeapMaster::GimpLeapMaster::OnButton_Click_2(System::Object^  sender, System::EventArgs^  e)
{
	//remove listener
	controller.removeListener(listener);
}


///////// MAIN /////////

[STAThread]
void main(array<String^>^ args) {
   
	while(controller.policyFlags() == Leap::Controller::POLICY_DEFAULT)
	{
		controller.setPolicyFlags(Leap::Controller::POLICY_BACKGROUND_FRAMES);
	}

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Run UI
	GimpLeapMaster::GimpLeapMaster form;
	Application::Run(%form);
}	
