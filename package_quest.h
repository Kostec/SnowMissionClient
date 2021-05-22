#ifndef PACKET_QUEST_H
#define PACKET_QUEST_H

#include <QObject>
#include <QVector>

class packet_quest
{
public:
    packet_quest();

private:
#pragma pack(push, 1)
    struct data_packet_struct{
        data_packet_struct(){
            memset(this,0x00,sizeof (data_packet_struct));
        }
        char *ptr(void){return (char *)this;}
        int  size(void) {return sizeof (data_packet_struct);}

        QString Start_SIGNATURE = "[START]";
        uint work_id:16; // id_задания
    //    uint work_type:8; // тип работы
        uint count_rect:8; //количество прямоугольничков 5х5
        QVector<int> rectangles_for_clean;
    };

#pragma pack(pop)


public:
    data_packet_struct *data_packet;

    QByteArray bytes(){
        return QByteArray(data_packet->ptr(),sizeof (data_packet_struct));
    }

    bool setBytes(const QByteArray &bytes){
        if (bytes.size() != sizeof (data_packet_struct))
            return false;
        memcpy(data_packet->ptr(), bytes.data(), sizeof(data_packet_struct));
        return true;
    }
};
#endif // PACKET_QUEST_H
