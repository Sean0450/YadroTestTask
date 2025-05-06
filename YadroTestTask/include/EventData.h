#pragma once

#include <optional>
#include <string>

#include "Event.h"

struct EventData
{
  std::string m_time;
  std::string m_name;
  EventTypes m_eventType;
  std::optional<int> m_tableNumber;
  EventData(std::string_view data);
  void GenerateError(const std::string & errorCode, const std::string & data);
  void GenerateOutput(const std::string & errorCode, const std::pair<std::string, std::string> & visitorData);
  std::string_view GetOutputData() const;

private:
  std::string m_outputData;
};
