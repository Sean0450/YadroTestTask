#include "../include/VisitorLeftEvent.h"

std::string VisitorLeftEvent::WorkingWithVisitor(const std::string_view inputInformation,
                                                 GamingCafeDataManager & gamingCafeDataManager)
{
  auto name = std::string(inputInformation.substr(8));
  if (!gamingCafeDataManager.isVisitorInCafe(name))
  {
    return std::string(inputInformation.substr(0, 5)) + " 13 " + phrases::clientUnknown;
  }
  auto freeTableAndSetNext = gamingCafeDataManager.FreeGamingTable(name, std::string(inputInformation.substr(0, 5)));
  if (freeTableAndSetNext.has_value())
  {
    return std::string(inputInformation.substr(0, 5)) + " 12 " + freeTableAndSetNext.value().first + " " +
           freeTableAndSetNext.value().second;
  }
  return {};
}
