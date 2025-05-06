#include "../include/GamingTable.h"


std::string_view GamingTable::GetVisitor() const
{
  return m_visitorName;
}

void GamingTable::SetVisitor(const std::string_view visitorName, const std::string & time)
{
  m_visitorName = std::string(visitorName);
  m_lastSavedTime = time;
}

void GamingTable::ClearGamingTable(const std::string & time)
{
  m_visitorName.clear();
  auto hoursAndMinutes = ConvertStringHoursToInt(time, m_lastSavedTime);
  m_gamingTableWorkingTime.first += hoursAndMinutes.first;
  m_gamingTableWorkingTime.second += hoursAndMinutes.second;
  if (m_gamingTableWorkingTime.second >= 60)
  {
    m_gamingTableWorkingTime.first++;
    m_gamingTableWorkingTime.second -= 60;
  }
}


const std::pair<int, int> & GamingTable::GetGamingTableWorkingTime() const
{
  return m_gamingTableWorkingTime;
}
