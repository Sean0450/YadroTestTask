#pragma once

#include "Event.h"

class VisitorComingEvent : public Event
{
public:
  void WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager) override;
};
