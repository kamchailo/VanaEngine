#pragma once

class Event
{
public:
	Event(void* _message) : message(_message) {};
	virtual ~Event() { delete message; };
	void* GetUserData() { return message; };
private:
	void* message;
};