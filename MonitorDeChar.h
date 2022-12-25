#ifndef MONITOR_DE_CHAR
#define MONITOR_DE_CHAR

#include "Monitor.h"


class MonitorDeChar : public Monitor {
public:
    MonitorDeChar();
    virtual ~MonitorDeChar();
    virtual void escrever(Dado* d);
};


#endif // MONITOR_DE_CHAR