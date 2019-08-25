#ifndef MATH_TASK_CDARRAY_HPP
#define MATH_TASK_CDARRAY_HPP

#include "string.h"

template< class T >
class CDArray
{
	T *m_pData;
	int m_Number;
	int m_Size;

public:
	CDArray() : m_Number(0), m_Size (1)
	{
		m_pData = (T*) malloc(sizeof(T) * m_Size);
	}

	CDArray(int size) : m_Number(0), m_Size(size)
	{
		m_pData = (T*) malloc(sizeof(T) * m_Size);
	}

	virtual ~CDArray()
	{
		free(m_pData);
	}

	int Add(const T &t)
	{
		if(m_Number == m_Size)
		{
			m_pData = (T*) realloc(m_pData, sizeof(T) * m_Size * 2);
			m_Size *= 2;
		}
		*(m_pData + m_Number) = t;
		return m_Number++;
	}

	int Delete(int number)
	{
		int elements_after = m_Number - number - 1;
		for (int i = 0; i < elements_after; i++)
		{
			*(m_pData * (number + i)) = *(m_pData * (number + i + 1));
		}
		m_Number--;
	}

	int Modify(int n, const T &t)
	{
		*(m_pData + n) = t;
		return 0;
	}

	int Resize(int size)
	{
		T *data = m_pData;
		if (size > m_Size)
		{
			data = (T*) realloc(m_pData, sizeof(T) * size);
			if (!data)
			{
				return 0;
			}
		}
		else if (size < m_Size)
		{
			T *data = (T*) malloc(sizeof(T) * size);
			if (!data)
			{
				return 0;
			}

			memcpy(data, m_pData, sizeof(T) * size);
		}

		m_pData = data;
		m_Size = size;
		return 1;
	}

	void Clear()
	{
		m_Number = 0;
	}

	T &operator[](int i) const
	{
		return *(m_pData + i);
	}

	int Number()
	{
		return m_Number;
	}
	int Size()

	{
		return m_Size;
	}

	T *Ptr()
	{
		return m_pData;
	};

};

#endif //MATH_TASK_CDARRAY_HPP
