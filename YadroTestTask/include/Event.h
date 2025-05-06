#pragma once

#include "GamingCafeDataManager.h"

enum class EventTypes
{
  VisitorComing,
  VisitorWantPlay,
  VisitorWait,
  VisitorGoOff
};

class EventData;

class Event
{
public:
  virtual ~Event() = default;
  virtual void WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManger) = 0;
};
