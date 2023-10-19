#ifndef __TIMESTAMP_H__
#define __TIMESTAMP_H__

class Timestamp {
    private:
        unsigned int hour;
        unsigned int minute;
        unsigned int second;

        unsigned long long unix_time;

    public:
        Timestamp();

        void updateTime();  
        char* getTime() const;
};


#endif //__TIMESTAMP_H__