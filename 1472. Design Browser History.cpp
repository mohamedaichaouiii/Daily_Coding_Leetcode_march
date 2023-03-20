class BrowserHistory {
  
public:
stack<string> s1;
stack<string> s2;

BrowserHistory(string homepage) {
  while(!s1.empty()) s1.pop();
  while(!s2.empty()) s2.pop();
  s1.push(homepage);
    }
    
    void visit(string url) {
        s1.push(url);
        while(!s2.empty()) s2.pop();
        
    }
    
    string back(int steps) {
        while(steps-- && s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        return s1.top();

          

        
    }
    
    string forward(int steps) {
        while(!s2.empty() && steps--){
            s1.push(s2.top());
            s2.pop();
        }
        return s1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */