#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include <string>

namespace messanger
{

  enum MSG_TYPE {
    KEY_PRESSED,
    APPLICATION_EXIT,
    TEXTURE_LOAD,
    TEXTURE_GET,
    TEXTURE_POST,
    TEXTURE_NOT_FOUND,
    SHADER_LOAD,
    SHADER_GET,
    SHADER_POST,
    SHADER_NOT_FOUND
  };

  struct Message{

    Message(MSG_TYPE _msg_type)
    {
        msg_type=_msg_type;
        msg_value="";
        msg_data=NULL;
    }

    Message(MSG_TYPE _msg_type, std::string _msg_value)
    {
      msg_type=_msg_type;
      msg_value=_msg_value;
      msg_data = NULL;
    }

    Message(MSG_TYPE _msg_type, std::string _msg_value, void* _msg_data)
    {
      msg_type=_msg_type;
      msg_value=_msg_value;
      msg_data=_msg_data;
    }

    MSG_TYPE msg_type;
    void* msg_data;
    std::string msg_value;
  };

}

#endif // MESSAGE_H_INCLUDED
