class dynamic_queue{
	private:
        struct list_node{
      	    int start_index;
	        int end_index;
  	        int max_size;
  	        int *arr; 
	        list_node *next_list_node;
        };
		struct list_node front,rear;
	public:
        dynamic_queue();
		void push_back(int);
		int pop_front();
        ~dynamic_queue();
}
