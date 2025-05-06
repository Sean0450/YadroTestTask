#include "../include/VisitorLeftEvent.h"

#include "../include/EventData.h"


void VisitorLeftEvent::WorkingWithVisitor(EventData & data, GamingCafeDataManager & gamingCafeDataManager)
{
  if (!gamingCafeDataManager.isVisitorInCafe(data.m_name))
  {
    data.GenerateError(phrases::code13, phrases::clientUnknown);
    return;
  }
  auto freeTableAndSetNext = gamingCafeDataManager.FreeGamingTable(data.m_name, data.m_time);
  if (freeTableAndSetNext.has_value())
  {
    data.GenerateOutput(phrases::code12, freeTableAndSetNext.value());
  }
}
