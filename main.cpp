#include <cstddef>

template< class T >
T* unique(T* a, size_t s)
{
    if (s == 0) return nullptr;

    T* result = new T[s];
    size_t count = 0;

    for (size_t i = 0; i < s; ++i) {
        bool found = false;
        for (size_t j = 0; j < count; ++j) {
            if (result[j] == a[i]) {
                found = true;
                break;
            }
        }
        if (!found)
            result[count++] = a[i];
    }

    for (size_t i = 0; i < count; ++i)
        a[i] = result[i];

    delete[] result;
    return a + count;
}
