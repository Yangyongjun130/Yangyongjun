#include <stdio.h>
#include <stdlib.h>
#define GOODS_COUNT  10		//定义物品的数量 
#define BOX_VOLUME 20		//定义箱子的体积大小 

typedef struct goods			//物品信息结构 
{
	int goods_num;				//物品号 
	int goods_volume;			//物品体积大小 
} ElementGoods;

typedef struct goods_node		//物品结点信息 
{
	int goods_num;				//物品号 
	int goods_volume; 			//物品体积 
	struct goods_node* next;
} GoodsLink;

typedef struct box_node			//箱子结点 
{
	int remember;				//箱子剩余体积 
	GoodsLink* goods_head;		//物品头结点 
	struct box_node* next;
} BoxLink;

void init_goods_info(ElementGoods data[])		//初始化物品信息 
{
	//自定义每个物品体积大小 
	int temp_vlume[GOODS_COUNT] = { 3, 1, 5, 7, 18, 10, 12, 11, 14, 15 };
	for (int i = 0; i < GOODS_COUNT; ++i)
	{
		data[i].goods_num = i + 1;
		data[i].goods_volume = BOX_VOLUME;
		data[i].goods_volume = temp_vlume[i];
	}

	int exchange = 1;		//是否排过序标志 
	ElementGoods temp;
	for (int i = 0; i < GOODS_COUNT && exchange; ++i)
	{
		exchange = 0;
		for (int j = 0; j < GOODS_COUNT - i - 1; ++j)
		{
			if (data[j].goods_volume < data[j + 1].goods_volume)
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				exchange = 1;
			}
		}
	}

}


BoxLink* packing_box(ElementGoods data[])
{
	BoxLink* box_head = NULL, * box_tail = NULL, * p = NULL;
	GoodsLink* new_goods, * goods_tail = NULL, * q = NULL;

	for (int i = 0; i < GOODS_COUNT; ++i)
	{
		//从头开始找能够放下当前物品体积大小的箱子 
		p = box_head;
		while (p && (p->remember < data[i].goods_volume))
			p = p->next;

		//是第一个箱子，或者找完了所有已经打开的箱子，放不下当前物品
		//需要打开一个新的箱子 
		if (!p)
		{
			p = (BoxLink*)malloc(sizeof(BoxLink));
			p->remember = BOX_VOLUME;
			p->goods_head = NULL;
			p->next = NULL;

			if (!box_head)
				box_head = box_tail = p;
			else
				box_tail = box_tail->next = p;
		}

		//生成新的物品
		//放进去物品之后，当前箱子体积为减去物品体积后的大小 
		p->remember -= data[i].goods_volume;
		new_goods = (GoodsLink*)malloc(sizeof(GoodsLink));
		new_goods->goods_num = data[i].goods_num;
		new_goods->goods_volume = data[i].goods_volume;
		new_goods->next = NULL;

		//找物品尾结点 
		for (q = p->goods_head; q && q->next; q = q->next)
			;
		if (!q)
			p->goods_head = new_goods;
		else
			q->next = new_goods;
	}

	return box_head;
}


void output_box_info(BoxLink* box_head)
{
	BoxLink* ptr = box_head;
	GoodsLink* t = NULL;
	int i, cnt = 1;
	while (ptr)
	{
		printf("Box %d:\n", cnt++);
		printf("\tremember = %d \n", ptr->remember);
		printf("\tgoods : ");

		t = ptr->goods_head;
		i = 1;
		while (t)
		{
			printf("(%d goods num:%d, reamin volume:%d)  ", i++, t->goods_num, t->goods_volume);
			t = t->next;
		}
		printf("\n");
		ptr = ptr->next;
	}
}


int main(int argc, char const* argv[])
{
	ElementGoods goods_data[GOODS_COUNT] = { 0 };
	BoxLink* box_head;

	init_goods_info(goods_data);
	box_head = packing_box(goods_data);
	output_box_info(box_head);

	return 0;
}
