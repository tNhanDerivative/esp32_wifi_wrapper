//
// Created by trongnhan on 9/10/23.
//

#ifndef ESP32_IOT_CONFIG_H
#define ESP32_IOT_CONFIG_H

#include "iNetwork.h"
#include "FakeNetwork.h"


class Config {
private:
    FakeNetwork network;
public:
    iNetwork& get_network();

};


#endif //ESP32_IOT_CONFIG_H
