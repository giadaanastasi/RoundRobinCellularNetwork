#ifndef __ROUNDROBINCELLULARNETWORK_ANTENNA_H_
#define __ROUNDROBINCELLULARNETWORK_ANTENNA_H_

#include <omnetpp.h>
#include "UserInformation.h"
#include "ResourceBlock.h"

#include "Packet_m.h"
#include "Frame_m.h"
#include "PacketCQI_m.h"

#include "constants.h"

using namespace omnetpp;

class Antenna : public cSimpleModule
{
  public:

    struct packet_info_t
    {
        int       recipient;
        bool      served;

        // probabilmente da togliere
        simtime_t arrivalTime;     // inserted into the queue
        simtime_t servedTime;      // removed from the queue
        simtime_t frameTime;       // inserted into the frame
        simtime_t propagationTime; // left the antenna
        int       size;
    };

  private:
    int NUM_USERS;
    std::vector<UserInformation> users;
    cMessage *timer;

    // stuff for roundrobin
    std::vector<UserInformation>::iterator currentUser;
    Frame *frame;

    // Information that are useful for performance evaluation
    std::vector<long> pendingPackets; // a list of the packet being in the current frame
    std::map<long, Antenna::packet_info_t> packetsInformation;

    int  numServedUsersPerTimeslot;
    long numSentBytesPerTimeslot;


    // Signal
    simsignal_t responseTimeGlobal_s;
    simsignal_t numServedUser_s;

    // probabilmente da togliere
    simsignal_t throughput_s;
    simsignal_t numberRB_s;

    // probabilmente da togliere
    virtual simsignal_t createDynamicSignal(std::string prefix, int userId, std::string templateName);

  protected:
    virtual ~Antenna();
    virtual void finish();

    virtual void initialize();

    virtual void handleTimer(cMessage *msg);
    virtual void handleMessage(cMessage *msg);
    virtual void handlePacket(Packet *packet);
    virtual void handleCQI(PacketCQI *notification);

    virtual void downlinkPropagation();
    virtual void createFrame();

    virtual void   initRoundInformation();
    virtual void   roundrobin();
    virtual void   broadcastFrame(Frame *f);
    virtual void   fillFrameWithCurrentUser(std::vector<ResourceBlock>::iterator &from, std::vector<ResourceBlock>::iterator to);
    virtual Frame* vectorToFrame(std::vector<ResourceBlock> &v);
};

#endif
