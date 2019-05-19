#include <iostream>
#include <cstring>
using namespace std;

class Basis {
protected:
	double i, j, k;
public:
	virtual void print() = 0;
};

class IJK : protected Basis {
	private:
		class subSpace{
			private:
				int e1,e2,e3;
			public:
				subSpace(){
					e1=0;
					e2=0;
					e3=0;
				}
				subSpace(double E1,double E2,double E3){
					e1=E1;
					e2=E2;
					e3=E3;
				}
				~subSpace(){}	
				void coutSubSpace(){
					cout<<"(e1,e2,e3) : ("<<e1<<","<<e2<<","<<e3<<")"<<endl;
				}
		};
	
		subSpace mSubSpace[3]{
			subSpace(1,2,3),
			subSpace(3,4,1),
			subSpace(8,2,1),
		};
		
	public:
		friend void textBox();
		void getSubSpaceInfo(IJK* one){
			cout<<"Подпространство объекта: "<<one<<endl;
			for(int i=0; i<3; i++){
				mSubSpace[i].coutSubSpace();
			}
		}
		
		IJK() {
			i = 0;
			j = 0;
			k = 0;
	
			static int objects0;
			objects0++;
			cout << "Объект нулевой радиус-вектор" << objects0 << " был создан" << endl;
			cout << "Его адрес: " << this << endl;
			this->print();
	
			cout << endl;
		}
	
		IJK(double I, double J, double K) {
			i = I;
			j = J;
			k = K;
	
			static int objects;
			objects++;
			cout << "Объект радиус-вектор: " << objects << " был создан" << endl;
			cout << "Его адрес: " << this << endl;
			this->print();
	
			cout << endl;
		}
	
		IJK(IJK* one) {
			i = one->i;
			j = one->j;
			k = one->k;
	
			static int objectsC;
			objectsC++;
			cout << "Копированный объект радиус-вектор: " << objectsC << " был создан" << endl;
			cout << "Его адрес: " << this << endl;
			this->print();
	
			cout << endl;
		}
	
		~IJK() {
			cout << "Удаление объекта . . ." << endl;
		}
	
		friend class Vector;
		friend void editIJK(IJK* one);
	
		void print() {
			cout << "Координаты радиус-вектора: ";
			cout << "i= " << i << "; j= " << j << "; k= " << k << endl;
		}
};

class Vector : protected Basis {
public:
	friend Vector operator + (Vector &one, Vector &two);
	friend Vector operator - (Vector &one, Vector &two);
	friend bool operator == (Vector &one, Vector &two);
	friend double operator ++ (Vector &one);
	friend void textBox();

	Vector(IJK* one, IJK* two) {
		i = two->i - one->i;
		j = two->j - one->j;
		k = two->k - one->k;

		static int vectors;
		vectors++;
		cout << "Объект вектор " << vectors << " был создан" << endl;
		this->print();
	}

	Vector(double I, double J, double K) {
		i = I;
		j = J;
		k = K;

		static int vectors;
		vectors++;
		cout << "Объект вектор по координатам " << vectors << " был создан" << endl;
		this->print();
	}

	~Vector() {
		cout << "Удаление объекта . . ." << endl;
	}

	void print() {
		cout << "Координаты вектора в пр-ве: ";
		cout << "i= " << i << "; j= " << j << "; k= " << k << endl;
		cout << endl;
	}

};

Vector operator + (Vector &one, Vector &two) {
	return (Vector(one.i + two.i, one.j + two.j, one.k + two.k));
}

Vector operator - (Vector &one, Vector &two) {
	return (Vector(one.i - two.i, one.j - two.j, one.k - two.k));
}

bool operator == (Vector &one, Vector &two) {
	if (one.i == two.i && one.j == two.j && one.k == two.k)
		return true;
	return false;
}
double operator ++ (Vector &one) {
	one.i++;
	one.j++;
	one.k++;
}

void editIJK(IJK* one) {
	int i, j, k;
	cout << "Изменение значения радиус-вектора (i=, j=, k=):";
	cin >> i >> j >> k;
	cout << endl;
	one->i = i;
	one->j = j;
	one->k = k;
	one->print();
}

void textBox (string alpha){
	static int iterTime;
	class text {
		public:
			text (){
				++iterTime;
			}
			void coutText(string name){
				cout<<" of iterTime ="<<iterTime<<endl;
			}
			~text(){}
	};
	
	text a;
	a.coutText(alpha);
}

int main()
{
	setlocale(LC_ALL, "rus");

	IJK obj1(5, 6, 11), obj2(13, 12, 11), obj3, obj4(&obj1);
	Vector vobj1(&obj1, &obj2);
	//editIJK(&obj3);
	Vector vobj2(&obj4, &obj3);
	Vector vobj3 = vobj1 + vobj2;
	Vector vobj4 = vobj3 - vobj1;
	
	if (vobj3 == vobj4) cout << "True" << endl;
	else cout << "False" << endl <<endl;
	
	obj1.getSubSpaceInfo(&obj1);
	string alpha = "Hello darkness my old friend";
	textBox(alpha);
		
	system("Pause");

	return 0;
}


