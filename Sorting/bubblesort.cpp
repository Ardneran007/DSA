/*
BUBBLE SORT
Comparision based sort + INPLACE 
O(N2)
STABLE SORTING ALGO
It makes multiple passes
1st pass-> lArgest element to last position
LArgest element is bubbled to last position
2nd pass->2nd largest elemet to second last position which is its final position
once last n-1 elements are sorted then sorting is done
ie only n-1 ties to be done

TIME-> n-1  +  n-2  +  ....2 + 1 

we can optiised it by maintaing a swapped flag which checks that swapping is happened or not
if swapping is not happened that means array has now bcon=me sorted so then we break
this swapped variable enhances the performance specially in cases when array is sorted
or it is about to bcome sorted or it become sorted in middle
it does not take n2 time in all cases

void Bubblesort(arr,n)
{
    for(int i=0;i<n-1;i++)
    {
        swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j] > A[j+1])
            {
                swap(A[j],A[j+1])
                swapped=true;
            }
        }
        if(swapped==false)
            break;
    }
}












*/