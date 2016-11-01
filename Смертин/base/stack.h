#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  int IsEmpty()
  {
	  return top = -1;
  }
  int IsFull()
  {
	  return top = MaxStackSize - 1;
  }
  void Put(int val)
  {
	  if (IsFull())
		  throw 1;
	  pMem[++top] = val;
  }
  int Get()
  {
	  if (IsEmpty())
		  throw 0;
	  return pMem[top--];
  }
};

#endif
