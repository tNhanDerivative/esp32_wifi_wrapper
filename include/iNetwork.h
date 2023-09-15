//
// Created by trongnhan on 9/10/23.
//

#ifndef ESP32_IOT_INETWORK_H
#define ESP32_IOT_INETWORK_H

#include <vector>


typedef enum {
    NETWORK_CONNECTED,
    NETWORK_DISCONNECTED,
} Network_State_t;

typedef void (*FuncPtr)();

class iNetwork {

public:
    virtual void subscribe_wifi_event(Network_State_t event, FuncPtr callback)= 0;
    virtual void post_wifi_event() =0;
    virtual void init_wifi()= 0;
};


#endif //ESP32_IOT_INETWORK_H
