#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <memory>

namespace GraphFlow {

typedef enum {
    MESSAGE_TYPE_DEFAULT = 0,
    MESSAGE_TYPE_MAX
} MESSAGE_TYPE;

class Message {
public:
    Message(MESSAGE_TYPE type=MESSAGE_TYPE_DEFAULT): mType(type) {}
    virtual ~Message() {}

    void setType(MESSAGE_TYPE type);
    MESSAGE_TYPE getType();

    virtual int getValue() {return 0;};

private:
    MESSAGE_TYPE mType;
};
typedef std::shared_ptr<Message> spMessage;

};

#endif
