#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define MAXtABLESIZE 100000
typedef int ElementType;
typedef int Index;
typedef Index Position;

typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell;
struct HashEntry {
	ElementType Data;//存放元素
	EntryType Info;
};

typedef struct TblNode* HashTable;//散列表类型
struct TblNode {
	int TableSize; // 表的最大长度
	Cell* Cells; //存放散列单元数据的数组
};

int NextPrime(int N)
{
	int i, p = (N % 2) ? N + 2 : N + 1;
	while (p <= MAXtABLESIZE) {
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p % i)) break;
		if (i == 2) break;
		else p += 2;
	}
	return p;
}

HashTable CreateTable(int TableSize) {
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Cells = (Cell*)malloc(H->TableSize * sizeof(Cell));
	for (i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;
	return H;
}

int Hash(const int Key, int TableSize)
{
	unsigned int H = 0;
	int Temp = Key;
	H = (H << 5) + Temp++;
	return H % TableSize;
}

Position Find(HashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 0;
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].Data != Key) {
		if (++CNum % 2) {
			NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4;
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize;
		}
		else {
			NewPos = CurrentPos - CNum * CNum * CNum / 4;
			while (NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}

bool Insert(HashTable H, ElementType Key) {
	Position Pos = Find(H, Key);
	if (H->Cells[Pos].Info != Legitimate) {
		H->Cells[Pos].Info = Legitimate;
		H->Cells[Pos].Data = Key;
		return true;
	}
	else {
		printf("failed");
		return false;
	}
}
int main()
{
	HashTable Tb = CreateTable(25);//创建哈希表
	int flag = Insert(Tb, 99);//往哈希表插入值
	int Pos = Find(Tb, 99);//寻找哈希表的位置
	printf("data's position:%d\n", Pos);
	int data = Tb->Cells[Pos].Data;
	printf("data:%d\n", data);
	flag = Insert(Tb,99);//插入一个已经有的值47
	return 0;
}
