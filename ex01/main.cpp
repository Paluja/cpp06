#include "Serializer/Serializer.h"


int main(void)
{
    Data* dataPtr = new Data;
    dataPtr->str = "Hello, World!";

    std::cout << "Original data pointer: " << dataPtr << std::endl;
    // Serialize the data pointer
    uintptr_t serializedData = Serializer::serialize(dataPtr);
    std::cout << "Serialized data: " << serializedData << std::endl;
    
    // Deserialize the data pointer
    Data* deserializedDataPtr = Serializer::deserialize(serializedData);
    std::cout << "Deserialized data: " << deserializedDataPtr << std::endl;
    //Everyyhing works fine ?
    if (dataPtr == deserializedDataPtr)
        std::cout << "Deserialization successful!" << std::endl;
    else
        std::cout << "Deserialization failed!" << std::endl;

    return 0;
}