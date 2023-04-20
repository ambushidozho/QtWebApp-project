#include "DataHandlers.h"



void DeviceHandler::service(IRequest &request, IResponse &response)
{
    // получает данные в виде json в request`e из девайса
    // преобразует их в плюсовые структуры 

    // ....

    //  сохраняет их в бд

    //....
}


void ClientDataHandler::service(IRequest &request, IResponse &response)
{
    // получает запрос от клиента на отображение данных 

    // вызывает функцию, достаёт из бд данные

    // преобразует в json отправляет клиенту
}

void ClientMLHandler::service(IRequest &request, IResponse &response)
{
    // получает запрос от клиента на прогнозирование данных 

    // вызывает функцию которая прогнозируется данные и отдаёт их

    // преобразует в json отправляет клиенту
}
