#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include <string>

namespace messanger
{

  enum MSG_TYPE {KEY_PRESS};

  struct Message{

      Message(MSG_TYPE _msg_type, std::string _msg_value)
      {
        msg_type=_msg_type;
        msg_value=_msg_value;
      }

      MSG_TYPE msg_type;
      std::string msg_value;
  };

}

#endif // MESSAGE_H_INCLUDED
