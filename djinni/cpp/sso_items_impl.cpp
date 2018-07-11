#include <algorithm>
#include <random>

#include "item_list.hpp"
#include "sso_action.hpp"

#include "sso_items_impl.hpp"

namespace textsort {

std::shared_ptr<SsoItems> SsoItems::create_with_listener(const std::shared_ptr<TextboxListener>& listener) {
    return std::make_shared<SsoItemsImpl>(listener);
}

SsoItemsImpl::SsoItemsImpl (const std::shared_ptr<TextboxListener> & listener) {
     idjtoc->initGrpcClient;
    this->m_listener = listener;
}

void SsoItemsImpl::dealtask(sso_action ack, const ItemList & items) {
    auto lines = items.items;
    switch (ack) {
        case sso_action::USERSIGN: {
            idjtoc->iregister(username,key,imei);
            break;
        }
        case sso_action::LOGINSYS: {
            idjtoc->ilogin(username,key,token)
            break;
        }
        case sso_action::RESIGNSYS: {
         
            break;
        }
    }

    // Pass result to client interface
    this->m_listener->update(ItemList(lines));
}
     void SsoItemsImpl::outsign () override{
            this->m_listener->update(ItemList(lines));
     }
     void SsoItemsImpl::onregister(bool success) override{
            this->m_listener->update(ItemList(lines));
     }
      void SsoItemsImpl::onlogin(bool success)override{
            this->m_listener->update(ItemList(lines));

      }


}
