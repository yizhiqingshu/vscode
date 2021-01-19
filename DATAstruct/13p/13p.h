#ifndef _shunxuduilie_H
#define _shunxuduilie_H
template<class T>
class Queue{
    public:
    Queue(int queueCaoacity=10);
    bool IsEmpty()const;
    T& Front()const;
    T& Rear()const;//查看读取队首尾的数据
    void Push(const T& item);
    void Pop();
    private:
    T *queue;
    int front;
    int rear;
    int capacity;

};
template<class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity){
    if(capacity<1) throw "Queue capacity must be >0";
    queue=new T[capacity];
    front=rear=0;
}
template<class T>
inline bool Queue<T>::IsEmpty()const{
    return front==rear; 
}
template<class T>
void Queue<T>::Push(const T& item){
    // if(rear==capacity-1)
    //     rear=0;
    // else 
    //     rear++;
    //     queue[rear=item];
    // if((rear+1)%capacity==front)
    // {
    //     //加倍
    //     T* newQueue=new T[2*capacity];
    //     int start =(front+1)&capacity;
    //     if(start<2)// 没有回转
    //     copy(queue+start,queue+start+capacity-1,newQueue);
    //     else 
    //     {
            
    //         copy(queue+start,queue+capacity,newQueue);
    //         copy(queue,queue+rear+1,newQueue+capacity-start);
    //     }
    //     front=2*capacity-1;
    //     rear=capacity-2;
    //     capacity*=2;
    //     delete[]queue;
    //     queue=newQueue;
    // }
    rear=(rear+1)%capacity;//妙哉！
    queue[rear]=item;

}
template<class T>
inline T& Queue<T>::Front()const{
    if(IsEmpty()) throw "Queue is empty";
    return queue[(front+1)%capacity];
}
template<class T>
inline T& Queue<T>::Rear()const{
    if(IsEmpty()) throw" queue is empty";
    return queue[rear];
}
template<class T>
void Queue<T>::Pop(){
    if(IsEmpty()) throw "Queue is empty! cannot delete";
    front=(front+1)%capacity;

}
#endif