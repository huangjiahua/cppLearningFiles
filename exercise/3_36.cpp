#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nums1[] = {2, 33};
    int nums2[] = {2, 33};

    int *p1 = nums1, *p2 = nums2;
    for( ; p1 != end(nums1) && p2 != end(nums2); p1++, p2++) {
        if (*p1 > *p2) {
            cout << "nums1 > nums2" << endl;
            return 0;
        }
        else if (*p1 < *p2) {
            cout << "nums1 < nums2" << endl;
            return 0;
        }
    }
    if (p1 == end(nums1) && p2 == end(nums2))
        cout << "nums1 == nums2" << endl;
    else if(p1 != end(nums1))
        cout << "nums1 > nums2" << endl;
    else if (p2 != end(nums2))
        cout << "nums1 < nums2" << endl;

    return 0;
}
