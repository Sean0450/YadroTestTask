#include "../include/VisitorComingEvent.h"

std::string VisitorComingEvent::WorkingWithVisitor(const std::string_view inputInformation,
                                                   GamingCafeDataManager & gamingCafeDataManager)
{
  auto time = std::string(inputInformation.substr(0, 5));
  auto name = std::string(inputInformation.substr(8));
  if (gamingCafeDataManager.isVisitorInCafe(name))
  {
    return time + " 13 " + phrases::shallNotPass;
  }
  auto compareOpenningHoursAndMinutes = ConvertStringHoursToInt(time, gamingCafeDataManager.GetWorkingHours().first);
  auto compareClosingHoursAndMinutes = ConvertStringHoursToInt(time, gamingCafeDataManager.GetWorkingHours().second);
  if (compareOpenningHoursAndMinutes.first < 0 or
      (compareOpenningHoursAndMinutes.first == 0 and compareOpenningHoursAndMinutes.second < 0) or
      compareClosingHoursAndMinutes.first > 0 or
      (compareClosingHoursAndMinutes.first == 0 and compareOpenningHoursAndMinutes.second > 0))
  {
    return time + " 13 " + phrases::notOpenYet;
  }
  gamingCafeDataManager.AddVisitor(name);
  return {};
}
