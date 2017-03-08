#ifndef LOCATION
#define LOCATION

// std includes
#include <string>
#include <vector>
#include <algorithm>

// Game includes
#include "Game/Object.h"

class Location {
public:
	std::string getName() const;

	void addObject(Object*);
	void eraseObject(Object*);
	void eraseObject(int i);
	const std::vector<Object*> getObjects() const;

	virtual std::string getDescription() const;
protected:
	void setName(std::string);
private:
	std::string mName;
	std::vector<Object*> mObjects;
};

#endif // LOCATION
