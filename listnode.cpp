template <typename T>

struct ListNode
{
	T value;
	ListNode<T>* next;
	ListNode(const T& val = 0, ListNode<T>* n = nullptr)
		: value(val)
		, next(n)
	{}
	~ListNode() {}
};
