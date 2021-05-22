#ifndef ABSTRACT_PACKAGE_H
#define ABSTRACT_PACKAGE_H

#include <QByteArray>
#include <QDebug>
#include <QVector>

class type_package
{
public:
    type_package();
private:
#pragma pack(push, 1)
    struct data_packet_struct{
        data_packet_struct(){
            memset(this,0x00,sizeof (data_packet_struct));
        }
        char *ptr(void){return (char *)this;}
        int  size(void) {return sizeof (data_packet_struct);}

        uint type:8;

        uint status:8;
        uint work_id:16;

        float velosity;
        float longituge;
        float lalittude;

        float power;
    };

#pragma pack(pop)


public:
    data_packet_struct *data_packet;

    QByteArray bytes(){
        return QByteArray(data_packet->ptr(), sizeof (data_packet_struct));
    }

    bool setBytes(const QByteArray &bytes){
        if (bytes.size() != sizeof (data_packet_struct))
            return false;
        memcpy(data_packet->ptr(), bytes.data(), sizeof(data_packet_struct));
        return true;
    }
};

#endif // ABSTRACT_PACKAGE_H
