#pragma once
#include <string>
#include <memory>

class CItem
{
public:
	CItem(std::string value)
		:m_value(move(value)),
		m_previous(),
		m_next()
	{}

	~CItem()
	{}

	std::string GetValue() const
	{
		return m_value;
	}

	void SetValue(std::string value)
	{
		m_value = move(value);
	}

	void SetNext(const std::shared_ptr<CItem> &next)
	{
		m_next = next;
	}

	void SetPrevious(const std::shared_ptr<CItem> &previous)
	{
		m_previous = previous;
	}

	std::shared_ptr<CItem> GetNext() const
	{
		return m_next;
	}

	std::shared_ptr<CItem> GetPrevious() const
	{
		return m_previous;
	}

private:
	std::string m_value;
	std::shared_ptr<CItem> m_next;
	std::shared_ptr<CItem> m_previous;
};

