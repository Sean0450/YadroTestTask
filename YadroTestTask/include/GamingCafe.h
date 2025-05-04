#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "GamingCafeDataManager.h"
#include "GamingTable.h"
#include "VisitorComingEvent.h"
#include "VisitorLeftEvent.h"
#include "VisitorWaitingEvent.h"
#include "VisitorWantPlayEvent.h"

class GamingCafe
{
  std::unique_ptr<Event> m_activeEvent;
  GamingCafeDataManager m_dataManager;
  bool FormatChecker(int counter, const std::string_view line);
  void EventHandler(const std::string_view event);
  void SwitchEventType(EventTypes eventType);

public:
  void ReadInputFile(const char * fileName);
};

//-----------------------------------------------------------------------------
//С помощью этой функции строки передаются потоку вывода. Благодаря этому вывод легко отслеживать и контролировать.
//--
void PrintOutputEvent(const std::string_view outputEvent);
