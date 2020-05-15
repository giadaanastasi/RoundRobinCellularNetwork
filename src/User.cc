#include "User.h"

Define_Module(User);

int User::NEXT_USER_ID;

void User::initialize()
{
    userID = NEXT_USER_ID++;
}

void User::sendCQI(){
    simtime_t lambda = par("lambda");
    bool isBinomial = par("isBinomial");
    double successProbGroup1 = par("successProbGroup1");
    double successProbGroup2 = par("successProbGroup2");
    double successProbGroup3 = par("successProbGroup3");

    double p =  ((it->getId()) % 2 == 0)? successProbGroup3: successProbGroup1;
    int cqi = (isBinomial)?binomial(BINOMIAL_N, p,RNG_CQI_BIN)+1:intuniform(MIN_CQI, MAX_CQI, RNG_CQI_UNI);


    PacketTimer *pt = new PacketTimer();
    pt->setKind(MSG_PKT_TIMER);
    pt->setUserId(userID);

    scheduleAt(simTime() + exponential(lambda, RNG_INTERARRIVAL),pt);
    PacketCQI *newCQI = new PacketCQI();
    newCQI->setUserId(userID);
    newCQI->setKind(MSG_CQI);

}

void User::handleMessage(cMessage *msg)
{
        Frame *f = check_and_cast<Frame*>(msg);
        handleFrame(f);
}



void User::handleFrame(Frame* f)
{
    EV << "[USER] I have received a frame... Here is the content:" << endl;
    for(int i =0; i<FRAME_SIZE; i++)
    {
        if(f->getRBFrame(i).getRecipient()==userID)
        {
            int numFragments = f->getRBFrame(i).getNumFragments();
            EV << "[USER] There are " << numFragments << " fragments" << endl;
            for(int j = 0; j < numFragments; j++)
            {
                EV << "   ID PKT:   " << f->getRBFrame(i).getFragment(j).id << endl;
                EV << "   PKT SIZE: " <<  f->getRBFrame(i).getFragment(j).packetSize << endl;
                EV << "   FRG SIZE: " <<  f->getRBFrame(i).getFragment(j).fragmentSize << endl;
            }
        }
    }
    delete(f);
}


