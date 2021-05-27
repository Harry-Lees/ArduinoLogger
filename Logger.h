#pragma once

#include "Arduino.h"

enum level {
 DEBUG,
 INFO,
 WARNING,
 ERROR,
};

class BaseHandler {
  public:
    virtual void emit(String, String);
  protected:
    level _level; // TODO: implement level handling
};

class UsbSerialHandler: public BaseHandler {
  public:
    UsbSerialHandler(int, level);
};

class Rs232SerialHandler: public BaseHandler {
  public:
    Rs232SerialHandler(int, level);
};

class Logger {
  private:
    void emit(String, String);
    BaseHandler *handlers;

  public:
    Logger(BaseHandler *handlers);
    void info(String);
    void error(String);
};