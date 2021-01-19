#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

const int MaxSize = 5000;

class Dict
{
public:
	typedef struct node
	{
		string Chinese;
		string English;
	}Node;
	Dict();
	~Dict();
	void Insert(string x,string y);
	string Delete(string x);
	string EntoZh(string x);
	string ZhtoEn(string x);
	int Find(string x,bool flag);
	void run(Dict *dict,int n);
private:
	int length;
	Node data[MaxSize];
};

vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//�ҵ��ַ������׸������ڷָ�������ĸ��
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

Dict::Dict()
{
	ifstream fin("cet4word.txt");
	string temp;
	int i = 0;
	cout << "Loding..." << endl;
	while (getline(fin,temp) && i<MaxSize)
	{
		vector<string> s = split(temp," ");
		data[i].English = s[0];
		data[i].Chinese = s[1];
		
		//cout << data[i].English << " " << data[i].Chinese << endl;
		i++;
	}
	length = i;
	cout << "Loaded dictionary successful!" << endl;
}

Dict::~Dict()
{
}
/*
Find�������Ҵ����Ƿ���ڣ������м亯��Ҳ�ɵ���ʹ��
string x Ϊ����Ҫ��ѯ��Ӣ�ĵ���
����ֵΪ�����ҵĵ���λ�ã����δ�ҵ�����-1
*/
int Dict::Find(string x,bool flag)
{
	for (int i = 0; i < length; i++)
	{
		if (x.compare(data[i].English) == 0) {
			if (flag) return i;
			else {
				//cout << "This word is already here!" << endl;
				return -1;
			}
		}
		else if (x.compare(data[i].English) < 0 || i == length-1)
		{
			if (flag) return -1;
			else return i;
		}
	}
}

/*
Insert���������x,y�ֱ�ΪӢ��������
*/
void Dict::Insert(string x, string y)
{
	if (length >= MaxSize)
	{
		cout << "Overflow!" << endl;
		throw "Overflow";
	}
	int index = Find(x,false);
	if (index == -1) {
		cout << "Please do not insert repeatly!" << endl;
		return;
	}
	else {
		for (int i = length; i > index+1; i--) {
			data[i].English = data[i - 1].English;
			data[i].Chinese = data[i - 1].Chinese;
		}
		data[index].English = x;
		data[index].Chinese = y;
		length++;
		cout << "Insert Successful!" << endl;
	}
}

/*
Deleteɾ��������ɾ����Ӣ�Ĵ���
����ֵΪ��������
*/
string Dict::Delete(string x)
{
	if (length <= 0) {
		cout << "Underflow!" << endl;
		throw "Underflow";
	}
	else
	{
		int index = Find(x,true);
		string temp[2];
		if (index == -1) {
			//cout << "Cannot Found this word!" << endl;
			return "NULL";
		}
		else
		{
			temp[0] = data[index].English;
			temp[1] = data[index].Chinese;
			for (int i = index; i < length; i++) {
				data[i].Chinese = data[i + 1].Chinese;
				data[i].English = data[i + 1].English;
			}
			length--;
			return temp[0] + " " + temp[1];
		}
	}
}

string Dict::EntoZh(string x)
{
	int s = Find(x, true);
	if (s == -1)
	{
		//cout << "Cannot find this word!" << endl;
		return "NULL";
	}
	else
	{
		string temp = data[s].Chinese;
		return temp;
	}
}

string Dict::ZhtoEn(string x)
{
	string res = "";
	bool flag = false;
	for (int i = 0; i < length; i++)
	{
		if (data[i].Chinese.find(x, 0) != string::npos)
		{
			flag = true;
			res += (data[i].English + " ");
		}
	}
	if (flag) {
		
		return res;
	}
	else
	{
		return "NULL";
	}
}

void Dict::run(Dict *dict,int n)
{
	string English,Chinese;
	int ind;
	switch (n)
	{
	case 0:
		exit(0);
		break;
	case 1:
		cin >> English >> Chinese;
		dict->Insert(English, Chinese);
		break;
	case 2:
		cin >> English;
		ind = dict->Find(English, false);
		if(ind == -1) cout << "This word is already here!" << endl;
		else cout << "Cannot found this word!" << endl;
		break;
	case 3:
		cin >> English;
		English = dict->EntoZh(English);
		if(English != "NULL") cout << English << endl;
		else cout << "Cannot found this word!" << endl;
		break;
	case 4:
		cin >> Chinese;
		Chinese = dict->ZhtoEn(Chinese);
		if (Chinese != "NULL") cout << Chinese << endl;
		else cout << "Cannot found this word!" << endl;
		break;
	case 5:
		cin >> English;
		English = dict->Delete(English);
		if(English != "NULL") cout<<"Successful delete: "<<English<<endl;
		else cout << "Cannot Found this word!" << endl;
		break;
	default:
		break;
	}
}

int main()
{
	Dict *dict = new Dict();
	int in;
	cout << "1. Insert" << endl;
	cout << "2. Find" << endl;
	cout << "3. English To Chinese" << endl;
	cout << "4. Chinese To English" << endl;
	cout << "5. Delete" << endl;
	cout << "0. exit" << endl;
	while (cin>>in)
	{
		dict->run(dict,in);
	}
	return 0;
}