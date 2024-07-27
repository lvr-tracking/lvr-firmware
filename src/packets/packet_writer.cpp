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