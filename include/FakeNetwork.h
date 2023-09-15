//
// Created by trongnhan on 9/10/23.
//

#ifndef ESP32_IOT_FAKENETWORK_H
#define ESP32_IOT_FAKENETWORK_H

#include "iNetwork.h"


class FakeNetwork: public iNetwork{
private:
    std::vector<FuncPtr> network_connected_observers;
    std::vector<FuncPtr> network_disconnected_observers;

    void wifi_event_connected();
    void wifi_event_disconnected();

public:
    void subscribe_wifi_event(Network_State_t event, FuncPtr callback) override;
    void post_wifi_event() override;
    void init_wifi() override;

};


#endif //ESP32_IOT_FAKENETWORK_H
