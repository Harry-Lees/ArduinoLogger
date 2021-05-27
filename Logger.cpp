#pragma once

#include "Arduino.h"
#include "Logger.h"

// Logger

Logger::Logger(BaseHandler *handlers) {
  this->handlers = handlers;
}

void Logger::emit(String prefix, String message) {
  for(int i=0; i<sizeof(this->handlers); i++) {
    this->handlers[i].emit();
  }
}

void Logger::info(String message) {
  this->emit("INFO: ", message);
}

void Logger::warning(String message) {
  this->emit("WARNING: ", message);
}

void Logger::error(String message) {
  this->emit("ERROR: ", message);
}


// UsbSerialHandler

void UsbSerialHandler::UsbSerialHandler(int baudrate, level _level) {
  this->_level = _level;

  Serial.begin(baudrate);
  while (!Serial);  
}

void UsbSerialHandler::emit(String prefix, String message) {
  Serial.print(prefix);
  Serial.println(message);
}


// Rs232SerialHandler

void Rs232SerialHandler::Rs232SerialHandler(int baudrate, level _level) {
  this->_level = _level;

  Serial1.begin(baudrate);
  while (!Serial);
}

void Rs232SerialHandler::emit(String prefix, String message) {
  Serial1.print(prefix);
  Serial1.println(message);
}