class Deque_Node
{
  int start, end;
  int *arr, size;
  Deque_Node *next;
public:
  Deque_Node();
  Deque_Node(int);
  void
  set_next_node(Deque_Node*);
  int
  pop_front();
  void
  push_back(int);
  ~Deque_Node();
};

class Deque_List
{
  Deque_Node *front, *rear;
public:
  Deque_List();
  void
  add_node();
  int
  pop_first();
  void
  push_last(int);
  ~Deque_List();
};

class Deque
{
  Deque_List list_of_nodes;
public:
  Deque();
  Deque(int,int);
  Deque(const Deque&);
  ~Deque();
  int&
  at(int);
  void
  push_back(int);
  int
  pop_front();
  int&
  operator[](int);
  Deque
  operator=(Deque&);
};
