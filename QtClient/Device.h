#pragma once
#include <QString>

class IDevice
{
public:
    virtual float get_pulse() = 0;
    virtual float get_O2() = 0;
    virtual float get_temprature() = 0;
    virtual QString get_name() = 0;
    virtual void set_pulse(float pulse) = 0;
    virtual void set_O2(float O2) = 0;
    virtual void set_temprature(float temprature) = 0;
    virtual void set_name(QString name) = 0;
    virtual void set_params(float pulse, float O2, float temprature, QString name) = 0;
};

class Device : public IDevice
{
public:
    float get_O2() override;
    float get_temprature() override;
    float get_pulse() override;
    QString get_name() override;
    void set_pulse(float _pulse) override
    {
        pulse = _pulse;
    }
    void set_O2(float _O2) override
    {
        O2 = _O2; 
    }
    void set_temprature(float _temprature) override
    {
        temprature = _temprature;
    }
    void set_name(QString _name) override
    {
        name = _name;
    }
    void set_params(float _pulse, float _O2, float _temprature, QString _name) override
    {
        pulse = _pulse;
        O2 = _O2; 
        temprature = _temprature;
        name = _name;
    }
private:
    float pulse;
    float O2;
    float temprature;
    QString name;
};