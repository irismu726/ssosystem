#pragma once

#include "sso_items.hpp"
#include "textbox_listener.hpp"
#include "dj_toc_interface.h"
#include "c_todj_interface.h"
namespace textsort {
//implament of c++ 
class SsoItemsImpl : public SsoItems,CJToDJ  {

public:
    SsoItemsImpl(const std::shared_ptr<TextboxListener> & listener);

    virtual void dealtask(sso_action order, const ItemList & items) override;
     void outsign () override;
     void onregister(bool success) override;
      void onlogin(bool success)override;
   ItemList itemList = new ItemList(items);

private:
    IDJToC*idjtoc = new IDJToC();
    std::shared_ptr<TextboxListener> m_listener;

};

}
