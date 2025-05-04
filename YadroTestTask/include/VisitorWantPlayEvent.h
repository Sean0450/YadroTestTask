#pragma once

#include "Event.h"

class VisitorWantPlayEvent : public Event
{
public:
  std::string WorkingWithVisitor(const std::string_view inputInformation, GamingCafeDataManager & gamingCafeDataManager) override;
};
