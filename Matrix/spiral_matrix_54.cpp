class Solution {
public:
    void spiral(vector<int> &v,int si,int sj,int ei,int ej,vector<vector<int>> mat)
    {
        int f=0;
        if(si>ei || sj>ej)
            return;
        if(si==ei)
        {
            for(int p=sj;p<=ej;p++)
                v.push_back(mat[si][p]);
            f=1;
        }
        else if(sj==ej)
        {
            for(int p=si;p<=ei;p++)
                v.push_back(mat[p][sj]);
            f=1;
        }
        if(f==0)
        {
            for(int p=sj;p<=ej;p++)
                v.push_back(mat[si][p]);
            for(int p=si+1;p<=ei;p++)
                v.push_back(mat[p][ej]);
            for(int p=ej-1;p>=sj;p--)
                v.push_back(mat[ei][p]);
            for(int p=ei-1;p>=si+1;p--)
                v.push_back(mat[p][sj]);
        }
        spiral(v,si+1,sj+1,ei-1,ej-1,mat);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> v;
        spiral(v,0,0,n-1,m-1,matrix);
        
        return v;
        
    }
};