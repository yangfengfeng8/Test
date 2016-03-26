#ifndef PABASE_H
#define PABASE_H

#include <QObject>

#define One_Way 0
#define Two_Way 1

#define Parally 10
#define Serial  11

#define Valid   20
#define InValid 21

#define ChannelMax  64

#define Attenuation 30
#define Matrix      31
#define NoMatrix    32
#define Divide      33
#define NoDivide    34
#define AttenuationSwitch 35
#define Special     36
#define NoSpecial   37

#ifndef Tabulator
#define Tabulator  "     "
#endif

#ifndef Version
#define Version "HBTE Power Creator 1.1.3.2"
#endif

class PABase : public QObject
{
    Q_OBJECT
public:
    explicit PABase(QObject *parent = 0);

signals:

public slots:
};

#endif // PABASE_H
