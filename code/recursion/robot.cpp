class Solution {
public:
    int sum=0;
    int s(int x,int y){
        string a=to_string(x);
        string b=to_string(y);
        int count=0;
        for(int i=0;i<a.size();i++){
            count+=(a[i]-'0');
        }
        for(int i=0;i<b.size();i++){
            count+=(b[i]-'0');
        }
        return count;        
    }
    void process(int y,int x,int rows,int cols,int threshold,bool *store){
        if(y<0 || x<0 || y>=rows || x>=cols) return;
        if(s(x,y)>threshold) return;
        if(store[y*cols+x]==true) return;
        sum++;
        store[y*cols+x]=true;
        process(y+1,x,rows,cols,threshold,store);
        process(y-1,x,rows,cols,threshold,store);
        process(y,x+1,rows,cols,threshold,store);
        process(y,x-1,rows,cols,threshold,store);
    }
    int movingCount(int threshold, int rows, int cols)
    {
        bool *store=new bool[rows*cols];
        for(int i=0;i<rows*cols;i++){
            store[i]=false;
        }
        process(0,0,rows,cols,threshold,store);
        return sum;        
    }
};