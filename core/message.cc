#include "message.h"

namespace GraphFlow {

void Message::setType(MESSAGE_TYPE type) {
    mType = type;
}

MESSAGE_TYPE Message::getType() {
    return mType;
}

};

