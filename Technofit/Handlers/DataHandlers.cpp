#include "DataHandlers.h"
#include <iostream>

void DeviceDataHandler::service(IRequest &request, IResponse &response)
{
    // получает данные в виде json в request`e из девайса
    // преобразует их в плюсовые структуры 

    // ....

    //  сохраняет их в бд

    //....
}

void ClientDataHandler::service(IRequest &request, IResponse &response)
{
    std::vector<unsigned char>& vc = request.GetBody();
    //std::vector<unsigned char>& vc;
    std::string reply_ = usecase_->ProcessRequest(vc);
    // получает запрос от клиента на отображение данных 
    // вызывает функцию, достаёт из бд данные
    // отправляет клиенту
    std::vector<unsigned char> reply(reply_.begin(), reply_.end());
    std::cout << "ready to write into response" << std::endl;
    response.write(reply);
}

void ClientMLHandler::service(IRequest &request, IResponse &response)
{
    // получает запрос от клиента на прогнозирование данных 

    // вызывает функцию которая прогнозируется данные и отдаёт их

    // преобразует в json отправляет клиенту
}
