#ifndef MATH_TASK_CDARRAY_HPP
#define MATH_TASK_CDARRAY_HPP

#include "string.h"

template< class T >
class CDArray
{
	T *m_pData{nullptr};
	int m_Number{0};
	int m_Size{0};

public:
	CDArray() : CDArray(1)
	{ }

	CDArray(int size) : m_Size(size)
	{
		m_pData = (T*) malloc(sizeof(T) * m_Size);
		if (!m_pData)
		{
			perror("CDArray(int)");
			exit(EXIT_FAILURE);
		}
	}

	/*!
	 * @brief Call destructors and then free resources
	 */
	virtual ~CDArray()
	{
		for (int i = 0; i < m_Number; i++)
		{
			(m_pData + i)->~T();
		}
		free(m_pData);
	}

	/*!
	 * @brief Add element into array
	 * @param t
	 * @return 1 on success, otherwise 0
	 */
	int Add(const T &t)
	{
		if(m_Number == m_Size)
		{
			auto data = (T*) realloc(m_pData, sizeof(T) * m_Size * 2);
			if (!data)
			{
				return 0;
			}

			m_pData = data;
			m_Size *= 2;
		}
		*(m_pData + m_Number++) = t;
		return 1;
	}

	/*!
	 * @brief Delete element with /number/ index
	 * @param number
	 * @return true
	 */
	int Delete(int number)
	{
		/* call destructor */
		(m_pData + number)->~T();

		/* move elements */
		int elements_after = m_Number - number - 1;
		for (int i = 0; i < elements_after; i++)
		{
			*(m_pData * (number + i)) = *(m_pData * (number + i + 1));
		}
		m_Number--;
		return 1;
	}

	/*!
	 * Modify element
	 * @param n
	 * @param t
	 * @return true
	 */
	int Modify(int n, const T &t)
	{
		*(m_pData + n) = t;
		return 1;
	}

	/*!
	 * Resize array
	 * @param size
	 * @return 1 on success, otherwise 0
	 */
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

	/*!
	 * Clear array
	 */
	void Clear()
	{
		for (int i = 0; i < m_Number; i++)
		{
			(m_pData + i)->~T();
		}

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
