#include "../include/VisitorWaitingEvent.h"

std::string VisitorWaitingEvent::WorkingWithVisitor(const std::string_view inputInformation,
                                                    GamingCafeDataManager & gamingCafeDataManager)
{
  auto name = std::string(inputInformation.substr(8));
  if (gamingCafeDataManager.HasFreeGamingTable())
  {
    return std::string(inputInformation.substr(0, 5)) + " 13 " + phrases::cantWait;
  }
  if (!gamingCafeDataManager.AddVisitorToQueue(name))
  {
    return std::string(inputInformation.substr(0, 5)) + " 11 " + name;
  }
  return {};
}
