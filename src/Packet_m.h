//
// Generated file, do not edit! Created by nedtool 5.5 from Packet.msg.
//

#ifndef __PACKET_M_H
#define __PACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Packet.msg:1</tt> by nedtool.
 * <pre>
 * message Packet
 * {
 *     int senderID;
 *     int receiverID;
 *     int serviceDemand;
 *     simtime_t arrivalTime;
 *     simtime_t startTime;
 *     simtime_t FrameTime;
 *     simtime_t EndService;
 * }
 * </pre>
 */
class Packet : public ::omnetpp::cMessage
{
  protected:
    int senderID;
    int receiverID;
    int serviceDemand;
    ::omnetpp::simtime_t arrivalTime;
    ::omnetpp::simtime_t startTime;
    ::omnetpp::simtime_t FrameTime;
    ::omnetpp::simtime_t EndService;

  private:
    void copy(const Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Packet&);

  public:
    Packet(const char *name=nullptr, short kind=0);
    Packet(const Packet& other);
    virtual ~Packet();
    Packet& operator=(const Packet& other);
    virtual Packet *dup() const override {return new Packet(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSenderID() const;
    virtual void setSenderID(int senderID);
    virtual int getReceiverID() const;
    virtual void setReceiverID(int receiverID);
    virtual int getServiceDemand() const;
    virtual void setServiceDemand(int serviceDemand);
    virtual ::omnetpp::simtime_t getArrivalTime() const;
    virtual void setArrivalTime(::omnetpp::simtime_t arrivalTime);
    virtual ::omnetpp::simtime_t getStartTime() const;
    virtual void setStartTime(::omnetpp::simtime_t startTime);
    virtual ::omnetpp::simtime_t getFrameTime() const;
    virtual void setFrameTime(::omnetpp::simtime_t FrameTime);
    virtual ::omnetpp::simtime_t getEndService() const;
    virtual void setEndService(::omnetpp::simtime_t EndService);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Packet& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Packet& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PACKET_M_H

