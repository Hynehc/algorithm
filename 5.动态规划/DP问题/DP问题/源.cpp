#define  _CRT_SECURE_NO_WARNINGS 1

//01��������
//����д��

//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];//v�������w�Ǽ�ֵ
//int f[N][N];//fΪdp
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 0;j <= m;j++)
//		{
//			f[i][j] = f[i - 1][j];//���ߵ��Ӽ�
//			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

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

//����д��

//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];//v�������w�Ǽ�ֵ
//int f[N][N];//fΪdp
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j] = f[i-1][j];//���ߵ��Ӽ�
//			//f[i][j] = f[i - 1][j];
//			if(j>=v[i])
//			f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//			//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])
//			//j>j-v[i],����j�Ӵ�С��ʼ������������f[j],��ôf[j-v[i]]Ϊi-1��f[j]
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

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
//		for (int j = v[i];j <= m ;j++)
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



//�ܽ�
//01���� f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
//��ȫ���� f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);




//ʯ�Ӻϲ�
//#include<iostream>
//using namespace std;
//const int N = 310;
//int n;
//int s[N];//ǰ׺��
//int f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> s[i], s[i] += s[i - 1];
//
//	for (int len = 2;len <= n;len++)//ö�����䳤��
//	{
//		for (int i = 1;i + len - 1 <= n;i++)//ö�ٶ˵�
//		{
//			int j = i + len - 1;//�Ҷ˵�
//			f[i][j] = 1e8;//��ʼ�����ֵ
//			for (int k = i;k < j;k++)
//			{
//				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
//			}
//		}
//	}
//	cout << f[1][n] << endl;//����Ϊ1��n
//	return 0;
//}




//�����������
//#include<iostream>
//using namespace std;
//const int N = 1000;
//int n, m;
//char a[N], b[N];
//int f[N][N];
//int main()
//{
//	cin >> n >> m >> a + 1 >> b + 1;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//			if (a[i] == b[j])
//				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
//		}
//	cout << f[n][m] << endl;
//	return 0;
//}