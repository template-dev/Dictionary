#ifndef IDICTIONARY_HPP
#define IDICTIONARY_HPP

template<class Key, class Value>
class IDictionary
{
public:
  virtual ~IDictionary() = default;

  virtual const Value& get(const Key& key) const = 0;
  virtual void set(const Key& key, const Value& value) = 0;
  virtual bool is_set(const Key& key) const = 0;
};

#endif //IDICTIONARY_HPP
