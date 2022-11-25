class MinStack {
private:
  int arr_top;
  int* arr;
  int* mins;

public:
  MinStack() {
    arr_top = -1;
    arr = new int[30005];
    mins = new int[30005];
  }
    
  void push(int val) {
    arr_top++;
    arr[arr_top] = val;
    
    if (arr_top == 0) { // first increment
      mins[arr_top] = val; 
    } else { // already has value
      mins[arr_top] = min(val, mins[arr_top - 1]);
    }
  }
  
  void pop() {
    arr_top--;
  }
  
  int top() {
    return arr[arr_top];
  }
  
  int getMin() {
    return mins[arr_top];
  }
};
