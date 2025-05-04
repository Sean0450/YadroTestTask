#pragma once

#include "Event.h"

class VisitorWaitingEvent : public Event
{
public:
  std::string WorkingWithVisitor(const std::string_view inputInformation, GamingCafeDataManager & gamingCafeDataManger) override;
};
