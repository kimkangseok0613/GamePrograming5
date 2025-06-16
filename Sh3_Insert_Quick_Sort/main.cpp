#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� ����
// - Ư�� ���� ���ĵ� ��ġ�� �ű�� ���
// - �տ������� �����͸� �����Ѵ�.
//

void InsertSort(int arr[], int n)
{
	// �� �� cycle ���ƾ� �ϳ���?
	for (int i = 1;i < n;i++)
	{
		// ���� key�� ���� �����ΰ�?
		int key = arr[i];

		// key�� �� ������ ����� �񱳸� �ض�.
		int j = i - 1;

		// while() ������ true�� �� �߰�ȣ { } �ڵ带 �����϶�.
		while (j >= 0 && arr[j] > key) // j�� ���� key���� ������ �Ǵ� �ε����� ���� 0���� Ŭ��
		{
			arr[j + 1] = arr[j]; // ������ �����Ϳ� ���� ���� �������� ��ġ�� �����ض�
			j--; // ���� key�� ��ġ
			
		}
		arr[j + 1] = key;
	}
}

void InsertSort(vector<int> nums)
{
	// �� �� cycle ���ƾ� �ϳ���?
	int n = nums.size();
	for (int i = 1;i < n;i++)
	{
		// ���� key�� ���� �����ΰ���?
		int key = nums[i];
		int j = i - 1;
		// key ���ʿ� �ִ� ��� �����͵�� ���ؼ� ��ġ�� ã�� �Ŀ� �� ��ġ�� ����.
		while (j >= 0 && nums[j] > key) // j�� ���� 0���� ũ�ų� ������ �Ǵ� key�� ���� ���ʿ� �ִ� ������ ������
		{
			// ������ ���ʰ� key�� ����ִ� ���� �����ϰ�
			// index�� �������� �̵��ؼ� ���� ���� �� ���Ѵ�.
			nums[j + 1] = nums[j];
			j--;
		}
		// ��ġ�� ã������ �ش� ��ġ�� key�� �����ض�.
		nums[j + 1] = key;
	}
}

// ���� : ��� ��쿡 ��ġ ������ �߻��ϴ� ���� �ƴ϶�, while ���ǿ� �ش� �� ���� ��ġ ����(swap)�� �߻��Ѵ�.
// �����̳� �����Ͱ� ���ĵǾ� �������� ���� �ӵ��� ������. "���� ����" ����, n*logN
// ����Ŭ : n
// while() 1 ~ n ũ�⸦ ���� �� �ִ�.
// �ּ��� ��� 0(n) ���, �־��� ��� (0N*2))
// ���� : n�� ������ ����ؼ� �ð��� �ɸ���.
// 
// log �ð��� �󸶳� ������?
// 2^10 = 1,024 // �뷫 1,000
// 2^20 = 2^10 * 2^10 // 1,000,000 �뷫 �鸸
// log2(2^20) = 20; n��(�鸸��) log n�� (20��)
// 
// �ð��� �����ϱ� ���ؼ� logn���� ǥ���ϴ� ����� ã�´�.
// "���� ����" �˰���
//

#pragma region �� ����

// ������ pivot�� ���Ѵ�. ���� ������ ���� �ǹ����� �Ѵ�.
// pivot �ǹ� : ������
// ���� ���� �˰���. ������ �ϱ� ���� �����̴�.
// Ư¡ : ���� ���� �˰����� ����ϰ� �ִ�. ��� �Լ��� �����ȴ�.
// ��� 0(n * logn) �ð��� ���´�.
// 0(n^2) ���� ������� �˰����� ���ϼ���.(����, ����, ����)
// 0(n log n) ���� ������� �˰����� ���ϼ���.(��, ����)
//

void quickSort(int data[], int start, int end)
{
	if (start >= end) // �����Ͱ� 1���� ������, ��� �Լ��� ������ ���� ����
	{
		return;
	}

	int pivot = start;	// ������ �Ǵ� ��
	int i = start + 1;	// ���ʿ��� ������ ��ġ
	int j = end;		// �����ʿ��� ������ ��ġ
	int temp;			// swap ����ϱ� ���� �ӽ� ����

	while (i <= j) // ���� �ε����� ������ �ε����� �߿����� ������ �ݺ�
	{
		while (data[i] <= data[pivot]) // �ǹ����� ū ���� ������ �� ���� ã�ƶ�
		{
			// ������ ��� i�� �������Ѷ�
			i++;
		}
		while (j > start && data[j] >= data[pivot]) // �ǹ����� ���� ���� ������ �� ���� �����ض�
		{
			// j�� ���� �������ִ� �ڵ�
			j--;
		}

		// i > j // ���� �ε����� ������ �ε������� ũ�� (�����ȴ�) �ǹ��� �ִ� ���� j�� ���� �����ϼ���.
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
			//swap(data[pivot], data[j]);
		}
		else // �������� �ʾ����� (j�� i�� �ִ� ���� �����ϼ���)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}

		// ��� �Լ�
		// quicksort(���� ��Ʈ)  quicksort(������ ��Ʈ)
		// ���� �ǹ��� ��ġ�� j�������� ���� ţ ��Ʈ�� �����ϰ� ������ �� ��Ʈ �Լ��� �����غ�����.
		quickSort(data, start, j-1);	// ����
		quickSort(data, j+1, end);		// ������
	}

}

void quickSort(vector<int> data, int start, int end)
{

}

#pragma endregion


int main()
{
	cout << "���� ���� �迭 ����" << endl;

	int arr1[10] = { 3,5,9,1,2,4,6,8,7,0 };

	InsertSort(arr1, 10);

	for (int i = 0;i < 10;i++)
	{
		cout << arr1[i] << " ";
	}

	cout << "\n\n���� ���� vector ����" << endl;

	vector<int> nums1 = { 3,5,9,1,2,4,6,8,7,0 };

	InsertSort(nums1);
	
	for (int num : nums1)
	{
		cout << num << " ";
	}

	cout << "\n\n�� ���� �迭 ����" << endl;
	int arr2[10] = { 3,5,9,1,2,4,6,8,7,0 };
	quickSort(arr2, 0, 9);
	for (int i = 0;i < 10;i++)
	{
		cout << arr2[i] << " ";
	}

	cout << "\n\n�� ���� vector ����" << endl;
	vector<int> nums2 = { 3,5,9,1,2,4,6,8,7,0 };
	quickSort(nums1, 0, nums2.size()-1);
	for (int num : nums2)
	{
		cout << num << " ";
	}
}