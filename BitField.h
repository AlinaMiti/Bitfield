#include <iostream>

class BitField{
private:
    size_t _sizeMem;   //размер памяти (сколько элементов в массиве)
    uint16_t* _mem;  //массив
    size_t _sizeBit;   //кол-во бит кооторое нам надо хранить(чтобы не залезть в лишнюю память)
    size_t GetMemIndex(size_t n)const; //вернуть индекс по которому лежит данный бит в массиве Мем. (Двойная индексация). в каком элементе лежит этот бит
    uint16_t GetMask(size_t n)const; //получение маски конкретного бита
public:
    BitField(size_t sizeBit);    
    BitField(const BitField& tmp); //копирование
    
    size_t GetSize()const;
    uint8_t GetBit(size_t n)const;//возвращает значение бита
    void SetBit(size_t n){      //устанавливать в конкретный бит значение 1
        _mem[GetMemIndex(n)] |= GetMask(n);     // |= "или равно"
    } 
    void ClrBit(size_t n);//устанавливать конкретный бит в знчение 0


    ~BitField(); //ставить nullptr указатель
};
