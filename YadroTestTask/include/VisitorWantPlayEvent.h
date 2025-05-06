#pragma once

#include "Event.h"

class VisitorWantPlayEvent : public Event
{
public:
  void WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager) override;
};
