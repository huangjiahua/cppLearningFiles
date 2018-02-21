#include <iterator>
namespace ITER {


    template <typename RaIterator>
    typename std::iterator_traits<RaIterator>::difference_type
    distance(RaIterator pos1, RaIterator pos2,
             std::random_access_iterator_tag)
    {
        return pos2 - pos1;
    }

    template <typename InIterator>
    typename std::iterator_traits<InIterator>::difference_type
    distance(InIterator pos1, InIterator pos2,
             std::input_iterator_tag)
    {
        typename std::iterator_traits<InIterator>::difference_type d;
        for (d = 0; pos1 != pos2; ++pos1, ++d)
            ;
        return d;
    }

    template <typename Iterator>
    typename std::iterator_traits<Iterator>::difference_type
    distance(Iterator pos1, Iterator pos2)
    {
        return distance(pos1, pos2,
                        typename std::iterator_traits<Iterator>
                           ::iterator_category());
    }
}
