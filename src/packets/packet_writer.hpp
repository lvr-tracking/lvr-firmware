#pragma once
#include <vector>

class PacketWriter {
    private:
        std::vector<int> buffer;
    public:
        PacketWriter();
        void writeByte(int byte);
        void writeShort(short data);
        void writeInt(int data);
        void writeLong(long data);
        void writeString(char* string);
};