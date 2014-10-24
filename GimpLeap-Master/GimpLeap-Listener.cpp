#include "Leap.h"

using namespace Leap;


class GimpLeapListener : public Listener {
  public:
    virtual void onInit(const Controller&);					// function when the listener is ready for use
    virtual void onConnect(const Controller&);				// when a connection is established between the controller and the Leap Motion software
    virtual void onDisconnect(const Controller&);			// if the controller loses its connection with the Leap Motion software or device
    virtual void onExit(const Controller&);					// if the listener is removed from the controller
    virtual void onFrame(const Controller&);				// function each time a new frame is available


	long timestampNow;					//current timestamp
	long timestampPrevious;				//previous timestamp
	long timestampDifference;			//timestamp difference

  private:  
	  
};