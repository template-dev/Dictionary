#include "Dictionary.hpp"

template<class Key, class Value>
const Value& Dictionary<Key, Value>::get(const Key& key) const
{
  auto it = m_map.find(key);
  if (it != m_map.end())
    return it->second;
  throw Not_found_exception<Key>(key);
}

template<class Key, class Value>
void Dictionary<Key, Value>::set(const Key& key, const Value& value)
{
  auto it = m_map.find(key);
  if(it != m_map.end())
    it->second = value;
  else
    m_map.insert(std::make_pair(key, value));
}

template<class Key, class Value>
bool Dictionary<Key, Value>::is_set(const Key& key) const
{
  auto it = m_map.find(key);
  if(it != m_map.end())
    return true;
  return false;
}

template<class Key, class Value>
Dictionary<Key, Value>& Dictionary<Key, Value>::operator=(const Dictionary& other)
{
  if(this != &other)
    m_map = other.m_map;
  return *this;
}

template<class Key, class Value>
Dictionary<Key, Value>& Dictionary<Key, Value>::operator=(Dictionary&& other)
{
  if(this != &other)
  {
    m_map = other.m_map;
    other.m_map.clear();
  }
  return *this;
}

template<class Key, class Value>
std::ostream& operator<<(std::ostream& os, const Dictionary<Key, Value>& dict)
{
  for(const auto& item : dict.m_map)
    os << "Key: " << item->first << ", value: " << item->second << std::endl;
  return os;
}

template<class Key, class Value>
Value& Dictionary<Key, Value>::operator[](const Key& key)
{
  auto it = m_map.find(key);
  if (it != m_map.end())
    return it->second;
  return m_map[key];
}

template<class Key, class Value>
Dictionary<Key, Value>& Dictionary<Key, Value>::operator++(int)
{
  typename std::map<Key, Value>::iterator tmp = m_map.begin();
  m_map.begin()++;
  return tmp;
}

template<class Key, class Value>
Dictionary<Key, Value>& Dictionary<Key, Value>::operator--(int)
{
  typename std::map<Key, Value>::iterator tmp = m_map.begin();
  m_map.begin()--;
  return tmp;
}