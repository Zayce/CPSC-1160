class AmazingArray{
public:
    int* values;
    int length;

    AmazingArray(){
        values = nullptr;
        length = 0;
    }
    AmazingArray(int* arr, int len){
        // copy contents of arr into values
    }
    ~AmazingArray(){
        if(values != nullptr){
            delete[] values;
            values = nullptr;
            length = 0;
        }        
    }

};