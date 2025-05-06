#include "../include/VisitorWantPlayEvent.h"
#include "../include/EventData.h"


void VisitorWantPlayEvent::WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager)
{
  if (!gamingCafeDataManager.isVisitorInCafe(data.m_name))
  {
    data.GenerateError(phrases::code13, phrases::clientUnknown);
    return;
  }
  else if (!gamingCafeDataManager.OccupiedGamingTable(data.m_name, data.m_time, data.m_tableNumber.value()))
  {
    data.GenerateError(phrases::code13, phrases::placeBusy);
  }
}
