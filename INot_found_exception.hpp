#ifndef INOT_FOUND_EXCEPTION_HPP
#define INOT_FOUND_EXCEPTION_HPP

template<class Key>
class INot_found_exception : public std::exception
{
public:
  virtual const Key& get_key() const noexcept = 0;
  virtual const char * what() const noexcept = 0;
};

#endif //INOT_FOUND_EXCEPTION_HPP
