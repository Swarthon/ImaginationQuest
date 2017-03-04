#ifndef EVENT
#define EVENT

class Event {
public:
	virtual std::string getType() const {
		return mType;
	}
protected:
	virtual void setType(std::string name){
		mType = name;
	}
private:
	std::string mType;
};

#endif // EVENT
