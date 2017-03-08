#ifndef GROUND
#define GROUND

// Game includes
#include "Game/Location.h"

class Ground : public Location {
public:
	Ground();
	virtual std::string getDescription() const;
protected:
private:
};

#endif // GROUND
