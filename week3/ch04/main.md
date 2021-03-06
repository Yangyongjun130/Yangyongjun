# 归并排序的实现及相关操作

## 归并排序实现思路
归并排序（Merge sort）是建立在归并操作上的一种有效的排序算法，归并排序对序列的元素进行逐层折半分组，然后从最小分组开始比较排序，合并成一个大的分组，逐层进行，最终所有的元素都是有序的

## 相关性质
1.时间复杂度
归并排序算法每次将序列折半分组，共需要logn轮，因此归并排序算法的时间复杂度是O(nlogn)
2.空间复杂度
归并排序算法排序过程中需要额外的一个序列去存储排序后的结果，所占空间是n，因此空间复杂度为O(n)
3.稳定性
归并排序算法在排序过程中，相同元素的前后顺序并没有改变，所以归并排序是一种稳定排序算法
