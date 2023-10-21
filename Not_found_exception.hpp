#ifndef NOT_FOUND_EXCEPTION_HPP
#define NOT_FOUND_EXCEPTION_HPP

#include "INot_found_exception.hpp"

template<class Key>
class Not_found_exception : public INot_found_exception<Key>
{
public:
  Not_found_exception(const Key& key) : m_key(key) {}
  const Key& get_key() const noexcept override { return m_key; }
  const char* what() const noexcept override { return "Key not found!"; }

private:
  Key m_key;
};

#endif //NOT_FOUND_EXCEPTION_HPP
