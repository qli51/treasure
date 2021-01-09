class Solution {
public:
    bool isPath(char* matrix, int rows, int cols, char* str,bool *store,int y,int x)
    {
        if(*str=='\0') return true;
        if(matrix[y*cols+x]!=*str) return false;
        if(y>=rows || y<0 || x<0 || x>=cols) return false;
        if(store[y*cols+x]==true) return false;
        store[y*cols+x]=true;
        bool res=isPath(matrix,rows,cols,str+1,store,y,x-1) || isPath(matrix,rows,cols,str+1,store,y,x+1) ||
            isPath(matrix,rows,cols,str+1,store,y+1,x) || isPath(matrix,rows,cols,str+1,store,y-1,x);
        store[y*cols+x]=false;
        return res;            
    }
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(rows<=0 || cols<=0 || str==NULL) return false;
        bool *store=new bool[rows*cols];
        for(int i=0;i<rows*cols;i++){
            store[i]=false;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(isPath(matrix,rows,cols,str,store,i,j)==true) return true;
            }
        }
        return false;
    }


};