#include <iostream>
#include <cstdlib>
class ArrayList {
private:
	int len;
	int* data;
	void init(int len)
	{
		//(*this).len = len;
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
		if (this->data != nullptr) {
			for (int i = 0; i < len; ++i) {
				this->data[i] = 0;
			}
		}
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
	void expand() {
		int newlen = len + 1;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata != nullptr) {
			for (int i = 0; i < len; ++i) {
				newdata[i] = this->data[i];
			}
		}
		if (this->data != nullptr) {
			free(this->data);
			this->data = newdata;
		}
		len = newlen;

	}
	void shrink() {

		int newlen = len - 1;
		int* newdata = (int*)malloc(sizeof(int) * newlen);
		if (newdata != nullptr) {
			for (int i = 0; i < len - 1; ++i) {
				newdata[i] = this->data[i];
			}
		}
		if (this->data != nullptr) {
			free(this->data);
			this->data = newdata;
		}
		len = newlen;

	}
	void swap(int a, int b) {
		int c = get(b);
		set(b, get(a));
		set(a, c);

	}

public:
	ArrayList(int len = 10)
	{
		this->init(len);

	}
	// i think this is just creating a massive
	ArrayList(ArrayList& list)
	{
		//this->len = list.len;
		//this->data = list.data;
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{

		free(this->data);
		this->data = nullptr;
	}
	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", get(i));
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}

	void pushBack(int element)
	{
		void expand();
		for (int i = 0; i < len; ++i)
		{
			set(i, get(i));
		}
		this->data[len - 1] = element;
		// важно//
	}

	void pushFront(int element) {
		void expand();
		for (int i = 0; i < len; ++i)
		{
			set(i, get(i));
		}
		this->data[0] = element;

	}
	void insert(int index, int element) {
		expand();
		for (int i = len - 1; i > index; --i) {
			set(i, get(i - 1));
		}
		set(index, element);
	}
	int popBack() {
		int a = get(len - 1);
		shrink();
		return a;
	}
	int popFront() {
		int a = get(0);
		shift(-1);
		shrink();
		return a;
	}
	int extract(int index) {
		int a = get(index);
		for (int i = len - 1; i > index; --i) {
			set(i, get(i + 1));
		}
		return a;
	}
	void reverse(int start, int end) {
		if (!indexValid(start) || !indexValid(end))
			return;
		while (start <= end) {
			swap(start, end);
			start++;
			end--;
		}

	}
	int sum() {
		int count = 0;
		for (int i = 0; i < len; ++i) {
			count += get(i);
		}
		return count;
	}

	int secondMax() {
		int max1 = get(0);
		int max2 = get(0);
		for (int i = 0; i < len; ++i) {
			if (get(i) > max1)
				max1 = get(i);
		}
		for (int i = 0; i < len; ++i) {
			if (get(i) > max2 && get(i) < max1)
				max2 = get(i);
		}
		return max2;
	}

	int lastMinIndex() {
		int min = get(0);
		int k = 0;
		for (int i = 0; i < len; ++i) {
			if (get(i) <= min) {
				min = get(i);
				k = i;
			}
		}
		return k;

	}
	void shift(int k) {
		reverse(0, len - k - 1);
		reverse(len - k, len - 1);
		reverse(0, len - 1);
	}
	int countOdd() {
		int count = 0;
		for (int i = 0; i < len; ++i) {
			if (get(i) % 2 != 0)
				count++;
		}
		return count;
	}

	int sumEven() {
		int count = 0;
		for (int i = 0; i < len; ++i) {
			if (get(i) % 2 == 0)
				count += get(i);
		}
		return count;
	}
};
int main() {
	ArrayList list;
	list.randomize();
	list.print();
	int t = list.lastMinIndex();
	std::cout << t;
	printf("\n");
	list.shift(5);
	list.print();
	std::cout << list.secondMax();
	printf("\n");
	list.pushBack(5);
	list.popBack();
	list.print();
	return 0;
}
