#include "MetricsUseCase.h"



void MetricsUseCase::RefreshData(int user_id)
{
   network_.FetchStatistics(user_id);
} 


void MetricsUseCase::OnFetchStatistics(Device& device)
{
   ui.UpdateResults(device);
}