#include<iostream>
using namespace std;
#include<string>

class Cart;
class Commodity {
	friend class Cart;// 商品类
public:
	Commodity() {

	}
	Commodity(string name, int price, int num) {
		this->name = name;
		this->price = price;
		this->num = num;
	}
	void printInfo() {
		cout << " 商品的名称是： " << this->name << ' ' << "价格是： " << this->price << ' ' << "数量是：" << this->num << endl;
	}  // 输出该商品的信息：名称、标牌价格、购买数量
private:
	string name;
	int price;
	int num;
};

class Cart {                                 // 购物车类
public:
	Cart() {

	}
	void addItem(Commodity& item) {
		this->iterms[step] = item;
		step++;
		this->SumPrice += item.num * item.price;
	}                      // 添加一定数量的商品到购物车
	void checkout() {
		/*cout << "您需要支付" << this->SumPrice << "元。" << endl;*/
		//return SumPrice;
		cout << endl;
	}// 对购物车中的商品进行结算
	void printInvoice(){
		cout << "您需要支付" << this->SumPrice << "元。" << endl;
		for (int i = 0; i < this->step; i++)
		{
			cout << this->iterms[i].name << ' ' << this->iterms[i].price << ' ' << this->iterms[i].num << endl;
		}
	}               // 将商品信息输出到显示器
private:
	Commodity iterms[20];
	int SumPrice = 0;
	int step = 0;
};

int main() {
	Commodity tShirt("Tshirt", 79, 2);// 创建服装对象，名称、价格、数量
	Commodity suit("suit", 1099, 1);  // 套装
	Commodity hat("hat", 129, 3);  // 帽子
	Commodity tv("tv set", 4899, 1); // 创建家电对象，名称、价格、数量
	Commodity ac("air condition", 5280, 1);// 空调
	Cart myCart;
	//将商品添加到购物车
	myCart.addItem(tShirt);
	myCart.addItem(suit);
	myCart.addItem(hat);
	myCart.addItem(tv);
	myCart.addItem(ac);

	myCart.checkout();   // 购物车商品结算，显示顾客需要支付的总金额
	myCart.printInvoice(); // 将购物清单输出到显示器上

	return 0;
}