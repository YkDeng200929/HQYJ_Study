#include <memory>
#include "Pointer.hpp"

// 智能指针

int main(void)
{
    {// auto_ptr
    /*
        auto_ptr<Pointer> aPoint(new Pointer("hello"));
        aPoint->show();

        auto_ptr<Pointer> aPoint2 = aPoint;
        aPoint2->show();
        //aPoint->show(); error
    */
    }

    {// unique_ptr
        /*
        unique_ptr<Pointer> uniquePointer(new Pointer("hello"));
        uniquePointer->show();

        // unique_ptr<Pointer> uniquePointer2 = uniquePointer;  // error
        unique_ptr<Pointer> uniquePointer2(new Pointer[10]);    // 数组管理

        unique_ptr<Pointer> uniquePointer3(new Pointer("world"));
        cout << "uniquePointer3 orgin: ";
        uniquePointer3->show();
        cout << endl;

        uniquePointer3 = move(uniquePointer); // 将uniquePointer 的地址转让给 uniquePointer3
        uniquePointer.release();              // 转让后释放原有地址
        
        cout << "uniquePointer3 after move: ";
        uniquePointer3->show();
        cout << endl;
        */
    }

    {// shared_ptr
        shared_ptr<Pointer> sharedPointer1(new Pointer("Hello"));
        cout << sharedPointer1.use_count() << endl;             // 计数器显示当前的智能指针数
        
        shared_ptr<Pointer> sharedPointer2 = sharedPointer1;
        sharedPointer1->show();
        sharedPointer2->show();

        cout << sharedPointer1.use_count() << endl;             // 计数器显示当前的智能指针数
        cout << sharedPointer2.use_count() << endl;             // 计数器显示当前的智能指针数
    }

    return 0;
}