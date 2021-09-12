#include<iostream>
#include<string>
using namespace std;
class CD {
public:
	CD(string name, string songs[]) {
		this->singer = name;
		for (int i = 0; i < 6; i++)
		{
			this->songs[i] = songs[i];
		}
	}
	string getSinger() {
		return this->singer;
	}        // 获得歌手的名称
	string getSong(int index) {
		return this->songs[index];
	}// 获得某首歌的歌名
	void listSongs() {
		cout << "Singer: " << this->singer << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ". " << this->songs[i] << endl;
		}
	}          // 列出CD的内容
private:
	string singer;		// 歌手的名字。
	string songs[6];		// 每张专辑6首歌的名字。
};
class CDPlayer {
public:
	//CDPlayer();

	/*提供给用户一个菜单，通过这个菜单，用户可以选择：
	1. 插入CD
	2. 播放CD
	3. 弹出CD
	0. 关机   */
	void showMenu() {
			cout << "*****************" << endl;
			cout << "*1. " << "插入CD*" << endl;
			cout << "*2. " << "播放CD*" << endl;
			cout << "*3. " << "弹出CD*" << endl;
			cout << "*0. " << "关机***" << endl;
			cout << "*****************" << endl;
	}

	/*插入CD. void insertCD(CD* cd)，形参是指向CD对象的指针。如果CDPlayer中已经有CD，提示先取出CD；如果CDPlayer中没有CD，显示插入了哪位歌星的CD。*/
	void insertCD(CD* cd) {
		if (this->cdIn)
		{
			cout << "请先取出CD！" << endl;
		}
		else
		{
			this->cd = cd;
			cout << "插入了" << this->cd->getSinger() << "的CD......	 " << endl;
			this->cdIn = true;
		}
	}

	/*弹出CD. CD *ejectCD()，返回值是指向该CD对象的指针。如果CDPlayer中已经有CD，显示弹出了哪位歌星的CD，返回该CD的指针；如果CDPlayer中没有CD，提示CDPlayer中没有CD，返回NULL。*/
	void ejectCD() {
		if (this->cdIn=false)
		{
			cout << "CDPlayer中没有CD!" << endl;
			//return 0;
		}
		else
		{
			cout << "弹出了" << this->cd->getSinger() << "的CD......	 " << endl;
			this->cd = NULL;
			this->cdIn = false;
			//return 0;
		}
	}
	/*播放CD。如果CDPlayer中已经有CD，显示正在播放哪位歌星的CD，并打印CD中歌曲的清单；如果CDPlayer中没有CD，显示CDPlayer中没有CD，并提示用户插入CD。*/
	void play() {
		if (this->cdIn==true)
		{
			cout << "正在播放" << this->cd->getSinger() << "的CD......	 " << endl;
			cd->listSongs();
		}
		else
		{
			cout << "请先插入CD！" << endl;
		}
	}
	void exitCD() {
		cout << "欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}
private:
	/* 插入CDPlayer中的CD，它是指向CD对象的指针。没有CD时，为null。使用指针，很好地模拟 了CD对象不是播放器的一部分，播放器只是读取放入其中的CD的内容。*/
	CD* cd = NULL;
	bool cdIn = false;  // CDPlayer中是否已经插入CD
};
void main() {
	string name;
	string songs[6];

	cout << "制造CD......" << endl;
	// 输入歌手名字
	cout << "  Singer's Name: " << endl;
	cin >> name;  // 输入：周杰伦

	// 输入该歌手的六首歌名（青花瓷、菊花台、双节棍等）
	for (int i = 0; i < 6; i++) {
		cout << "  song" << (i + 1) << "#: ";
		cin >> songs[i];
	}
	int chose = 0;
	CD cd(name, songs);   //制造CD
	cd.listSongs();       //显示CD的内容
	CDPlayer player;      //制造CDplayer
	
	while (true)
	{
		player.showMenu(); 
		//生成播放机的按钮
		cin >> chose;
		switch (chose)
		{
		case 1:
			player.insertCD(&cd);
			system("pause");
			system("cls");
			break;
		case 2:
			player.play();
			system("pause");
			system("cls");
			break;
		case 3:
			player.ejectCD();
			system("pause");
			system("cls");
			break;
		case 0:
			player.exitCD();
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	}
	
	///* 播放 */
	//player.play();         //打印：Please insert CD first
	///* 插入CD */
	//player.insertCD(&cd); //打印：插入了周杰伦的CD......
	///* 播放 */
	//player.play();         //打印：正在播放周杰伦的CD......
	//player.ejectCD();      //打印：弹出了周杰伦的CD......

	/* 另造一张CD，歌手和歌的录入省略。*/
	/*CD cd2(name2, songs2);
	player.insertCD(&cd2);
	player.play();*/
}