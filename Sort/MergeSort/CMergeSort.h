#include <iostream>
#include <vector>

class MergeSort {
private:
    const int m_Max;
    void Sort( std::vector<int> &array, int front, int end );
    void Merge( std::vector<int> &Array, int front, int mid, int end );

public:
    std::vector<int> m_Array;
    MergeSort(std::vector<int> &Array)
        : m_Max(INT_MAX)
    {
        m_Array = Array;
        Sort(m_Array, 0, m_Array.size()-1 );
    };
    ~MergeSort() {};
    void Show(std::vector<int> &array);
};

inline void MergeSort::Merge( std::vector<int> &array, int front, int mid, int end ) {
    // Divide
    std::vector<int> LeftSub( array.begin()+front, array.begin()+mid+1 ),
                     RightSub( array.begin()+mid+1, array.begin()+end+1 );

    // ** 是子陣列的尾巴，非輸入陣列尾巴
    LeftSub.insert( LeftSub.end(), m_Max);
    RightSub.insert( RightSub.end(), m_Max);

    int left_index = 0, right_index = 0;

    // Conquer
    for (int i = front; i <= end; i++)
    {
        if ( LeftSub[ left_index ] <= RightSub[ right_index ] )
            array[i] = LeftSub[ left_index++ ];
        else
            array[i] = RightSub[ right_index++ ];
    }
}

inline void MergeSort::Sort( std::vector<int> &array, int front, int end )
{
    if (front < end)
    {
        int mid = ( front + end )/2;
        Sort(array, front, mid);
        Sort(array, mid+1, end);
        Merge(array, front, mid, end);
    }
}

inline void MergeSort::Show(std::vector<int> &array)
{
    std::cout << "\n[ ";
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i];
        if (i != array.size()-1)
            std::cout << ", ";
    }
    std::cout << " ]\n";
}