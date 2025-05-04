#pragma once

#include "GamingCafeDataManager.h"

enum class EventTypes
{
  VisitorComing,
  VisitorWantPlay,
  VisitorWait,
  VisitorGoOff
};

class Visitor;

class Event
{
public:
  virtual ~Event() = default;
  virtual std::string WorkingWithVisitor(const std::string_view inputInformation,
                                         GamingCafeDataManager & gamingCafeDataManger) = 0;
};
