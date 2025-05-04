#include "../include/VisitorWantPlayEvent.h"

std::string VisitorWantPlayEvent::WorkingWithVisitor(const std::string_view inputInformation,
                                                     GamingCafeDataManager & gamingCafeDataManager)
{
  auto name = std::string(inputInformation.substr(8));
  auto time = std::string(inputInformation.substr(0, 5));
  auto space = name.find(" ");
  int gamingTableNumber = std::stoi(name.substr(space + 1));
  auto rightName = name.substr(0, space);
  if (!gamingCafeDataManager.isVisitorInCafe(rightName))
  {
    return time + " 13 " + phrases::clientUnknown;
  }
  else if (!gamingCafeDataManager.OccupiedGamingTable(rightName, time, gamingTableNumber))
  {
    return time + " 13 " + phrases::placeBusy;
  }
  return {};
}
