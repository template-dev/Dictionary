#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <map>
#include "IDictionary.hpp"
#include "Not_found_exception.hpp"

template<class Key, class Value>
class Dictionary : public IDictionary<Key, Value>
{
public:
  Dictionary() : m_map() {}
  Dictionary(const Key& key, const Value& value) : m_map() { m_map[key] = value; }
  Dictionary(const Dictionary& other) : m_map(other.m_map){}
  Dictionary(Dictionary&& other) : m_map(std::move(other.m_map)){}
  ~Dictionary() { m_map.clear(); }

  const Value& get(const Key& key) const override;
  void set(const Key& key, const Value& value) override;
  bool is_set(const Key& key) const override;

  Dictionary& operator=(const Dictionary& other);
  Dictionary& operator=(Dictionary&& other);
  Dictionary& operator++() { return ++m_map.begin(); }
  Dictionary& operator--() { return --m_map.begin(); }
  Dictionary& operator++(int);
  Dictionary& operator--(int);
  Value& operator[](const Key& key);
  friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict);

  typename std::map<Key, Value>::iterator begin() { return m_map.begin(); }
  typename std::map<Key, Value>::iterator end() { return m_map.end(); }
  typename std::map<Key, Value>::const_iterator cbegin() { return m_map.cbegin(); }
  typename std::map<Key, Value>::const_iterator cend() { return m_map.cend(); }
  typename std::map<Key, Value>::reverse_iterator rbegin() { return m_map.rbegin(); }
  typename std::map<Key, Value>::reverse_iterator rend() { return m_map.rend(); }
  typename std::map<Key, Value>::const_reverse_iterator crbegin() { return m_map.crbegin(); }
  typename std::map<Key, Value>::const_reverse_iterator crend() { return m_map.crend(); }

private:
  std::map<Key, Value> m_map;
};

#include "Dictionary.inl"

#endif //DICTIONARY_HPP
