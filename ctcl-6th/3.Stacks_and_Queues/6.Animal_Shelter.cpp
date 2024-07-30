#include <iostream>
#include <limits>
#include <memory>
#include <utility>
#include "queue.hpp"
using namespace std;

// 名前と古い順の通し番号をメンバ変数に持つ基底クラス Animal を作り
// その派生クラスとして Cat, Dog を定義する
class Animal
{
    private:
        string name;
        size_t orderNo;

    protected:
        // コンストラクタを protected にすることで外部での生成を禁止する
        Animal( string&& animalName )
        : name(move(animalName)), orderNo(numeric_limits<decltype(orderNo)>::max()) {}
        // numeric_limits<T>::max() はT型の最大の値を返す

    public:
        virtual ~Animal() {}  // デストラクタを仮想関数にすることで
                              // Animal クラスのポインタで子クラスを生成しても
                              // delete で子クラスのデストラクタが呼ばれる
        void setOrder( size_t order ) { orderNo = order; }
        size_t getOrder() const { return orderNo; }
        const string& getName() const { return name; }

        // 子クラスの生成を親クラスの create 関数で管理
        // (ファクトリ関数)
        template <typename T>
        static shared_ptr<Animal> create( string&& name )
        { return make_shared<T>(move(name)); }  //T型の shared_ptr を生成し返す

        bool operator < ( const Animal& other )
        { return orderNo < other.orderNo; }
};


class Dog: public Animal
{
    public:
        Dog(string&& name): Animal(move(name)) {}
};

class Cat: public Animal
{
    public:
        Cat(string&& name): Animal(move(name)) {}
};


class Shelter
{
    private:
        Queue<shared_ptr<Dog>> dogs;
        Queue<shared_ptr<Cat>> cats;
        size_t nextOrderNo;

    public:
        Shelter(): nextOrderNo(0) {}

        void enqueue( shared_ptr<Animal>&& animal );

        shared_ptr<Animal> dequeueAny();
        shared_ptr<Animal> dequeueCat()
        { return static_pointer_cast<Animal>(cats.remove()); }
        shared_ptr<Animal> dequeueDog();
        { return static_pointer_cast<Animal>(dogs.remove()); }

        class BadAnimalException {};
};

void Shelter::enqueue( shared_ptr<Animal>&& animal )
{
    // dynamic_pointer_cast は animal を Dog へ動的にキャストする
    // ポインタ変数の初期化とNULLチェックを同時に行う
    if( auto dog = dynamic_pointer_cast<Dog>(animal) ){
        dog->setOrder(nextOrderNo++);
        dogs.add(std::move(dog));
    }else if( auto cat = std::dynamic_pointer_cast<Cat>(animal) ){
        cat->setOrder(nextOrderNo++);
        cats.add(move(cat));
    }else throw BadAnimalException();
}

std::shared_ptr<Animal> Shelter::dequeueAny()
{
    if     ( dogs.isEmpty() ) return dequeueCat();
    else if( cats.isEmpty() ) return dequeueDog();
    else if( *dogs.peek() < *cats.peek() )
        return dequeueDog();  // Animal クラスの比較演算子は orderNo
                              // の比較になるようオーバーロードしている
    else return dequeueCat();
}



int main()
{
    Shelter shelter;
    for (auto name : {"Dog 1", "Cat 1", "Dog 2", "Dog 3 ", "Cat 2", "Cat 3", "Cat 4", "Dog 4", "Dog 5", "Dog 6", "Cat 5", "Cat 6", "Dog 7", "Dog 8", "Cat 7", "Dog 9"})
    {
        if (name[0] == 'D')
            shelter.enqueue(Animal::create<Dog>(std::move(name)));
        else if (name[0] == 'C')
            shelter.enqueue(Animal::create<Cat>(std::move(name)));
    }

    std::cout << "any --> " << shelter.dequeueAny()->getName() << std::endl;
    std::cout << "any --> " << shelter.dequeueAny()->getName() << std::endl;

    std::cout << "dog --> " << shelter.dequeueDog()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "dog --> " << shelter.dequeueDog()->getName() << std::endl;
    std::cout << "dog --> " << shelter.dequeueDog()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "any --> " << shelter.dequeueAny()->getName() << std::endl;
}
