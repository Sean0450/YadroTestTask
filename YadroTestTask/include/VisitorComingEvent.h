#pragma once

#include "Event.h"

class VisitorComingEvent : public Event
{
public:
  std::string WorkingWithVisitor(const std::string_view inputInformation, GamingCafeDataManager & gamingCafeDataManager) override;
};
