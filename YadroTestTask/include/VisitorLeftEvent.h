#pragma once

#include "Event.h"

class VisitorLeftEvent : public Event
{
  void WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager) override;
};
