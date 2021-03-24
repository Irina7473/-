
template <typename T> Tree<T>::Tree(const initializer_list<T> & tree): Tree()
{
	for (T const* it = tree.begin(); it != tree.end(); it++)
		insert (*it);
	cout << "LIConstructor Tree  " << this << endl;
}

template <typename T> Tree<T>::Tree(Tree&& other) : Tree()
{
	Root = other.Root;
	copy(other.Root);
	other.Root = nullptr;
	cout << "AssConstrucktor Tree  " << this << endl;
}

template <typename T> void Tree<T>::erase(T data)
{
	if (this->Root == nullptr) return;
	Element<T>* temper = Root; //удаляемый элемент
	Element<T>* temppar = nullptr; // родитель удаляемого элемента
	while (temper && temper->Data != data)
	{
		temppar = temper;
		(data < temper->Data) ? temper = temper->pLeft : temper = temper->pRight;
	}
	if (!temper) return; //не нашли элемент
	if (temper->is_leaf())  // у элемента нет потомков
	{
		if (!temppar) Root = nullptr;
		else (temppar->pLeft == temper) ? temppar->pLeft = nullptr : temppar->pRight = nullptr;
	}
	else if (!temper->pLeft) // у элемента только правый потомок
	{
		if (!temppar) Root = temper->pRight;
		else (temppar->pLeft == temper) ? temppar->pLeft = temper->pRight : temppar->pRight = temper->pRight;
	}
	else if (!temper->pRight) // у элемента только левый потомок
	{
		if (!temppar) Root = temper->pLeft;
		else (temppar->pLeft == temper) ? temppar->pLeft = temper->pLeft : temppar->pRight = temper->pLeft;
	}
	else if (temper->pLeft && temper->pRight) // у элемента есть оба потомка
	{
		{
			if (!temppar) Root = temper->pRight;
			else (temppar->pLeft == temper) ? temppar->pLeft = temper->pRight : temppar->pRight = temper->pRight;
			min(temper->pRight)->pLeft = temper->pLeft;
		}
	}
	delete temper;
}

template <typename T> void Tree<T>::copy(Element<T>* Root)
{
	if (Root == nullptr) return;  //выход из пустой ветки
	insert(Root->Data, this->Root);
	copy(Root->pLeft);
	copy(Root->pRight);
}

template <typename T> void Tree<T>::insert(T Data, Element<T>* Root)
{
	if (this->Root == nullptr) this->Root = new Element<T>(Data);
	if (Root == nullptr) return;
	if (Data < Root->Data)
	{
		if (Root->pLeft == nullptr)
			Root->pLeft = new Element<T>(Data);
		else
			insert(Data, Root->pLeft);
	}
	else if (Data> Root->Data)
	{
		if (Root->pRight) insert(Data, Root->pRight);
		else Root->pRight = new Element<T>(Data);
	}
}

template <typename T> void Tree<T>::clear(Element<T>* Root)
{
	if (Root == nullptr) return;
	clear(Root->pLeft);
	clear(Root->pRight);
	delete Root;
}

template <typename T> Element<T>* Tree<T>::search(T data, Element<T>* Root)
{
	if (Root == nullptr) return 0;
	if (Root->Data == data) return Root;
	else (data < Root->Data) ? search(data, Root->pLeft) : search(data, Root->pRight);
}

template <typename T> T Tree<T>::count(Element<T>* Root)
{
	if (Root == nullptr) return 0;
	return (Root->is_leaf()) ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;
}

template <typename T> T Tree<T>::sum(Element<T>* Root)
{
	if (Root == nullptr) return 0;
	return (Root->is_leaf()) ? Root->Data : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
}

template <typename T> void Tree<T>::print(Element<T>* Root)
{
	if (Root == nullptr) return;
	print(Root->pLeft);
	cout <<Root<<tab<< Root->Data << endl;
	print(Root->pRight);
}
