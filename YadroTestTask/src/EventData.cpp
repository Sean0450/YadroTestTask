#include "../include/EventData.h"

EventData::EventData(std::string_view data)
{
  m_eventType = static_cast<EventTypes>(std::stoi(std::string(data.substr(6, 1))) - 1);
  m_time = std::string(data.substr(0, 5));
  m_name = std::string(data.substr(8));
  if (m_eventType == EventTypes::VisitorWantPlay)
  {
    auto space = m_name.find(" ");
    m_tableNumber = std::stoi(std::string(m_name.substr(space + 1)));
    m_name = m_name.substr(0, space);
  }
}

void EventData::GenerateError(const std::string & errorCode, const std::string & data)
{
  m_outputData = m_time + " " + errorCode + " " + data;
}

void EventData::GenerateOutput(const std::string & errorCode, const std::pair<std::string, std::string> & visitorData)
{
  m_outputData = m_time + " " + errorCode + " " + visitorData.first + " " + visitorData.second;
}

std::string_view EventData::GetOutputData() const
{
  return m_outputData;
}
