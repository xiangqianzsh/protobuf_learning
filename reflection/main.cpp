#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <student.pb.h>

typedef tutorial::Student Student;

int main(int argc, char** argv) {

    Student item;
    
    const google::protobuf::Descriptor* pDescriptor = item.GetDescriptor();
    // Also you can
    // std::string type_name = Student::descriptor()->full_name();
    // const google::protobuf::Descriptor* pDescriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
    const google::protobuf::Reflection* pReflection = item.GetReflection();

    for (int i = 0; i < pDescriptor->field_count(); ++i) {
        const google::protobuf::FieldDescriptor* pFieldDescriptor = pDescriptor->field(i);
        const std::string& strFieldName = pFieldDescriptor->name();

        std::cout << "i: " << i
                << ", strFieldName: " << strFieldName
                << std::endl;

        if (strFieldName == "name") {
            pReflection->SetString(&item, pFieldDescriptor, "a");
        } else if (strFieldName == "id") {
            pReflection->SetInt32(&item, pFieldDescriptor, 1);
        }
    }

    std::cout << "name: " << item.name()
                << ", id: " << item.id()
                << ", coure: " << item.course()
                << ", score: " << item.score()
                << std::endl;
    
    return 0;
}
