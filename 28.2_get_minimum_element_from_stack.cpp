class Solution{
    private:
      int arr_top = -1;
      int arr[30005];
      int mins[30005];
    public:
       /*returns min element from stack*/
       int getMin(){
           if (arr_top == -1) {
               return -1;
           }
           return mins[arr_top];
       }
       
       /*returns poped element from stack*/
       int pop(){
           if (arr_top == -1) {
               return -1;
           } else {
               int top = arr[arr_top];
               arr_top--;
               return top;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
            arr_top++;
            arr[arr_top] = x;
            
            if (arr_top == 0) { // first increment
              mins[arr_top] = x; 
            } else { // already has value
              mins[arr_top] = min(x, mins[arr_top - 1]);
            }
       }
};
