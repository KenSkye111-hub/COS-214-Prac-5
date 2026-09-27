#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>

//adaptee
class legacyEmailService{
  public:
    void dispatchMail(std::string address, std::string subject, std::string body);
};

class alertSender{ //actual interface with the CommunicationSystem
  public:
    virtual void sendAlert(std::string recipients, std::string message) =0;
    virtual ~alertSender();
};

//adapter
class smsService : public alertSender{
  private:
    legacyEmailService* legacyService;
  public:
    smsService(legacyEmailService* l);
    void sendAlert(std::string , std::string) override;
};

#endif