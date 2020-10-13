#ifndef LINUX_CORE_H
#define LINUX_CORE_H


#include <QString>
#include <stdlib.h>

const QString PROJECT_NAME = "$HARCAT";
const QString USER_NAME = getenv("USER");
const QString PROJECT_PATH = "/home/" + USER_NAME + "/Documents/" + PROJECT_NAME + "/";




#endif // LINUX_CORE_H
