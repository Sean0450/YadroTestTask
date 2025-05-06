#include "../include/VisitorComingEvent.h"
#include "../include/EventData.h"

void VisitorComingEvent::WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager)
{
  if (gamingCafeDataManager.isVisitorInCafe(data.m_name))
  {
    data.GenerateError(phrases::code13, phrases::shallNotPass);
    return;
  }
  auto compareOpenningHoursAndMinutes = ConvertStringHoursToInt(data.m_time, gamingCafeDataManager.GetWorkingHours().first);
  auto compareClosingHoursAndMinutes = ConvertStringHoursToInt(data.m_time, gamingCafeDataManager.GetWorkingHours().second);
  if (compareOpenningHoursAndMinutes.first < 0 or
      (compareOpenningHoursAndMinutes.first == 0 and compareOpenningHoursAndMinutes.second < 0) or
      compareClosingHoursAndMinutes.first > 0 or
      (compareClosingHoursAndMinutes.first == 0 and compareOpenningHoursAndMinutes.second > 0))
  {
    data.GenerateError(phrases::code13, phrases::notOpenYet);
  }
  else
  {
    gamingCafeDataManager.AddVisitor(data.m_name);
  }
}
