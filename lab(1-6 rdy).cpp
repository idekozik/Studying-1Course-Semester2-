#include <iostream>
#include <cstring>
using namespace std;

class IJK{
    private:
        double i,j,k;
    public:
    	IJK(){
            i=0;
            j=0;
            k=0;
           	
			static int objects0;
        	objects0++;
        	cout<<"������ ������� ������-������ "<<objects0<<" ��� ������"<<endl;
        	cout<<"��� �����: "<<this<<endl;
        	this->coutIJK();
        	
        	cout<<endl;
		}
		
        IJK(double I, double J, double K){
            i=I;
            j=J;
            k=K;
           	
			static int objects;
        	objects++;
        	cout<<"������ ������-������: "<<objects<<" ��� ������"<<endl;
        	cout<<"��� �����: "<<this<<endl;
        	this->coutIJK();
        	
        	cout<<endl;
		}
        ~IJK(){
        	cout<<"�������� ������� . . ."<<endl;
		}
        
        friend class Vector;
        friend void editIJK(IJK* one);

        void editIJK(){
            cout<<"�������������� i,j,k: "<<endl;
            cin>>i,j,k;
        }
        
        void coutIJK(){
            cout<<"���������� ������-�������: ";
            cout<<"i= "<<i<<"; j= "<<j<<"; k= "<<k<<endl;
        }
};

class Vector{
	private:
		double i,j,k;
	public:
		Vector(IJK* one, IJK* two){
			i = two->i - one->i;
			j = two->j - one->j;
			k = two->k - one->k;
			
			static int vectors;
        	vectors++;
        	cout<<"������ ������ "<<vectors<<" ��� ������"<<endl;
			this->coutVector();
		}
		~Vector(){
			cout<<"�������� ������� . . ."<<endl;
		}
		coutVector(){
			cout<<"���������� ������� � ��-��: ";
			cout<<"i= "<<i<<"; j= "<<j<<"; k= "<<k<<endl;
			cout<<endl;
		}

};

void editIJK(IJK* one){
	int i,j,k;
	cout<<"��������� �������� ������-������� (i=, j=, k=): ";
	cin>>i>>j>>k;
	cout<<endl;
	one->i=i; 
	one->j=j; 
	one->k=k; 
	one->coutIJK();
}


int main()
{
	setlocale(LC_ALL, "rus");
	
    IJK obj1 (5,6,11),obj2(13,12,11), obj3;
   	Vector vobj1(&obj1, &obj2);
   	
   	editIJK(&obj3);
    return 0;
}

