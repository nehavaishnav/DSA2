//create an array containig the details of patients (id, name, appointement_status) 
//enter 10 patient record in which three have true in appointment 
//search those patients in the array and print in the formatted manner 
//search the patient having id 1001 using  binary search
//mid=low+((high-low)/2)
#include<iostream>
#include<string>
using namespace std;
class patient {
    int id;
    string name;
    bool appointment_status;  
     
    patient(int i, string n, bool status) : id(i), name(n), appointment_status(status) {}
   
}


   int binarySearch(int low, int high, int id) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (patients[mid].id == id) {
                return mid;  // ID found, return index
            } else if (patients[mid].id < id) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;  // ID not found
    }
int main(){
     patient patients[10] = {
      
        patient(1001, "Alice", true),
        patient(1002, "Bob", false),
        patient(1003, "Charlie", false),
        patient(1004, "David", true),
        patient(1005, "Eve", true),
        patient(1006, "Frank", false),
        patient(1007, "Grace", false),
        patient(1008, "Hannah", false),
        patient(1009, "Ivy", false),
        patient(1010, "Jack", false)
    }
    };
}
