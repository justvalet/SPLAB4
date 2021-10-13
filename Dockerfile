FROM centos
COPY dsn1-4.cpp  .
COPY dsn2-4.cpp  .  
RUN yum install vim -y
RUN yum install gcc-c++ -y