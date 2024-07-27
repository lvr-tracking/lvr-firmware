#include "packet_writer.hpp"

//I think we can use for here, but for now this one should be good

PacketWriter::PacketWriter() {
    this->buffer = { 0 };
}

void PacketWriter::writeByte(int byte) {
    this->buffer.push_back(byte);
}

void PacketWriter::writeShort(short data) {
    this->buffer.push_back(data & 0xff);
    this->buffer.push_back((data >> 8) & 0xff);
};

void PacketWriter::writeInt(int data) {
    this->buffer.push_back(data & 0xff);
    this->buffer.push_back((data >> 8) & 0xff);
    this->buffer.push_back((data >> 16) & 0xff);
    this->buffer.push_back((data >> 24) & 0xff);
}

void PacketWriter::writeLong(long data) {
    this->buffer.push_back(data & 0xff);
    this->buffer.push_back((data >> 8) & 0xff);
    this->buffer.push_back((data >> 16) & 0xff);
    this->buffer.push_back((data >> 24) & 0xff);
    this->buffer.push_back((data >> 32) & 0xff);
    this->buffer.push_back((data >> 40) & 0xff);
    this->buffer.push_back((data >> 48) & 0xff);
    this->buffer.push_back((data >> 56) & 0xff);
}

void PacketWriter::writeVarint(unsigned long data) {
    while (data > 0x7F) {
        this->buffer.push_back((data & 0x7F) | 0x80);
        data >>= 7;
    }
    this->buffer.push_back(data & 0x7F);
}

void PacketWriter::writeString(const char* data) {
    this->writeVarint(sizeof(data));

    for (int i = 0; i < sizeof(data); i++) {
        this->writeByte(data[i]);
    }
}