#include<iostream>
using namespace std;
#include<string>

class Cart;
class Commodity {
	friend class Cart;// ��Ʒ��
public:
	Commodity() {

	}
	Commodity(string name, int price, int num) {
		this->name = name;
		this->price = price;
		this->num = num;
	}
	void printInfo() {
		cout << " ��Ʒ�������ǣ� " << this->name << ' ' << "�۸��ǣ� " << this->price << ' ' << "�����ǣ�" << this->num << endl;
	}  // �������Ʒ����Ϣ�����ơ����Ƽ۸񡢹�������
private:
	string name;
	int price;
	int num;
};

class Cart {                                 // ���ﳵ��
public:
	Cart() {

	}
	void addItem(Commodity& item) {
		this->iterms[step] = item;
		step++;
		this->SumPrice += item.num * item.price;
	}                      // ���һ����������Ʒ�����ﳵ
	void checkout() {
		/*cout << "����Ҫ֧��" << this->SumPrice << "Ԫ��" << endl;*/
		//return SumPrice;
		cout << endl;
	}// �Թ��ﳵ�е���Ʒ���н���
	void printInvoice(){
		cout << "����Ҫ֧��" << this->SumPrice << "Ԫ��" << endl;
		for (int i = 0; i < this->step; i++)
		{
			cout << this->iterms[i].name << ' ' << this->iterms[i].price << ' ' << this->iterms[i].num << endl;
		}
	}               // ����Ʒ��Ϣ�������ʾ��
private:
	Commodity iterms[20];
	int SumPrice = 0;
	int step = 0;
};

int main() {
	Commodity tShirt("Tshirt", 79, 2);// ������װ�������ơ��۸�����
	Commodity suit("suit", 1099, 1);  // ��װ
	Commodity hat("hat", 129, 3);  // ñ��
	Commodity tv("tv set", 4899, 1); // �����ҵ�������ơ��۸�����
	Commodity ac("air condition", 5280, 1);// �յ�
	Cart myCart;
	//����Ʒ��ӵ����ﳵ
	myCart.addItem(tShirt);
	myCart.addItem(suit);
	myCart.addItem(hat);
	myCart.addItem(tv);
	myCart.addItem(ac);

	myCart.checkout();   // ���ﳵ��Ʒ���㣬��ʾ�˿���Ҫ֧�����ܽ��
	myCart.printInvoice(); // �������嵥�������ʾ����

	return 0;
}