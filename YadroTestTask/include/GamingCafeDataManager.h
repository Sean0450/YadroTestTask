#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <set>
#include <vector>

#include "Resources.h"

class GamingTable;

class GamingCafeDataManager
{
  //-----------------------------------------------------------------------------
  //В целом можно обойтись и без дополнительного контейнера для клиентов, но тогда
  //часто используемая операция проверки присутствия клиента в клубе будет выполняться намного дольше. Плюс поддерживается упорядоченность, что необходимо по условию.
  //--
  std::set<std::string> m_visitors;
  int m_paymentPerHour = 0;
  std::pair<std::string, std::string> m_workHours;
  std::vector<GamingTable> m_gamingTables;
  std::vector<std::string> m_queue;

  std::string CalculateIncome();

public:
  void AddVisitor(const std::string & name);
  void SetGamingTablesCount(int tablesCount);
  void SetPaymentPerHour(int payment);
  void SetWorkingHours(const std::string & workHours);
  const std::pair<std::string, std::string> & GetWorkingHours() const;
  bool OccupiedGamingTable(const std::string & visitorName, const std::string & time, int gamingTableNumber);
  bool isVisitorInCafe(const std::string & name) const;
  bool HasFreeGamingTable() const;
  bool AddVisitorToQueue(const std::string & visitor);
  std::optional<std::pair<std::string, std::string>> FreeGamingTable(const std::string & name, const std::string & time);
  void CloseGamingCafe(std::function<void(std::string_view)> printFunction);
};

std::string ConvertIntHoursToString(const std::pair<int, int> & time);

std::pair<int, int> ConvertStringHoursToInt(const std::string & time, const std::string & comparableTime);
