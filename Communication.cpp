#include "Communication.h"
#include <iostream>


void legacyEmailService::dispatchMail(std::string address, std::string subject, std::string body){
  std::cout << "|--------\n| Emailing: " << address << "\n| Subject: " << subject << "\n|\n| " << body << "\n|--------\n";
}

alertSender::~alertSender() { }

smsService::smsService(legacyEmailService* l) : legacyService(l) { }

void smsService::sendAlert(std::string recipients, std::string message){
  legacyService->dispatchMail(recipients, "ALERT", message);
}

