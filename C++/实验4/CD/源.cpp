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
	}        // ��ø��ֵ�����
	string getSong(int index) {
		return this->songs[index];
	}// ���ĳ�׸�ĸ���
	void listSongs() {
		cout << "Singer: " << this->singer << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ". " << this->songs[i] << endl;
		}
	}          // �г�CD������
private:
	string singer;		// ���ֵ����֡�
	string songs[6];		// ÿ��ר��6�׸�����֡�
};
class CDPlayer {
public:
	//CDPlayer();

	/*�ṩ���û�һ���˵���ͨ������˵����û�����ѡ��
	1. ����CD
	2. ����CD
	3. ����CD
	0. �ػ�   */
	void showMenu() {
			cout << "*****************" << endl;
			cout << "*1. " << "����CD*" << endl;
			cout << "*2. " << "����CD*" << endl;
			cout << "*3. " << "����CD*" << endl;
			cout << "*0. " << "�ػ�***" << endl;
			cout << "*****************" << endl;
	}

	/*����CD. void insertCD(CD* cd)���β���ָ��CD�����ָ�롣���CDPlayer���Ѿ���CD����ʾ��ȡ��CD�����CDPlayer��û��CD����ʾ��������λ���ǵ�CD��*/
	void insertCD(CD* cd) {
		if (this->cdIn)
		{
			cout << "����ȡ��CD��" << endl;
		}
		else
		{
			this->cd = cd;
			cout << "������" << this->cd->getSinger() << "��CD......	 " << endl;
			this->cdIn = true;
		}
	}

	/*����CD. CD *ejectCD()������ֵ��ָ���CD�����ָ�롣���CDPlayer���Ѿ���CD����ʾ��������λ���ǵ�CD�����ظ�CD��ָ�룻���CDPlayer��û��CD����ʾCDPlayer��û��CD������NULL��*/
	void ejectCD() {
		if (this->cdIn=false)
		{
			cout << "CDPlayer��û��CD!" << endl;
			//return 0;
		}
		else
		{
			cout << "������" << this->cd->getSinger() << "��CD......	 " << endl;
			this->cd = NULL;
			this->cdIn = false;
			//return 0;
		}
	}
	/*����CD�����CDPlayer���Ѿ���CD����ʾ���ڲ�����λ���ǵ�CD������ӡCD�и������嵥�����CDPlayer��û��CD����ʾCDPlayer��û��CD������ʾ�û�����CD��*/
	void play() {
		if (this->cdIn==true)
		{
			cout << "���ڲ���" << this->cd->getSinger() << "��CD......	 " << endl;
			cd->listSongs();
		}
		else
		{
			cout << "���Ȳ���CD��" << endl;
		}
	}
	void exitCD() {
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}
private:
	/* ����CDPlayer�е�CD������ָ��CD�����ָ�롣û��CDʱ��Ϊnull��ʹ��ָ�룬�ܺõ�ģ�� ��CD�����ǲ�������һ���֣�������ֻ�Ƕ�ȡ�������е�CD�����ݡ�*/
	CD* cd = NULL;
	bool cdIn = false;  // CDPlayer���Ƿ��Ѿ�����CD
};
void main() {
	string name;
	string songs[6];

	cout << "����CD......" << endl;
	// �����������
	cout << "  Singer's Name: " << endl;
	cin >> name;  // ���룺�ܽ���

	// ����ø��ֵ����׸������໨�ɡ��ջ�̨��˫�ڹ��ȣ�
	for (int i = 0; i < 6; i++) {
		cout << "  song" << (i + 1) << "#: ";
		cin >> songs[i];
	}
	int chose = 0;
	CD cd(name, songs);   //����CD
	cd.listSongs();       //��ʾCD������
	CDPlayer player;      //����CDplayer
	
	while (true)
	{
		player.showMenu(); 
		//���ɲ��Ż��İ�ť
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
	
	///* ���� */
	//player.play();         //��ӡ��Please insert CD first
	///* ����CD */
	//player.insertCD(&cd); //��ӡ���������ܽ��׵�CD......
	///* ���� */
	//player.play();         //��ӡ�����ڲ����ܽ��׵�CD......
	//player.ejectCD();      //��ӡ���������ܽ��׵�CD......

	/* ����һ��CD�����ֺ͸��¼��ʡ�ԡ�*/
	/*CD cd2(name2, songs2);
	player.insertCD(&cd2);
	player.play();*/
}