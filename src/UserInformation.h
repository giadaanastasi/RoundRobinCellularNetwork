#ifndef USERINFORMATION_H_
#define USERINFORMATION_H_

#include <omnetpp.h>
#include <vector>
#include "ResourceBlock.h"
#include "constants.h"

class UserInformation {
private:
    int id;
    omnetpp::cQueue FIFOQueue;

    int CQI;
    int numPendingPackets;
    int numberRBs;
    long numServed;
    
    int  servedBytes;
    bool served;

public:
    // probabilmente da togliere
    omnetpp::simsignal_t throughput_s;
    omnetpp::simsignal_t responseTime_s;
    omnetpp::simsignal_t CQI_s;
    omnetpp::simsignal_t numberRBs_s;
    omnetpp::simsignal_t served_s;

public:
    UserInformation(int id);
    virtual ~UserInformation();

    virtual int getId();
    virtual int              CQIToBytes();
    virtual omnetpp::cQueue* getQueue();

    virtual long getNumServed();
    virtual void setCQI(int cqi);
    virtual int  getCQI();

    virtual void serveUser();
    virtual bool isServed();
    virtual void shouldBeServed();

    virtual void incrementNumPendingPackets();
    virtual void setNumPendingPackets(int val);
    virtual void initNumPendingPackets();
    virtual int  getNumPendingPackets();


    virtual void incrementServedBytes(int bytes);
    virtual int  getServedBytes();
    virtual void incrementNumberRBs();
    virtual int  getNumberRBs();
    virtual void setNumberRBs(int n);
};

#endif /* USERINFORMATION_H_ */
