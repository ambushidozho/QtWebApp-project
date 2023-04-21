#pragma once
#include <QNetworkAccessManager>


// singleton класс для работы с http 
class QNetworkAccessManagerWrapper
{
    static QNetworkAccessManager* m_QNetworkAccessManager;
public:
    static QNetworkAccessManager* getQNetworkAccessManager()
    {
        Q_ASSERT_X(m_QNetworkAccessManager,"QNAMwrapper","You must create an instance of QNAMwrapper before using the QNAM");
        return m_QNetworkAccessManager;
    }
    QNetworkAccessManagerWrapper()
    {
        Q_ASSERT_X(!m_QNetworkAccessManager,"QNAMwrapper","Only one instance of QNAMwrapper can be created");
        if(!m_QNetworkAccessManager)
        m_QNetworkAccessManager = new QNetworkAccessManager;
    }
    ~QNetworkAccessManagerWrapper()
    {
        delete m_QNetworkAccessManager;
        m_QNetworkAccessManager = Q_NULLPTR;
    }
};