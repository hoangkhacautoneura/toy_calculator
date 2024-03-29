#pragma once

#include "IServiceSettingsFactory.hpp"

class CalcServiceSettingsFactory : public IServiceSettingsFactory {

public:

    CalcServiceSettingsFactory();
    shared_ptr<Settings> get_settings() const final;

private:

    std::shared_ptr<Settings> _settings;

};