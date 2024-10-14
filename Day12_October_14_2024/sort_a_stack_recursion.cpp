

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert_in_sorted_stack(stack<int>&s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }
    
    if(s.top() <= ele)
    {
        s.push(ele);
        return;
    }
    else
    {
        int curr = s.top();
        s.pop();
        
        insert_in_sorted_stack(s,ele);
        s.push(curr);
        
    }
    return;
}


void solve(stack<int>&s)
{
   if(s.empty())
   {
       return;
   }
   
   int curr = s.top();
   s.pop();
   
   solve(s);
   insert_in_sorted_stack(s,curr);
   return;
   
}

void SortedStack :: sort() // stack<int> s
{
    solve(s);
}