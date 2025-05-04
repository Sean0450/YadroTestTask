#pragma once

#include <string>

#include "GamingCafeDataManager.h"


class GamingTable
{
  std::string m_visitorName;
  std::string m_lastSavedTime;
  std::pair<int, int> m_gamingTableWorkingTime;

public:
  std::string_view GetVisitor() const;
  void ClearGamingTable(const std::string & time);
  void SetVisitor(const std::string_view visitorName, const std::string & time);
  const std::pair<int, int> & GetGamingTableWorkingTime() const;
};
