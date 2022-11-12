#pragma once

// has pointer to mes
// push design to inherit class to desigh they own event
// let 

class Event
{
public:
	Event(void* _message) : message(_message) {};
	virtual ~Event() { delete message; };
	void* GetUserData() { return message; };
private:
	void* message;
};