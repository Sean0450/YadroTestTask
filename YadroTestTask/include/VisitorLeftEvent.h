#pragma once

#include "Event.h"

class VisitorLeftEvent : public Event
{
  std::string WorkingWithVisitor(const std::string_view inputInformation, GamingCafeDataManager & gamingCafeDataManager) override;
};
