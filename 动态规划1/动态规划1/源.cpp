#define  _CRT_SECURE_NO_WARNINGS 1



//01��������
//����д��

#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v�������w�Ǽ�ֵ
int f[N][N];//fΪdp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			f[i][j] = f[i - 1][j];//���ߵ��Ӽ�
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}

//�Ż�д��(�ռ�)
//�Ӵ�������ϻ������--��ά->һά

//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];//v�������w�Ǽ�ֵ
//int f[N];//fΪdp
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = m;j >= v[i];j--)
//		{
//			f[j] = f[j];//���ߵ��Ӽ�
//			//f[i][j] = f[i - 1][j];
//
//			f[j] = max(f[j], f[j - v[i]] + w[i]);
//			//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])
//			//j>j-v[i],����j�Ӵ�С��ʼ������������f[j],��ôf[j-v[i]]Ϊi-1��f[j]
//		}
//	}
//	cout << f[m] << endl;
//	return 0;
//}





//��ȫ��������
//������ѭ��˳���С����

//����д��--��ά

#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v�������w�Ǽ�ֵ
int f[N][N];//fΪdp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			for (int k = 0;k * v[i] <= j;k++)
			{
				f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}


//�Ż�--��ά
#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v�������w�Ǽ�ֵ
int f[N][N];//fΪdp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}




//�Ż�д��(�ռ�)
//�Ӵ�������ϻ������--��ά->һά

#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v�������w�Ǽ�ֵ
int f[N];//fΪdp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = v[i];j <= m ;j++)
		{
			f[j] = f[j];//���ߵ��Ӽ�
			//f[i][j] = f[i - 1][j];

			f[j] = max(f[j], f[j - v[i]] + w[i]);
			//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])
			//j>j-v[i],����j�Ӵ�С��ʼ������������f[j],��ôf[j-v[i]]Ϊi-1��f[j]
		}
	}
	cout << f[m] << endl;
	return 0;
}



//�ܽ�
//01���� f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
//��ȫ���� f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);





//���ر������� I
//���ؽⷨ
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N][N];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i] >> s[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
			for (int k = 0;k <= s[i] && k * v[i] <= j;k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
	cout << f[n][m] << endl;
}



//���ر������� II -- �������Ż�
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 25000, M = 2010;
int n, m;
int v[N], w[N];
int f[N];
int main()
{
	cin >> n >> m;
	int cnt = 0; //��������
	for (int i = 1;i <= n;i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		int k = 1;// �������ĸ���
		while (k <= s)
		{
			cnt++; //���������
			v[cnt] = a * k;//�������
			w[cnt] = b * k;// �����ֵ
			s -= k;// sҪ��С
			k *= 2;// �����ĸ�������
		}
		//ʣ���һ��
		if (s > 0)
		{
			cnt++;
			v[cnt] = a * s;
			w[cnt] = b * s;
		}
	}
	n = cnt;//ö�ٴ�����ʽ�ɸ�����������
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= v[i];j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	cout << f[m] << endl;
}





//���鱳������
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int n, m;
int v[N][N], w[N][N], s[N];
int f[N];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		for (int j = 0;j < s[i];j++)
			cin >> v[i][j] >> w[i][j];
	}
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= 0;j--)
			for (int k = 0;k < s[i];k++)
				if (v[i][k] <= j)
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
	cout << f[m] << endl;
}