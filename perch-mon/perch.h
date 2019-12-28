#ifndef PERCH_H
#define PERCH_H
#include <QObject>
struct perchHeader
{
    quint8 ver;     // version of the protocol
    quint8 hlen;    // lenght of the head
    quint8 ptype;   // packet type
    quint8 pcntr;   // number of packets
    quint16 dlen;    // dlen
    quint16 rsv;     // reserved
};
struct perchData
{
    quint16 len;     // lenght of the spectrm
    quint16 ref;      // number of spectrm
};

    struct perch_packet
{
        perchHeader *headerr;
        perchData *perchAmp;
        quint16 *amps;
};


#endif // PERCH_H


