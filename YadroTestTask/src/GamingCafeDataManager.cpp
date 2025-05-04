#include "../include/GamingCafeDataManager.h"
#include "../include/GamingTable.h"


void GamingCafeDataManager::AddVisitor(const std::string & name)
{
  m_visitors.insert(std::string(name));
}

bool GamingCafeDataManager::isVisitorInCafe(const std::string & name) const
{
  return m_visitors.find(name) != m_visitors.end();
}

void GamingCafeDataManager::SetGamingTablesCount(int tablesCount)
{
  m_gamingTables.resize(tablesCount);
}

void GamingCafeDataManager::SetPaymentPerHour(int paymentPerHour)
{
  m_paymentPerHour = paymentPerHour;
}

void GamingCafeDataManager::SetWorkingHours(const std::string & workingHours)
{
  m_workHours.first = workingHours.substr(0, 5);
  m_workHours.second = workingHours.substr(6);
}

bool GamingCafeDataManager::OccupiedGamingTable(const std::string & visitorName, const std::string & time, int gamingTableNumber)
{
  if (!m_gamingTables[gamingTableNumber - 1].GetVisitor().empty())
  {
    return false;
  }
  for (auto && gamingTable : m_gamingTables)
  {
    if (gamingTable.GetVisitor() == visitorName)
    {
      gamingTable.ClearGamingTable(time);
      break;
    }
  }
  m_gamingTables[gamingTableNumber - 1].SetVisitor(visitorName, time);
  return true;
}

const std::pair<std::string, std::string> & GamingCafeDataManager::GetWorkingHours() const
{
  return m_workHours;
}

bool GamingCafeDataManager::HasFreeGamingTable() const
{
  return std::ranges::find_if(m_gamingTables, [&](auto & gamingTable) { return gamingTable.GetVisitor().empty(); }) !=
         m_gamingTables.end();
}

bool GamingCafeDataManager::AddVisitorToQueue(const std::string & visitor)
{
  if (m_queue.size() + 1 > m_gamingTables.size())
  {
    m_visitors.erase(visitor);
    return false;
  }
  if (std::ranges::find(m_queue, visitor) == m_queue.end())
  {
    m_queue.emplace_back(std::string(visitor));
    return true;
  }
}

std::optional<std::pair<std::string, std::string>> GamingCafeDataManager::FreeGamingTable(const std::string & name,
                                                                                          const std::string & time)
{
  m_visitors.erase(name);
  auto comparator = [&](auto & gamingTable)
  {
    return gamingTable.GetVisitor() == name;
  };
  if (auto gamingTable = std::ranges::find_if(m_gamingTables, comparator); gamingTable != m_gamingTables.end())
  {
    (*gamingTable).ClearGamingTable(time);
    if (!m_queue.empty())
    {
      (*gamingTable).SetVisitor(m_queue.front(), time);
      auto visitorName = m_queue.front();
      m_queue.erase(m_queue.begin());
      return std::pair<std::string, std::string>(visitorName,
                                                 std::to_string(std::distance(m_gamingTables.begin(), gamingTable) + 1));
    }
  }
  return std::nullopt;
}

void GamingCafeDataManager::CloseGamingCafe(std::function<void(std::string_view)> printFunction)
{
  m_queue.clear();
  for (auto && visitor : m_visitors)
  {
    printFunction(m_workHours.second + " 11 " + visitor);
  }
  for (auto && gamingTable : m_gamingTables)
  {
    if (!gamingTable.GetVisitor().empty())
    {
      FreeGamingTable(std::string(gamingTable.GetVisitor()), m_workHours.second);
    }
  }
  printFunction(m_workHours.second);
  printFunction(CalculateIncome());
}

std::string GamingCafeDataManager::CalculateIncome()
{
  std::string result;
  for (int i = 0; i < m_gamingTables.size(); ++i)
  {
    int income = m_gamingTables[i].GetGamingTableWorkingTime().second > 0
                 ? (m_gamingTables[i].GetGamingTableWorkingTime().first + 1) * m_paymentPerHour
                 : m_gamingTables[i].GetGamingTableWorkingTime().first * m_paymentPerHour;
    result += std::to_string(i + 1) + " " + std::to_string(income) + " " +
              ConvertIntHoursToString(m_gamingTables[i].GetGamingTableWorkingTime()) + '\n';
  }
  return result;
}

std::pair<int, int> ConvertStringHoursToInt(const std::string & actualTime, const std::string & comparableTime)
{
  int hours = std::stoi(actualTime.substr(0, 2)) - std::stoi(comparableTime.substr(0, 2));
  int minutes = std::stoi(actualTime.substr(3, 2)) - std::stoi(comparableTime.substr(3, 2));
  if (minutes < 0)
  {
    hours--;
    minutes += 60;
  }
  return {hours, minutes};
}

std::string ConvertIntHoursToString(const std::pair<int, int> & time)
{
  std::string stringTime;
  if (time.first < 10)
  {
    stringTime += "0" + std::to_string(time.first);
  }
  else
  {
    stringTime += std::to_string(time.first);
  }
  stringTime += ":";
  if (time.second < 10)
  {
    stringTime += "0" + std::to_string(time.second);
  }
  else
  {
    stringTime += std::to_string(time.second);
  }
  return stringTime;
}
