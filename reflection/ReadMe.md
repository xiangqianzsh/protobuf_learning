protobuf

# reflection
# 通过对象和对象的属性的名字获取,修改对应属性.

# compile
```
protoc --proto_path=. --cpp_out=./ ./*.proto
g++  main.cpp  student.pb.cc -I ./  -o main  -I ./ -lprotobuf -std=c++14
./main
```

# output
```
i: 0, strFieldName: name
i: 1, strFieldName: id
i: 2, strFieldName: course
i: 3, strFieldName: score
name: a, id: 1, coure: , score: 0
```

# ref
google protobuf 反射机制学习笔记
https://blog.csdn.net/cchd0001/article/details/52452204

ProtoBuf 反射详解
http://blog.jobbole.com/101302/