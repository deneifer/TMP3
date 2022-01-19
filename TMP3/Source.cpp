//#include <iostream>
//#include <new>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//
//class strt {
//	const char* p;
//	int size;
//public:
//	strt();
//	strt(const char* str);
//	strt(const strt& o); // ����������� �����
//
//	~strt() { delete[] p; }
//
//	friend ostream& operator<<(ostream& stream, strt& o);
//	friend istream& operator>>(istream& stream, strt& o);
//
//	strt operator=(strt& o); // assign a StrType object
//	strt operator=(const char* s); // assign a quoted string
//
//	strt operator+(strt& o); // concatenate a StrType object
//	strt operator+(const char* s); // concatenate a quoted string
//	friend strt operator+(const char* s, strt& o); /*  concatenatea quoted string with a StrType object */
//
//
//	strt substr(strt& str, int start, int length = 0)//��������� ���������
//	{
//		char* s;
//		// ���������� ����� �������� ������
//		int len = 0;
//		for (int i = 0; str[i] != '\0'; i++)
//			len++;
//		// ���������� ������� ���������� ������� ���������
//		if (length > 0)
//		{
//			if (start + length < len)
//				len = start + length;
//		}
//		else // length < 0
//			len = len + length;
//		int newlen = len - start + 1; // ����� ���������
//		s = new char[newlen];
//		// ����������� �������� ���������
//		int j = 0;
//		for (int i = start; i < len; i++)
//		{
//			s[j] = str[i]; j++;
//		}
//		s[j] = '\0';
//		return(s);
//	}
//
//	int pos(strt& s, const char* c, int n)//����� ���������
//	{
//		int i, j; // �������� ��� ������
//		int lenC, lenS; // ����� �����
//
//		//������� ������� ������ ��������� � ��������
//		for (lenC = 0; c[lenC]; lenC++);
//		for (lenS = 0; s[lenS]; lenS++);
//
//		for (i = 0; i <= lenS - lenC; i++) // ���� ���� ����������� ������
//		{
//			for (j = 0; s[i + j] == c[j]; j++); // ��������� ���������� �����������
//			// ���� ����������� ��������� �� ����� �������� - ������� ����� ������, ������ ���������� ����������
//
//			if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) return i;
//			if (j == lenC)
//				if (n - 1) n--;
//				else return i;
//		}
//		//����� ������ -1 ��� ��������� ���������� ���������
//		return -1;
//	}
//
//	int strsize() { return strlen(p); } // return size of string
//	void makestr(char* s) { strcpy(s, p); } // null-terminated string
//	operator const char* () { return p; } // conversion to char *
//};
//
//
//strt::strt() {
//	size = 1;
//
//	p = new const char[size];
//
//	strcpy((char*)p, "");
//}
//
//
//strt::strt(const char* str) {
//	size = strlen(str) + 1;
//
//	p = new const char[size];
//
//	strcpy((char*)p, str);
//}
//
//// Initialize using a StrType object.
//strt::strt(const strt& o) {
//	size = o.size;
//	try {
//		p = new const char[size];
//	}
//	catch (bad_alloc xa) {
//		cout << "Allocation error\n";
//		exit(1);
//	}
//	strcpy((char*)p, o.p);
//}
//
//// Output a string.
//ostream& operator<<(ostream& stream, strt& o)
//{
//	stream << o.p;
//	return stream;
//}
//
//// Input a string.
//istream& operator>>(istream& stream, strt& o)
//{
//	char t[255]; // arbitrary size - change if necessary
//	int len;
//
//	stream.getline(t, 255);
//	len = strlen(t) + 1;
//
//	if (len > o.size) {
//		delete[] o.p;
//		try {
//			o.p = new const char[len];
//		}
//		catch (bad_alloc xa) {
//			cout << "Allocation error\n";
//			exit(1);
//		}
//		o.size = len;
//	}
//	strcpy((char*)o.p, t);
//	return stream;
//}
//
//// Assign a StrType object to a StrType object.
//strt strt::operator=(strt& o)
//{
//	strt temp(o.p);
//
//	if (o.size > size) {
//		delete[] p; // free old memory
//		try {
//			p = new char[o.size];
//		}
//		catch (bad_alloc xa) {
//			cout << "Allocation error\n";
//			exit(1);
//		}
//		size = o.size;
//	}
//
//	strcpy((char*)p, o.p);
//	strcpy((char*)temp.p, o.p);
//
//	return temp;
//}
//
//// Assign a quoted string to a StrType object.
//strt strt::operator=(const char* s)
//{
//	int len = strlen(s) + 1;
//	if (size < len) {
//		delete[] p;
//		try {
//			p = new char[len];
//		}
//		catch (bad_alloc xa) {
//			cout << "Allocation error\n";
//			exit(1);
//		}
//		size = len;
//	}
//	strcpy((char*)p, s);
//	return *this;
//}
//
//// Concatenate two StrType objects.
//strt strt::operator+(strt& o)
//{
//	int len;
//	strt temp;
//
//	delete[] temp.p;
//	len = strlen(o.p) + strlen(p) + 1;
//	temp.size = len;
//	try {
//		temp.p = new char[len];
//	}
//	catch (bad_alloc xa) {
//		cout << "Allocation error\n";
//		exit(1);
//	}
//	strcpy((char*)temp.p, p);
//
//	strcat((char*)temp.p, o.p);
//
//	return temp;
//}
//
//// Concatenate a StrType object and a quoted string.
//strt strt::operator+(const char* s)
//{
//	int len;
//	strt temp;
//
//	delete[] temp.p;
//
//	len = strlen(s) + strlen(p) + 1;
//	temp.size = len;
//	try {
//		temp.p = new char[len];
//	}
//	catch (bad_alloc xa) {
//		cout << "Allocation error\n";
//		exit(1);
//	}
//	strcpy((char*)temp.p, p);
//
//	strcat((char*)temp.p, s);
//
//	return temp;
//}
//
//// Concatenate a quoted string and a StrType object.
//strt operator+(const char* s, strt& o)
//{
//	int len;
//	strt temp;
//
//	delete[] temp.p;
//
//	len = strlen(s) + strlen(o.p) + 1;
//	temp.size = len;
//	try {
//		temp.p = new char[len];
//	}
//	catch (bad_alloc xa) {
//		cout << "Allocation error\n";
//		exit(1);
//	}
//	strcpy((char*)temp.p, s);
//
//	strcat((char*)temp.p, o.p);
//
//	return temp;
//}
//
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	int x;
//	strt s1("sd");
//	int count = 0;
//	cout << "������� ������: ";
//	string str;
//	cin >> str;
//	s1 = str.data();
//	cout << "����� ���������� ����� ������ ������� - 4 " << endl;
//	cout << "����� ���������� ������ ������� - 5 " << endl;
//	cout << "����� ������������ ������ ������� - 6 " << endl;
//	cout << "��� ��������� ��������� ������� - 7 " << endl;
//	cout << "��� ������ ��������� ��������� ������� - 8 " << endl;
//	cout << "��� ������ ������� - 0 " << endl;
//	while (count == 0)
//	{
//		string s;
//		cin >> s;
//		if (s == "4")
//		{
//			cout << endl << "����� ������: " << s1.strsize() << endl;
//
//		}
//		if (s == "5")
//		{
//			cout << endl << "��� ������: " << s1 << endl;
//		}
//		if (s == "6")
//		{
//			string str;
//			cout << "������� ����� ��� ���������: ";
//			cin >> str;
//			s1 = s1 + str.data();
//		}
//		if (s == "7")
//		{
//			cout << "������� �������� ��� ��������� ��������� (� ������ �������, ������� ��������): " << endl;
//			int a = 0, b = 0;
//			cin >> a;
//			cin >> b;
//			cout << "���������: " << s1.substr(s1, a, b) << endl;
//		}
//		if (s == "8")
//		{
//			cout << "������� ��������� ��� �������� �� ���������: ";
//			string str;
//			cin >> str;
//			int i, n = 0;
//			cout << "��������� ������ � ������ ������� � �������: " << endl;
//			for (i = 1; n != -1; i++)
//			{
//				n = s1.pos(s1, str.data(), i);
//
//				if (n >= 0)
//					std::cout << n << std::endl;
//			}
//
//		}
//		if (s == "0")
//		{
//			count++;
//		}
//	}
//
//
//	//strt s2(s1);
//	//strt s3;
//	//char s[80];
//
//	//cout << s1 << s2;
//
//	//s3 = s1;
//	//cout << s1;
//
//	//s3.makestr(s);
//	//cout << "Convert to a string: " << s;
//
//	//s2 = "This is a new string.";
//	//cout << s2 << endl;
//
//	//strt s4(" So is this.");
//	//s1 = s2 + s4;
//	//cout << s1 << endl;
//
//
//	//if (s2 > "ABC") cout << "s2 greater than ABC\n\n";
//
//	//s1 = "one two three one two three\n";
//	//s2 = "two";
//	//cout << "Initial string: " << s1;
//	//
//
//	//cout << endl;
//	//s4 = "Hi there!";
//	//s3 = s4 + " C++ strings are fun\n";
//	//cout << s3;
//
//	//cout << "Enter a string: ";
//	//cin >> s1;
//	//cout << s1 << endl;
//	//cout << "s1 is " << s1.strsize() << " characters long.\n";
//
//	//puts(s1); // convert to char *
//
//	//s1 = s2 = s3;
//	//cout << s1 << s2 << s3;
//
//	//s1 = s2 = s3 = "Bye ";
//	//cout << s1 << s2 << s3;
//
//	//cout<<s1.substr(s1, 1, 1)<<endl;
//
//	//cout << "Enter a string: ";
//	//cin >> s2;
//
//	//int i, n = 0;
//
//	//for (i = 1; n != -1; i++)
//	//{
//	//	n = s2.pos(s2, "ty", i);
//
//	//	if (n >= 0)
//	//		std::cout << n << std::endl;
//	//}
//
//	//cout << s1.pos(s2, "ty", 2) << endl;
//
//
//
//	system("PAUSE");
//	return 0;
//}