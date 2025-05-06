#include "../include/VisitorWaitingEvent.h"

#include "../include/EventData.h"

void VisitorWaitingEvent::WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager)
{
  if (gamingCafeDataManager.HasFreeGamingTable())
  {
    data.GenerateError(phrases::code13, phrases::cantWait);
    return;
  }
  if (!gamingCafeDataManager.AddVisitorToQueue(data.m_name))
  {
    data.GenerateError(phrases::code11, data.m_name);
  }
}
