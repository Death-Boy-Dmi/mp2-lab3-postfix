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
  bool IsEmpty()
  {
	  return top == (-1);
  }
  bool IsFull()
  {
	  return top == (size - 1);
  }
  void Put(T val)
  {
	  if (IsFull())
		  throw val;
	  pMem[++top] = val;
  }
  T Get()
  {
	  if (IsEmpty())
		  throw 0;
	  return pMem[top--];
  }
  int GetTop()
  {
	  return top;
  }
  int GetSize()
  {
	  return size;
  }
};

#endif