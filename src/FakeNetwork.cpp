//
// Created by trongnhan on 9/10/23.
//

#include "../include/FakeNetwork.h"
#include <iostream>


void FakeNetwork::subscribe_wifi_event(Network_State_t event, FuncPtr callback) {
    switch(event){
        case NETWORK_CONNECTED:
            this->network_connected_observers.push_back(callback);
            break;
        case NETWORK_DISCONNECTED:
            this->network_disconnected_observers.push_back(callback);
            break;
        default: break;
    }
}

void FakeNetwork::init_wifi() {
    std::cout << " init fake wifi" << "\n";
    this->post_wifi_event();

}

void FakeNetwork:: wifi_event_connected() {
    for(auto& callback : this->network_connected_observers){
        (*callback)();
    }
}

void FakeNetwork:: wifi_event_disconnected() {
    for(auto& callback : this->network_disconnected_observers){
        (*callback)();
    }

}

void FakeNetwork::post_wifi_event() {
    this->wifi_event_connected();
    this->wifi_event_disconnected();

}
