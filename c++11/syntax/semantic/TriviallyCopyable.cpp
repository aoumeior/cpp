#include <type_traits>
#include <assert.h>
class TriviallyCopyable
{
  public:
    // at least one copy constructor, move constructor,
    // copy assignment operator, or move assignment operator is non-deleted
    TriviallyCopyable(const TriviallyCopyable &) = default;
    TriviallyCopyable(TriviallyCopyable &&) = default;
    TriviallyCopyable &operator=(const TriviallyCopyable &) = default;
    TriviallyCopyable &operator=(TriviallyCopyable &&) = default;

    ~TriviallyCopyable() = default; // Trivial non-deleted destructor
};

int main()
{
    //
    assert(std::is_trivially_copyable<volatile TriviallyCopyable>::value == true);
    assert(std::is_trivially_copyable<const TriviallyCopyable>::value == true);
    assert(std::is_trivially_copyable<TriviallyCopyable>::value == true);
    return 0;
}