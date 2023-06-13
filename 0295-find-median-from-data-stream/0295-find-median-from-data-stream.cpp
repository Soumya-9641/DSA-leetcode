class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
     double median =0;
    MedianFinder() {
        
    }
    int signam(int a ,int b){
	if(a==b){
		return 0;
	}
	else if(a>b){
		return 1;
	}
	else{
		return -1;
	}
}
    
    void solve(int num,priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini, double &median){
        	switch(signam(maxi.size(),mini.size())){
				case 0: if(num>median){
					mini.push(num);
					median= mini.top();
				}
				else{
					maxi.push(num);
					median= maxi.top();
				}
				break;

				case 1: if(num>median){
					mini.push(num);
					median = (mini.top()+maxi.top())/2.0;
				}
				else{
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(num);
					median = (mini.top()+maxi.top())/2.0;
				}
				break;
				case -1: if(num>median){
					maxi.push(mini.top());
					mini.pop();
					mini.push(num);
					median = (mini.top()+maxi.top())/2.0;
				}
				else{
					maxi.push(num);
					median = (mini.top()+maxi.top())/2.0;
				}
				break;

		}
    }
    
    void addNum(int num) {
       
        solve(num, maxheap,minheap, median);
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */