#pragma once
#include "Item.h"

class CMyStringList
{
public:
	CMyStringList()
		:m_first(), m_last()
	{}

	~CMyStringList()
	{}

	std::string GetValue(const std::shared_ptr<CItem> &item) const
	{
		return item->GetValue();
	}

	std::shared_ptr<CItem> GetFirst() const
	{
		return m_first;
	}

	std::shared_ptr<CItem> GetLast() const
	{
		return m_last;
	}

	std::shared_ptr<CItem> GetNext(const std::shared_ptr<CItem> &item) const
	{
		return item->GetNext();
	}

	std::shared_ptr<CItem> GetPrevious(const std::shared_ptr<CItem> &item) const
	{
		return item->GetPrevious();
	}

	void Insert(const std::string str, const std::shared_ptr<CItem> &item = std::shared_ptr<CItem>())
	{
		auto newItem = std::make_shared<CItem>(move(str));
		if (!m_first)
		{
			m_first = newItem;
			m_last = newItem;
			return;
		}

		if (item)
		{
			newItem->SetPrevious(item);
			auto next = item->GetNext();
			newItem->SetNext(next);
			
			if (next)
			{
				next->SetPrevious(newItem);
			}

			item->SetNext(newItem);
			if (m_last == item)
			{
				m_last = newItem;
			}
		}
		else
		{
			newItem->SetPrevious(m_last);
			newItem->SetNext(std::shared_ptr<CItem>());
			m_last->SetNext(newItem);
			m_last = newItem;
		}
	}

	void Delete(const std::shared_ptr<CItem> &item)
	{
		auto it = item->GetNext();
		if (it)
		{
			item->GetNext()->SetPrevious(item->GetPrevious());
		}
		else
		{
			m_last = item->GetPrevious();
		}
		it = item->GetPrevious();
		
		if (it)
		{
			item->GetPrevious()->SetNext(item->GetNext());
		}
		else
		{
			m_first = item->GetNext();
		}
	}

private:
	std::shared_ptr<CItem> m_first;
	std::shared_ptr<CItem> m_last;
};

