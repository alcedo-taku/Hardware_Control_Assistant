#ifndef HCA_MOVING_AVERAGE_FILTER_HPP_
#define HCA_MOVING_AVERAGE_FILTER_HPP_

#include <queue>
#include <cstdint>
#include "filter_interface.hpp"

class MovingAverageFilter : FilterInterface{
private:
    uint16_t number;
    float filteredValue;

    template<class T>
    class AverageQueue{
    private:
        std::queue<T> dataContainer;
        T total;
    public:
        void pop(){
            total -= dataContainer.front();
            dataContainer.pop();
        }

        void push(T value){
            total += value;
            dataContainer.push(value);
        }

        T getAverage(){
            return  (total/dataContainer.size());
        }

        size_t size(){
            return dataContainer.size();
        }

        void reset(){
            std::queue<T> empty;
            std::swap(dataContainer, empty);
        }


    };
    AverageQueue<float> averageQueue;
public:
    MovingAverageFilter();
    void init(uint16_t number);
    void init(float work_frequency, float cut_off_frequency) override;
    void update(float value) override;
    float get() override;
    void reset();
};

#endif // HCA_MOVING_AVERAGE_FILTER_HPP_
