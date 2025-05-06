#pragma once

#include "Event.h"

class VisitorWaitingEvent : public Event
{
public:
  void WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManger) override;
};
