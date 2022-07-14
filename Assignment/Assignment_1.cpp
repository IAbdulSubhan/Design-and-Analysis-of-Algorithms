//p200086   Subhan Khalid

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node{
    string data;
    node *next;
};
class DNC{
    private:
        
        string temp1;
        
    public:
        string numOne,numTwo;
        node *arr1,*arr2,*temp,*result;
        int length1,length2;

        DNC(){
            arr1=arr2=temp=result=NULL;
            length1=length2=0;

            cout<<"Enter the Multiplicand : ";
            cin>>numOne;
            cout<<"Enter the Multiplier : ";
            cin>>numTwo;

            length1=numOne.size();
            length2=numTwo.size();

            if(length1 % 2 != 0){  
                numOne = "0"+numOne;
                length1+=1;
            }
            if(length2 % 2 != 0){  
                numTwo = "0"+numTwo;
                length2+=1;
            }
        }

        void Divide(int len,node* arr,string str,int a){

        for(int i=0;i<len;i=i+2){

            temp1=str[i];
            temp1+=str[i+1];
            if(arr==NULL){
                arr=new node;
                arr->data=temp1;
                arr->next=NULL;
            }
            else{
                temp=arr;
                while(temp->next != NULL){
                    temp=temp->next;
                }
                temp->next=new node;
                temp->next->data=temp1;
                temp->next->next=NULL;   
            }      
        }
        if (a==1){
            arr1=arr;
        }
        else{
            arr2=arr;
        }
        return;
    }

void Multiplication(){
    int count=0, count1=0,var_1,var_2,var_3;

    node *temp2=arr2;
    temp=arr1;
    while(temp !=NULL ){
        count=count1=0;
        temp2=arr2;
        stringstream convert(temp->data); 
        convert >> var_1;
        count+=Count(temp);
        while(temp2 != NULL){
            count1=Count(temp2);
            stringstream convert(temp2->data); 
            convert >> var_2;
            var_3=var_1*var_2;
            stringstream ss;
            ss << var_3;
            temp1 = ss.str();
            temp2=temp2->next;
            Merge(count+count1,temp1);
        }
        
        temp=temp->next;
        
    }
    temp=result;
    var_3=0;
    while(temp!=NULL){
        temp1=temp->data;
        stringstream convert(temp->data); 
        convert >> var_1;
        var_3+=var_1;
        temp=temp->next;
    }
    cout<<"The Answer is "<<var_3<<endl;
    return;   
}

    void Merge(int var_1,string str){

        node *abc;

        while(var_1!=0){
            str+="0";
            var_1-=1;
        }
        if(result==NULL){
            result=new node;
            result->data=str;
            result->next=NULL;
            return;
        }
        
        abc = result;
        while(result->next != NULL) {
            result=result->next;  
        }
        result->next=new node;
        result->next->data=str;
        result->next->next=NULL;
        result=abc;
        return;
    }
    
    int Count(node *temp){
    
    int count=0;

    while(temp->next != NULL){
        count+=2;
        temp=temp->next;
    }
    return count;
    }

};



int main(){
    DNC one;
    one.Divide(one.length1,one.arr1,one.numOne,1);
    one.Divide(one.length2,one.arr2,one.numTwo,2);
    one.Multiplication();
    return 0;
}