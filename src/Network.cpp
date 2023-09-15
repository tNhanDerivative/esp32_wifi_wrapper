#include "../include/Network.h"

#define WIFI_SSID "<YOUR_WIFI_SSID>"
#define WIFI_PASSWORD "<YOUR_WIFI_PASSWORD>"



void Network:: wifi_event_connected() {
    for(auto& callback : this->network_connected_observers){
        (*callback)();
    }
}

void Network:: wifi_event_disconnected() {
    for(auto& callback : this->network_disconnected_observers){
        (*callback)();
    }

}

void Network::subscribe_wifi_event(Network_State_t event, FuncPtr callback) {
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

void Network::post_wifi_event() {
    WiFi.onEvent(this->wifi_event_connected(), SYSTEM_EVENT_STA_CONNECTED);
    WiFi.onEvent(this->wifi_event_disconnected(), SYSTEM_EVENT_STA_DISCONNECTED);
}

void Network::initWiFi(){
  WiFi.disconnect();
  this->post_wifi_event();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}


