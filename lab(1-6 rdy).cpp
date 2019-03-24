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
        	cout<<"Объект нулевой радиус-вектор"<<objects0<<" был создан"<<endl;
        	cout<<"Его адрес: "<<this<<endl;
        	this->coutIJK();
        	
        	cout<<endl;
	}
		
        IJK(double I, double J, double K){
            	i=I;
            	j=J;
            	k=K;
           	
		static int objects;
        	objects++;
        	cout<<"Объект радиус-вектор: "<<objects<<" был создан"<<endl;
        	cout<<"Его адрес: "<<this<<endl;
        	this->coutIJK();
        	
        	cout<<endl;
	}
	
	IJK(IJK* one){
		i=one->i;
		j=one->j;
		k=one->k;
			
		static int objectsC;
        	objectsC++;
        	cout<<"Копированный объект радиус-вектор: "<<objectsC<<" был создан"<<endl;
        	cout<<"Его адрес: "<<this<<endl;
        	this->coutIJK();
		
		cout<<endl;
	}
	
        ~IJK(){
        	cout<<"Удаление объекта . . ."<<endl;
	}
        
        friend class Vector;
        friend void editIJK(IJK* one);
        
        void coutIJK(){
            cout<<"Координаты радиус-вектора: ";
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
        		cout<<"Объект вектор "<<vectors<<" был создан"<<endl;
			this->coutVector();
		}
	
		~Vector(){
			cout<<"Удаление объекта . . ."<<endl;
		}
	
		coutVector(){
			cout<<"Координаты вектора в пр-ве: ";
			cout<<"i= "<<i<<"; j= "<<j<<"; k= "<<k<<endl;
			cout<<endl;
		}

};

void editIJK(IJK* one){
	int i,j,k;
	cout<<"Изменение значения радиус-вектора (i=, j=, k=):";
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
	IJK obj4(&obj1);
   	Vector vobj1(&obj1, &obj2);
   	
   	//editIJK(&obj3);
    	return 0;
}

