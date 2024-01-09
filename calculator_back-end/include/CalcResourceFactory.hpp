#pragma once

#include "IResourceFactory.hpp"
#include <string>
#include <tuple>
#include "IServiceSettingsFactory.hpp"
#include <restbed>

class CalcResourceFactory : public IResourceFactory
{

public:
  CalcResourceFactory();
  shared_ptr<Resource> get_resource() const final;

private:
  shared_ptr<Resource> _resource;
  void get_handler(const shared_ptr<Session> session);
  tuple<float, float, string>
  get_path_parameters(const shared_ptr<Session> session) const;
  float calculate(float num1, float num2, string operation);
  string to_json(float result);
};