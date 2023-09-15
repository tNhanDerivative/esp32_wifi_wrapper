#ifndef Network_H_
#define Network_H_


#include <WiFi.h>
#include "iNetwork.h"



class Network: public iNetwork{
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


#endif