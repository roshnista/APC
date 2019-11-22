//interview bit solution atoi

int Solution::atoi(const string A) {
    int i=0,sign=1;
    int res=0;
    long long int no=0; 
    if(A[i]=='-')
        {
            sign=-1;
            i++;
        }
    else if(A[i]=='+')
    {
        sign=1;
        i++;
    }
        
    for(;i<A.length();i++)
    {
        
        if(isdigit(A[i]))
           {
               res=res*10+(A[i]-'0');
               no=no*10+(A[i]-'0');
                
               if(res!=no)
               {
                   if(sign==-1)
                        return INT_MIN;
                    else
                        return INT_MAX;
               }
           }
           
        else 
             break;
    }
	return sign*res;
}


