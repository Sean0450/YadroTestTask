#include "../include/GamingCafe.h"

bool GamingCafe::FormatChecker(int counter, const std::string_view line)
{
  if (counter == 0 or counter == 2)
  {
    return line.find(" ") == std::string_view::npos;
  }
  return line.size() > 8 and line.find(" ") != std::string_view::npos;
}
void GamingCafe::ReadInputFile(const char * fileName)
{
  std::ifstream file(fileName);
  if (file.is_open())
  {
    std::string line;
    int counter = 0;
    while (std::getline(file, line))
    {
      if (!FormatChecker(counter, line))
      {
        PrintOutputEvent(line);
        return;
      }
      if (counter == 0)
      {
        m_dataManager.SetGamingTablesCount(std::stoi(line));
      }
      else if (counter == 1)
      {
        m_dataManager.SetWorkingHours(line);
        PrintOutputEvent(line.substr(0, 5));
      }
      else if (counter == 2)
      {
        m_dataManager.SetPaymentPerHour(std::stoi(line));
      }
      else
      {
        EventHandler(std::string_view{line});
      }
      counter++;
    }
    m_dataManager.CloseGamingCafe(PrintOutputEvent);
    file.close();
  }
  else
  {
    throw std::runtime_error("File can't be opened");
  }
}

void GamingCafe::EventHandler(const std::string_view event)
{
  PrintOutputEvent(event);
  auto eventID = static_cast<EventTypes>(std::stoi(std::string(event.substr(6, 1))) - 1);
  SwitchEventType(eventID);
  auto action = m_activeEvent->WorkingWithVisitor(event, m_dataManager);
  if (!action.empty())
  {
    PrintOutputEvent(action);
  }
}

void GamingCafe::SwitchEventType(EventTypes eventType)
{
  switch (eventType)
  {
    case EventTypes::VisitorComing:
    {
      m_activeEvent = std::make_unique<VisitorComingEvent>();
      break;
    }
    case EventTypes::VisitorWantPlay:
    {
      m_activeEvent = std::make_unique<VisitorWantPlayEvent>();
      break;
    }
    case EventTypes::VisitorWait:
    {
      m_activeEvent = std::make_unique<VisitorWaitingEvent>();
      break;
    }
    case EventTypes::VisitorGoOff:
    {
      m_activeEvent = std::make_unique<VisitorLeftEvent>();
      break;
    }
  }
}

void PrintOutputEvent(const std::string_view outputEvent)
{
  std::cout << outputEvent << std::endl;
}
