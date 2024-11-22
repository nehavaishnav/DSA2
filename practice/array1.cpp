#include <iostream>
#include <string>
using namespace std;


class patient {

    int id;
    string name;
    bool appointment_status;  
public:
 patient(){}

 patient(int id,string name){
    this->id=id;
    this->name=name;
    appointment_status=false;
}
void display(){
    cout<<"\n patient id:"<<id;
    cout<<"patient name:"<<name;
    cout<<"as:"<<appointment_status;
}

void set_appointment_status(){
    appointment_status=!appointment_status;
    
}



};

int main() {
    int id=1000;
    patient *arr[10];
    for (int i=0;i<10;i++){
        string name;
        cin>>name;
        id=id+1;
        patient *p=new patient(id,name);
        arr[i]=p;
    }
    cout<<"display:";
    for (int i=0;i<10;i++){
        arr[i]->display();
    }
    arr[2]->set_appointment_status();
        arr[3]->set_appointment_status();
            arr[4]->set_appointment_status();

for(int i=0;i<10;i++){
  arr[i]->display();
    
}

    return 0;
}
