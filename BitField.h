#include <iostream>

class BitField{
private:
    size_t _sizeMem;   //размер памяти (сколько элементов в массиве)
    uint16_t* _mem;  //массив
    size_t _sizeBit;   //кол-во бит кооторое нам надо хранить(чтобы не залезть в лишнюю память)
    size_t GetMemIndex(size_t n)const{ //вернуть индекс по которому лежит данный бит в массиве Мем. (Двойная индексация). в каком элементе лежит этот бит
        size_t index = n/(8*sizeof(uint16_t)); //sizeof  вернет байты, но нам нужны биты => умножаем на 8
        if (n >= _sizeBit)
            throw "Bit out of range"; //бит за границей массива. Программа дальше работать не будет если исключение открылось
        return index;
    }
    uint16_t GetMask(size_t n)const{ //получение маски конкретного бита 
        return  1 << (n % 16);
    }
public:
    BitField(size_t len){
        _sizeBit = len;
        _sizeMem = (len/(8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
        _mem = new uint16_t[_sizeMem];
        for (size_t i = 0; i < _sizeMem; ++i)
            _mem[i] = 0;
    }    

    BitField(const BitField& tmp){ //копирование
        _sizeBit = tmp._sizeBit;
        _sizeMem = tmp._sizeMem;
        _mem = new uint16_t[_sizeMem];
        for(size_t i = 0; i < _sizeMem; ++i)
            _mem[i] = tmp._mem[i];
    }

    BitField& operator=(const BitField& tmp){
        if(_sizeBit != tmp._sizeBit){
            delete [] _mem;
            _sizeBit = tmp._sizeBit;
            _sizeMem = tmp._sizeMem;
            _mem = new uint16_t[_sizeMem];
        }       
        for(size_t i = 0; i < _sizeMem; ++i)
            _mem[i] = tmp._mem[i];
        return *this;  
    }
    
    size_t GetSize()const;
    uint8_t GetBit(size_t n)const{  //возвращает значение бита
        //проверка размера. получить маску. получить индекс

        //логическое И этого элемента с его маской
    }
    void SetBit(size_t n){      //устанавливать в конкретный бит значение 1
        _mem[GetMemIndex(n)] |= GetMask(n);     // |= "или равно"
    } 
    void ClrBit(size_t n);//устанавливать конкретный бит в знчение 0

    ~BitField(); //ставить nullptr указатель
};
