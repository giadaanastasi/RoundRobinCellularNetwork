#ifndef USERINFORMATION_H_
#define USERINFORMATION_H_

#include <omnetpp.h>
#include <vector>
#include "ResourceBlock.h"

class UserInformation {
private:
    omnetpp::cQueue *FIFOQueue;
    int CQI;

public: // too much stuff
    std::vector<ResourceBlock>::iterator lastRB;
    double remainingBytes;

public:
    UserInformation();
    virtual ~UserInformation();
    virtual void generateCQI();

    virtual int              CQIToBytes();
    virtual omnetpp::cQueue* getQueue();
};

#endif /* USERINFORMATION_H_ */
