#ifndef OBJECT
#define OBJECT

// std includes
#include <string>

class Object {
public:
	std::string getName() const;
	std::string getDeterminer() const;
protected:
	void setName(std::string);
	void setDeterminer(std::string);
private:
	std::string mName;
	std::string mDeterminer;
};

#endif // OBJECT
