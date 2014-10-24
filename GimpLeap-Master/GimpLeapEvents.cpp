#include <windows.h>
#include <string.h>
#include "Leap.h"

using namespace std;
using namespace Leap;

class GimpLeapEvent 
{
	public:

		//Initialization
		GimpLeapEvent(void)
		{
			isRotating = false;
			isResizing = false;
			clickOnHold = false;
			sizeIncreasing = false;
			sizeDecreasing = false;
			move = true;
			previousgrabStrength = NULL;		
		}

		//Function to move the cursor
		void moveCursor(Finger finger, Leap::Screen screen)
		{

			if (screen.isValid())
			{
				float velocity = finger.tipVelocity().magnitude();

				if(velocity > 6.5)
				{
					float xScreenIntersect = screen.intersect(finger,true).x;
					float yScreenIntersect = screen.intersect(finger,true).y;

					if(to_string(xScreenIntersect) != "Nan")
					{
						int x = (int)(xScreenIntersect * screen.widthPixels());
						int y = (int)(screen.heightPixels() - (yScreenIntersect * screen.heightPixels()));
			
						SetCursorPos(x, y);
					}
				}
			}
		}

		//Simulate a mouse press, with move as selected function
		void Drag(FingerList fingers)
		{
			keybd_event(VkKeyScan('M'),0x9e, 0,0);
			keybd_event(VkKeyScan('M'),0x9e, KEYEVENTF_KEYUP,0); 

			Input.type        = INPUT_MOUSE;									
			Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;							
			SendInput( 1, &Input, sizeof(INPUT) );								
	
			clickOnHold = true;
		}

		//Simulate mouse press, with draw as selected function
		void Draw(FingerList fingers)
		{
			keybd_event(VkKeyScan('N'),0x9e, 0,0);
			keybd_event(VkKeyScan('N'),0x9e, KEYEVENTF_KEYUP,0); 

			Input.type        = INPUT_MOUSE;									
			Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;							
			SendInput( 1, &Input, sizeof(INPUT) );								
	
			clickOnHold = true;
		}

		//Call gimp rotate function
		void startRotate()
		{
			keybd_event(VK_LSHIFT,0 ,0 , 0); 
			keybd_event(VkKeyScan('R'),0x9e, 0,0);
			keybd_event(VkKeyScan('R'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); 

			isRotating = true;
		}

		//Rotate image clockwise
		void rotateRight()
		{
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('A'),0x9e, 0,0);
			keybd_event(VkKeyScan('A'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_UP, 0, 0, 0); 
			keybd_event(VK_UP,0, KEYEVENTF_KEYUP, 0); 
		}

		//Rotate image counter-clockwise
		void rotateLeft()
		{
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('A'),0x9e, 0,0);
			keybd_event(VkKeyScan('A'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_DOWN, 0, 0, 0); 
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0); 
		}

		//Call gimp scale function
		void startResize()
		{
			keybd_event(VK_LSHIFT,0 ,0 , 0); 
			keybd_event(VkKeyScan('T'),0x9e, 0,0);
			keybd_event(VkKeyScan('T'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); 

			isResizing = true;
		}

		//Increase length and width of image
		void increaseSize()
		{
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('W'),0x9e, 0,0);
			keybd_event(VkKeyScan('W'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_UP, 0, 0, 0); 
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_UP, 0, 0, 0); 
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('E'),0x9e, 0,0);
			keybd_event(VkKeyScan('E'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_UP, 0, 0, 0); 
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0); 
			keybd_event(VK_UP, 0, 0, 0); 
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
		}

		//Decrease length and width of image
		void decreaseSize()
		{
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('W'),0x9e, 0,0);
			keybd_event(VkKeyScan('W'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_DOWN, 0, 0, 0); 
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_DOWN, 0, 0, 0); 
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_MENU, 0, 0, 0);
			keybd_event(VkKeyScan('E'),0x9e, 0,0);
			keybd_event(VkKeyScan('E'),0x9e, KEYEVENTF_KEYUP,0); 
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_DOWN, 0, 0, 0); 
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0); 
			keybd_event(VK_DOWN, 0, 0, 0); 
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
		}

		bool isRotating;		//state when rotating
		bool isResizing;		//state when resizing
		bool clickOnHold;		//state when left mouse button is down
		bool sizeIncreasing;	//state when increasing size
		bool sizeDecreasing;	//state when decreasing size
		bool move;				// state when move function is selected

		int grabStrength;			
		int previousgrabStrength;

		INPUT Input;			

	private:
};
